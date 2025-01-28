using WEB_253505_Shpakovsky.Domain.Entities;

namespace WEB_253505_Shpakovsky.BlazorWasm.Services;

public interface IDataService
{
    event Action DataLoaded;
    List<Genre> Genres { get; set; }
    List<Movie> Movies { get; set; }
    bool Success { get; set; }
    string ErrorMessage { get; set; }
    int TotalPages { get; set; }
    int CurrentPage { get; set; }
    Genre SelectedCategory { get; set; }
    public Task GetProductListAsync(int pageNo = 1);
    public Task GetCategoryListAsync();
}