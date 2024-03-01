using ClassLibrary1;
public class Label1
{
    public string Text { get; set; }
}
class Program
{
    public static async Task Main(string[] args)
    {
        List<Passenger> passengers = new List<Passenger>();

        var rnd = new Random();
        for (int i = 0; i < 1000; i++)
        {
            Passenger pas = new Passenger();
            pas.Id = i;
            pas.Name = $"Passenger {i}";
            pas.NumberOfBags = rnd.Next(3);
            passengers.Add(pas);
        }

        StreamService<Passenger> streamService = new StreamService<Passenger>();

        MemoryStream memoryStream = new MemoryStream();
        streamService.TaskProgressEvent += (threadId, action) =>
        {
            Console.WriteLine($"[Event Invokation] Thread {threadId}: {action}");
        };
        IProgress<string> progress = new Progress<string>(report =>
            Console.WriteLine($"[Progress Report] Thread {Thread.CurrentThread.ManagedThreadId}: {report}"));

        var task1 = streamService.WriteToStreamAsync(memoryStream, passengers, progress);
        //await Task.WhenAny(task1);
        var task2 = streamService.CopyFromStreamAsync(memoryStream, "file.txt",progress);
        await Task.WhenAll(task1, task2);
        
        int stats = await streamService.GetStatisticsAsync("file.txt", (Passenger pas) => pas.NumberOfBags >= 1);
        
        Console.WriteLine($"Thread {Thread.CurrentThread.ManagedThreadId}: got statistics (passengers with at least 1 bag): {stats}");
    }
}
