using System.Net.Http.Json;
using System.Text;
using System.Web;
using Microsoft.AspNetCore.Components.WebAssembly.Authentication;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.BlazorWasm.Services;

    public class DataService : IDataService
    {
        private readonly HttpClient _httpClient;
        private readonly IAccessTokenProvider _tokenProvider;
        private readonly string _apiUrl;
        private readonly int _pageSize;

        public DataService(HttpClient httpClient, IConfiguration configuration, IAccessTokenProvider tokenProvider)
        {
            _httpClient = httpClient;
            _tokenProvider = tokenProvider;
            _apiUrl = configuration["ApiUrl"];
            _pageSize = int.Parse(configuration["ItemsPerPage"]);
        }
        public event Action DataLoaded;
        public List<Genre> Genres { get; set; } = new();
        public List<Movie> Movies { get; set; } = new();
        public bool Success { get; set; } = true;
        public string ErrorMessage { get; set; } = string.Empty;
        public int TotalPages { get; set; } = 1;
        public int CurrentPage { get; set; } = 1;
        public Genre SelectedCategory { get; set; }
        public async Task GetProductListAsync(int pageNo = 1)
        {
            try
            {
                var tokenRequest = await _tokenProvider.RequestAccessToken();
                if (tokenRequest.TryGetToken(out var token))
                {
                    _httpClient.DefaultRequestHeaders.Authorization =
                        new System.Net.Http.Headers.AuthenticationHeaderValue("Bearer", token.Value);
                }
                else
                {
                    Success = false;
                    ErrorMessage = "Unable to acquire token.";
                    return;
                }

                var route = new StringBuilder("Movies/");
                if (SelectedCategory != null)
                {
                    route.Append($"{SelectedCategory.NormalizedName}/");
                }

                var queryData = HttpUtility.ParseQueryString(string.Empty);
                if (pageNo > 1)
                {
                    queryData["pageNo"] = pageNo.ToString();
                }

                if (_pageSize != 3)
                {
                    queryData["pageSize"] = _pageSize.ToString();
                }

                var fullRoute = queryData.Count > 0
                    ? $"{route}?{queryData}"
                    : route.ToString();

                var response = await _httpClient.GetFromJsonAsync<ResponseData<ListModel<Movie>>>($"{_apiUrl}/{fullRoute}");
                if (response != null && response.Successfull && response.Data != null)
                {
                    Movies = response.Data.Items;
                    TotalPages = response.Data.TotalPages;
                    CurrentPage = pageNo;
                    DataLoaded?.Invoke();
                }
                else
                {
                    Success = false;
                    ErrorMessage = response?.ErrorMessage ?? "Unknown error";
                }
            }
            catch (Exception ex)
            {
                Success = false;
                ErrorMessage = ex.Message;
            }
        }

        public async Task GetCategoryListAsync()
        {
            try
            {
                var tokenRequest = await _tokenProvider.RequestAccessToken();
                if (tokenRequest.TryGetToken(out var token))
                {
                    _httpClient.DefaultRequestHeaders.Authorization =
                        new System.Net.Http.Headers.AuthenticationHeaderValue("Bearer", token.Value);
                }
                else
                {
                    Success = false;
                    ErrorMessage = "Unable to acquire token.";
                    return;
                }

                var response = await _httpClient.GetFromJsonAsync<ResponseData<List<Genre>>>($"{_apiUrl}/Genres");
                if (response != null && response.Successfull && response.Data != null)
                {
                    Genres = response.Data;
                    DataLoaded?.Invoke();
                }
                else
                {
                    Success = false;
                    ErrorMessage = response?.ErrorMessage ?? "Unknown error";
                }
            }
            catch (Exception ex)
            {
                Success = false;
                ErrorMessage = ex.Message;
            }
        }
    }