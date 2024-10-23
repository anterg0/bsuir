using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.UI.Services.GenreService;

public interface IGenreService
{
    /// <summary>
    /// Возвращает список жанров
    /// </summary>
    /// <returns></returns>
    public Task<ResponseData<List<Genre>>> GetGenreListAsync();
    /// <summary>
    /// Поиск жанра по ID
    /// </summary>
    /// <param name="id">Идентификатор жанра</param>
    /// <returns>Найденный жанр или null, если жанр не найден</returns>
    Task<ResponseData<Genre>> GetGenreByIdAsync(int id);
}