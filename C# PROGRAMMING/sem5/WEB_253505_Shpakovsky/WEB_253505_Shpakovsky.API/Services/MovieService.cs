using Microsoft.EntityFrameworkCore;
using WEB_253505_Shpakovsky.API.Data;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.API.Services;

public class MovieService : IMovieService
{
    private readonly AppDbContext _context;
    private readonly int _pageSize;

    public MovieService(AppDbContext context, IConfiguration configuration)
    {
        _context = context;
        _pageSize = configuration.GetValue<int>("ItemsPerPage", 3);
    }

    public async Task<ResponseData<ListModel<Movie>>> GetMovieListAsync(string? categoryNormalizedName, int pageNo = 1)
    {
        var query = _context.Movies.Include(m => m.Category).AsQueryable();

        if (!string.IsNullOrEmpty(categoryNormalizedName))
        {
            query = query.Where(m => m.Category != null && m.Category.NormalizedName == categoryNormalizedName);
        }

        var totalItems = await query.CountAsync();
        var totalPages = (int)Math.Ceiling(totalItems / (double)_pageSize);

        if (pageNo > totalPages)
        {
            return ResponseData<ListModel<Movie>>.Error("Такой страницы не существует");
        }

        var movies = await query
            .Skip((pageNo - 1) * _pageSize)
            .Take(_pageSize)
            .ToListAsync();

        var result = new ListModel<Movie>
        {
            Items = movies,
            CurrentPage = pageNo,
            TotalPages = totalPages
        };

        return ResponseData<ListModel<Movie>>.Success(result);
    }

    public async Task<ResponseData<Movie>> GetMovieByIdAsync(int id)
    {
        var movie = await _context.Movies.Include(m => m.Category).FirstOrDefaultAsync(m => m.ID == id);

        if (movie == null)
        {
            return ResponseData<Movie>.Error("Фильм не найден");
        }

        return ResponseData<Movie>.Success(movie);
    }

    public async Task UpdateMovieAsync(int id, Movie product, IFormFile? formFile)
    {
        var existingMovie = await _context.Movies.FindAsync(id);

        if (existingMovie == null)
        {
            throw new KeyNotFoundException("Фильм не найден");
        }

        existingMovie.Name = product.Name;
        existingMovie.Description = product.Description;
        existingMovie.Rating = product.Rating;
        existingMovie.Duration = product.Duration;
        existingMovie.CategoryID = product.CategoryID;
        existingMovie.Image = product.Image;
        
        if (formFile != null)
        {
            existingMovie.Image = product.Image;
        }

        _context.Entry(existingMovie).State = EntityState.Modified;
        await _context.SaveChangesAsync();
    }

    public async Task DeleteMovieAsync(int id)
    {
        var movie = await _context.Movies.FindAsync(id);

        if (movie == null)
        {
            throw new KeyNotFoundException("Фильм не найден");
        }

        _context.Movies.Remove(movie);
        await _context.SaveChangesAsync();
    }

    public async Task<ResponseData<Movie>> CreateMovieAsync(Movie product, IFormFile? formFile)
    {

        _context.Movies.Add(product);
        await _context.SaveChangesAsync();

        return ResponseData<Movie>.Success(product);
    }
}