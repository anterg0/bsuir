using System.Text.Json;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.UI.Services;

public class ApiCategoryService : IGenreService
{
    private readonly HttpClient _httpClient;
    private readonly JsonSerializerOptions _serializerOptions;
    private readonly ILogger<ApiCategoryService> _logger;

    public ApiCategoryService(HttpClient httpClient, ILogger<ApiCategoryService> logger)
    {
        _httpClient = httpClient;
        _serializerOptions = new JsonSerializerOptions
        {
            PropertyNamingPolicy = JsonNamingPolicy.CamelCase
        };
        _logger = logger;
    }

    public async Task<ResponseData<List<Genre>>> GetGenreListAsync()
    {
        try
        {
            var response = await _httpClient.GetAsync("Genres");
            if (response.IsSuccessStatusCode)
            {
                return await response.Content.ReadFromJsonAsync<ResponseData<List<Genre>>>(_serializerOptions)
                       ?? ResponseData<List<Genre>>.Error("Не удалось обработать данные");
            }

            return ResponseData<List<Genre>>.Error($"Ошибка API: {response.StatusCode}");
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка при получении жанров: {ex.Message}");
            return ResponseData<List<Genre>>.Error("Ошибка при получении данных");
        }
    }

    public async Task<ResponseData<Genre>> GetGenreByIdAsync(int id)
    {
        try
        {
            var response = await _httpClient.GetAsync($"Genres/{id}");
            if (response.IsSuccessStatusCode)
            {
                return await response.Content.ReadFromJsonAsync<ResponseData<Genre>>(_serializerOptions)
                       ?? ResponseData<Genre>.Error("Не удалось обработать данные");
            }

            return ResponseData<Genre>.Error($"Ошибка API: {response.StatusCode}");
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка при получении жанра: {ex.Message}");
            return ResponseData<Genre>.Error("Ошибка при получении данных");
        }
    }
}