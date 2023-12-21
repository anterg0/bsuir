using System.Text.Json;

namespace ClassLibrary1;

public class StreamService<T> where T : class
{
    public event Action<int, string> TaskProgressEvent;
    private Semaphore sema = new Semaphore(1, 1);

    public async Task WriteToStreamAsync(Stream stream, IEnumerable<T> data, IProgress<string> progress)
    {
        sema.WaitOne();
        progress?.Report($"Starting writing to stream {Thread.CurrentThread.ManagedThreadId}");
        TaskProgressEvent?.Invoke(Thread.CurrentThread.ManagedThreadId, "Writing");
        // double totalCount = data.Count();
        // double processedCount = 0;
        await Task.Delay(2000);
        lock (stream)
        {
            JsonSerializer.SerializeAsync(stream, data);
        }

        progress?.Report($"Finished writing. Thread: {Thread.CurrentThread.ManagedThreadId}");
        TaskProgressEvent?.Invoke(Thread.CurrentThread.ManagedThreadId, "Finished writing");
        sema.Release();
    }

    public async Task CopyFromStreamAsync(Stream stream, string fileName, IProgress<string> progress)
    {
        sema.WaitOne();
        progress?.Report($"Starting copying to file from stream. Thread: {Thread.CurrentThread.ManagedThreadId}");
        TaskProgressEvent?.Invoke(Thread.CurrentThread.ManagedThreadId, "Copying");
        await using (var file = File.Open(fileName, FileMode.Create, FileAccess.ReadWrite))
        {
            stream.Position = 0;
            lock (stream)
            {
                stream.CopyToAsync(file);
            }
        }
        progress?.Report($"Finished copying to file. Thread: {Thread.CurrentThread.ManagedThreadId}");
        TaskProgressEvent?.Invoke(Thread.CurrentThread.ManagedThreadId,"Finished copying");
        sema.Release();
    }

    public async Task<int> GetStatisticsAsync(string fileName, Func<T, bool> filter)
    {
        List<T> list;
        using (var file = File.Open(fileName, FileMode.Open))
        {
            list = await JsonSerializer.DeserializeAsync<List<T>>(file);
        }
        return list.Where(filter).Count();
    }
}