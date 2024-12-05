using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.UI.Services
{
    public interface IMovieService
    {
        Task<ResponseData<ListModel<Movie>>> GetMovieListAsync(string? categoryNormalizedName, int pageNo = 1);
        Task<ResponseData<Movie>> GetMovieByIdAsync(int id);
        Task UpdateMovieAsync(int id, Movie product, IFormFile? formFile);
        Task DeleteMovieAsync(int id);
        Task<ResponseData<Movie>> CreateMovieAsync(Movie product, IFormFile? formFile);
    }
}