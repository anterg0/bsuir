using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.UI.Services.GenreService;

public class MemoryGenreService : IGenreService
{
    private List<Genre> _genres;

    public MemoryGenreService()
    {
        _genres = new List<Genre>
        {
            new Genre { ID = 1, Name = "Фантастика", NormalizedName = "scifi" },
            new Genre { ID = 2, Name = "Драма", NormalizedName = "drama" },
            new Genre { ID = 3, Name = "Боевик", NormalizedName = "action" },
            new Genre { ID = 4, Name = "Комедия", NormalizedName = "comedy" }
        };
    }
    
    public Task<ResponseData<List<Genre>>> GetGenreListAsync()
    {
        return Task.FromResult(ResponseData<List<Genre>>.Success(_genres));
    }
    
    public Task<ResponseData<Genre>> GetGenreByIdAsync(int id)
    {
        var genre = _genres.FirstOrDefault(g => g.ID == id);
        if (genre == null)
        {
            return Task.FromResult(ResponseData<Genre>.Error("Жанр не найден", null));
        }
        return Task.FromResult(ResponseData<Genre>.Success(genre));
    }
}
