using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.UI.Services
{
    public interface IGenreService
    {
        Task<ResponseData<List<Genre>>> GetGenreListAsync();
        Task<ResponseData<Genre>> GetGenreByIdAsync(int id);
    }
}