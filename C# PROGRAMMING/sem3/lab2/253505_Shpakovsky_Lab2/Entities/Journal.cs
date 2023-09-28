using collections;

namespace _253505_Shpakovsky_Lab1.Entities;

public class Journal
{
    private MyCustomCollection<string> logs;

    public Journal()
    {
        logs = new MyCustomCollection<string>();
    }

    public void Log(string message)
    {
        logs.Add(message);
    }

    public string GetLogs()
    {
        string result = "";
        foreach (var str in logs)
        {
            result += str + '\n';
        }

        return result;
    }

    private void OnTariffChange(object sender, EventArgs a)
    {
        Console.WriteLine("Tariff list was changed.");
    }
    private void OnClientChange(object sender, EventArgs a)
    {
        Console.WriteLine("Client list was changed.");
    }
}