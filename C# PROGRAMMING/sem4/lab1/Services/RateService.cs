using System.Text.Json;
using lab1.Entities;

namespace lab1.Services;

public class RateService : IRateService
{
    private HttpClient _httpClient;
    private readonly List<string> CurAbbreviations = new() { "RUB", "EUR", "USD", "CHF", "CNY", "GBP" };
    public RateService(HttpClient httpClient) 
    {
        _httpClient = httpClient;
    }
    public IEnumerable<Rate>? GetRates(DateTime date)
    {
        List<Rate> rates = new();
        string uri = $"{_httpClient.BaseAddress}?ondate={date:yyyy-MM-dd}&periodicity=0";
        var response = _httpClient.GetAsync(uri).Result;
        if (response.IsSuccessStatusCode)
        {
            string content = response.Content.ReadAsStringAsync().Result;
            rates = JsonSerializer.Deserialize<List<Rate>>(content);
        }
        return rates?.Where(x => CurAbbreviations.Contains(x.Cur_Abbreviation));
    }
}