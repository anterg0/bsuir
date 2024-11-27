using System.Net.Http.Json;
using System.Text;
using System.Text.Json;
using Microsoft.Extensions.Logging;
using WEB_253505_Shpakovsky.API.Services;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

public class ApiProductService : IMovieService
{
    private readonly HttpClient _httpClient;
    private readonly JsonSerializerOptions _serializerOptions;
    private readonly ILogger<ApiProductService> _logger;

    public ApiProductService(HttpClient httpClient, ILogger<ApiProductService> logger)
    {
        _httpClient = httpClient;
        _serializerOptions = new JsonSerializerOptions
        {
            PropertyNamingPolicy = JsonNamingPolicy.CamelCase
        };
        _logger = logger;
    }

    public async Task<ResponseData<ListModel<Movie>>> GetMovieListAsync(string? categoryNormalizedName, int pageNo = 1)
    {
        try
        {
            var url = new StringBuilder("Movies");
            if (!string.IsNullOrEmpty(categoryNormalizedName))
            {
                url.Append($"/category/{categoryNormalizedName}");
            }
            url.Append($"?pageNo={pageNo}");

            var response = await _httpClient.GetAsync(url.ToString());
            if (response.IsSuccessStatusCode)
            {
                return await response.Content.ReadFromJsonAsync<ResponseData<ListModel<Movie>>>(_serializerOptions)
                    ?? ResponseData<ListModel<Movie>>.Error("Не удалось обработать данные");
            }

            return ResponseData<ListModel<Movie>>.Error($"Ошибка API: {response.StatusCode}");
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка при получении фильмов: {ex.Message}");
            return ResponseData<ListModel<Movie>>.Error("Ошибка при получении данных");
        }
    }

    public async Task<ResponseData<Movie>> GetMovieByIdAsync(int id)
    {
        try
        {
            var response = await _httpClient.GetAsync($"Movies/id/{id}");
            if (response.IsSuccessStatusCode)
            {
                return await response.Content.ReadFromJsonAsync<ResponseData<Movie>>(_serializerOptions)
                    ?? ResponseData<Movie>.Error("Не удалось обработать данные");
            }

            return ResponseData<Movie>.Error($"Ошибка API: {response.StatusCode}");
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка при получении фильма: {ex.Message}");
            return ResponseData<Movie>.Error("Ошибка при получении данных");
        }
    }

    public async Task UpdateMovieAsync(int id, Movie product, IFormFile? formFile)
    {
        try
        {
            var content = new MultipartFormDataContent
            {
                { new StringContent(product.Name), "Name" },
                { new StringContent(product.Description), "Description" },
                { new StringContent(product.Duration.ToString()), "Duration" },
                { new StringContent(product.Rating.ToString()), "Rating" }
            };

            if (formFile != null)
            {
                var fileStream = formFile.OpenReadStream();
                content.Add(new StreamContent(fileStream), "FormFile", formFile.FileName);
            }

            var response = await _httpClient.PutAsync($"Movies/id/{id}", content);

            if (!response.IsSuccessStatusCode)
            {
                _logger.LogError($"Ошибка обновления фильма: {response.StatusCode}");
                throw new Exception($"Ошибка обновления фильма: {response.StatusCode}");
            }
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка обновления фильма: {ex.Message}");
            throw;
        }
    }

    public async Task DeleteMovieAsync(int id)
    {
        try
        {
            var response = await _httpClient.DeleteAsync($"Movies/id/{id}");
            if (!response.IsSuccessStatusCode)
            {
                _logger.LogError($"Ошибка удаления фильма: {response.StatusCode}");
                throw new Exception($"Ошибка удаления фильма: {response.StatusCode}");
            }
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка удаления фильма: {ex.Message}");
            throw;
        }
    }

    public async Task<ResponseData<Movie>> CreateMovieAsync(Movie product, IFormFile? formFile)
    {
        try
        {
            var content = new MultipartFormDataContent
            {
                { new StringContent(product.Name), "Name" },
                { new StringContent(product.Description), "Description" },
                { new StringContent(product.Duration.ToString()), "Duration" },
                { new StringContent(product.Rating.ToString()), "Rating" }
            };

            if (formFile != null)
            {
                var fileStream = formFile.OpenReadStream();
                content.Add(new StreamContent(fileStream), "FormFile", formFile.FileName);
            }

            var response = await _httpClient.PostAsync("Movies", content);

            if (response.IsSuccessStatusCode)
            {
                return await response.Content.ReadFromJsonAsync<ResponseData<Movie>>(_serializerOptions)
                    ?? ResponseData<Movie>.Error("Не удалось обработать данные");
            }

            return ResponseData<Movie>.Error($"Ошибка API: {response.StatusCode}");
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка создания фильма: {ex.Message}");
            return ResponseData<Movie>.Error("Ошибка при создании фильма");
        }
    }
}
