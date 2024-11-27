using Microsoft.EntityFrameworkCore;
using WEB_253505_Shpakovsky.API.Data;
using WEB_253505_Shpakovsky.API.Services;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

public class GenreService : IGenreService
{
    private readonly AppDbContext _context;

    public GenreService(AppDbContext context)
    {
        _context = context;
    }

    public async Task<ResponseData<List<Genre>>> GetGenreListAsync()
    {
        var genres = await _context.Genres.ToListAsync();
        return ResponseData<List<Genre>>.Success(genres);
    }

    public async Task<ResponseData<Genre>> GetGenreByIdAsync(int id)
    {
        var genre = await _context.Genres.FindAsync(id);

        if (genre == null)
        {
            return ResponseData<Genre>.Error("Жанр не найден");
        }

        return ResponseData<Genre>.Success(genre);
    }
}