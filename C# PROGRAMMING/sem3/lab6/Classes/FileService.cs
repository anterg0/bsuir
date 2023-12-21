using System.Text.Json;
using _253505_Shpakovsky_Lab6;

namespace Classes;

public class FileService<T> : IFileService<T> where T : Employee
{
    public IEnumerable<T> ReadFile(string fileName)
    {
        string json = File.ReadAllText(fileName);
        return JsonSerializer.Deserialize<IEnumerable<T>>(json);
    }

    public void SaveData(IEnumerable<T> data, string fileName)
    {
        string json = JsonSerializer.Serialize(data);
        File.WriteAllText(fileName, json);
    }
}