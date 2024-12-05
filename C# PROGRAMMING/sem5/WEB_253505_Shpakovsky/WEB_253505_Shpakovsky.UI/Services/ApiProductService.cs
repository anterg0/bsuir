using System.Security.AccessControl;
using System.Text;
using System.Text.Json;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.UI.Services;

public class ApiProductService : IMovieService
{
    private readonly HttpClient _httpClient;
    private readonly JsonSerializerOptions _serializerOptions;
    private readonly ILogger<ApiProductService> _logger;
    private readonly IFileService _fileService;
    public ApiProductService(HttpClient httpClient, ILogger<ApiProductService> logger, IFileService fileService)
    {
        _httpClient = httpClient;
        _serializerOptions = new JsonSerializerOptions
        {
            PropertyNamingPolicy = JsonNamingPolicy.CamelCase
        };
        _logger = logger;
        _fileService = fileService;
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
            var response = await _httpClient.GetAsync($"Movies/{id}");
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

            if (formFile != null)
            {

                if (!string.IsNullOrEmpty(product.Image))
                {
                    var existingFileName = Path.GetFileName(product.Image);
                    await _fileService.DeleteFileAsync(existingFileName);
                }
                
                var imageUrl = await _fileService.SaveFileAsync(formFile);
                if (!string.IsNullOrEmpty(imageUrl))
                {
                    product.Image = imageUrl; 
                }
            }
            
            var response = await _httpClient.PutAsJsonAsync($"Movies/{id}", product);

            if (!response.IsSuccessStatusCode)
            {
                var errorContent = await response.Content.ReadAsStringAsync();
                
                Console.WriteLine($"Ошибка: {response.StatusCode}");
                Console.WriteLine($"Тело ошибки: {errorContent}");
                
                throw new Exception($"Ошибка запроса: {response.StatusCode}, {errorContent}");
            }
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка обновления фильма: {ex.Message}");
            throw new Exception($"Ошибка обновления фильма: {ex.Message}");
        }
    }

    public async Task DeleteMovieAsync(int id)
    {
        try
        {
            var response = await _httpClient.DeleteAsync($"Movies/{id}");
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
            if (formFile != null)
            {
                var imageUrl = await _fileService.SaveFileAsync(formFile);
                if (!string.IsNullOrEmpty(imageUrl))
                {
                    product.Image = imageUrl;
                }

                product.MimeType = formFile.ContentType;
            }
            
            var response = await _httpClient.PostAsJsonAsync("Movies", product);

            if (!response.IsSuccessStatusCode)
            {
                var errorContent = await response.Content.ReadAsStringAsync();
                
                Console.WriteLine($"Ошибка: {response.StatusCode}");
                Console.WriteLine($"Тело ошибки: {errorContent}");

                throw new Exception($"Ошибка запроса: {response.StatusCode}, {errorContent}");
            }
            else
            {

                var result = await response.Content.ReadAsStringAsync();
                Console.WriteLine("Фильм успешно создан: " + result);
            }

            return await response.Content.ReadFromJsonAsync<ResponseData<Movie>>()
                   ?? ResponseData<Movie>.Error("Не удалось обработать данные.");
        }
        catch (Exception ex)
        {
            _logger.LogError($"Ошибка создания фильма: {ex.Message}");
            return ResponseData<Movie>.Error($"Ошибка при создании фильма: {ex.Message}");
        }
    }

}