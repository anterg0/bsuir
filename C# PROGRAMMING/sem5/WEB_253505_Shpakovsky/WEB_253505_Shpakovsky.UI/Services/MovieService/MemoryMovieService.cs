using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;
using WEB_253505_Shpakovsky.UI.Services.GenreService;

namespace WEB_253505_Shpakovsky.UI.Services.MovieService;

public class MemoryMovieService : IMovieService
{
    private List<Movie> _movies;
    private List<Genre> _categories;
    private string _uploadPath = "/Users/anterg0/Documents/bsuir/C# PROGRAMMING/sem5/WEB_253505_Shpakovsky/WEB_253505_Shpakovsky.UI/wwwroot/images";
    public MemoryMovieService(IGenreService genreService)
    {
        _categories = genreService.GetGenreListAsync().Result.Data;
        _movies = new List<Movie>
        {
            new Movie { ID = 1, Name = "Начало", Description = "Фантастический триллер о воровстве через сны.", Category = _categories.Find(m => m.NormalizedName == "action"), Duration = 148, Rating = 8.8, Image = "images/inception.jpg", MimeType = "image/jpeg" },
            new Movie { ID = 2, Name = "Интерстеллар", Description = "Космическая драма о выживании человечества.", Category = _categories.Find(m => m.NormalizedName == "scifi"), Duration = 169, Rating = 8.6, Image = "images/interstellar.jpg", MimeType = "image/jpeg" },
            new Movie { ID = 3, Name = "Темный рыцарь", Description = "История Бэтмена и его битвы с Джокером.", Category = _categories.Find(m => m.NormalizedName == "action"),Duration = 152, Rating = 9.0, Image = "images/dark_knight.jpg", MimeType = "image/jpeg" },
            new Movie { ID = 4, Name = "Матрица", Description = "Фильм о мире, в котором все люди живут в виртуальной реальности.", Category = _categories.Find(m => m.NormalizedName == "scifi"),Duration = 136, Rating = 8.7, Image = "images/matrix.jpg", MimeType = "image/jpeg" }
        };
    }
    
    public Task<ResponseData<ListModel<Movie>>> GetMovieListAsync(int pageNo = 1)
    {
        int itemsPerPage = 2;
        var totalPages = (int)Math.Ceiling((double)_movies.Count / itemsPerPage);
        
        var moviesPage = _movies.Skip((pageNo - 1) * itemsPerPage).Take(itemsPerPage).ToList();
        
        var result = new ListModel<Movie>
        {
            Items = moviesPage,
            CurrentPage = pageNo,
            TotalPages = totalPages
        };

        return Task.FromResult(ResponseData<ListModel<Movie>>.Success(result));
    }
    
    public Task<ResponseData<Movie>> GetMovieByIdAsync(int id)
    {
        var movie = _movies.FirstOrDefault(m => m.ID == id);
        if (movie == null)
        {
            return Task.FromResult(ResponseData<Movie>.Error("Фильм не найден", null));
        }
        return Task.FromResult(ResponseData<Movie>.Success(movie));
    }

    public Task UpdateMovieAsync(int id, Movie updatedMovie, IFormFile? formFile)
    {
        var movie = _movies.FirstOrDefault(m => m.ID == id);
        if (movie == null)
        {
            return Task.FromResult(ResponseData<Movie>.Error("Фильм не найден", null));
        }
        
        movie.Name = updatedMovie.Name;
        movie.Description = updatedMovie.Description;
        movie.Duration = updatedMovie.Duration;
        movie.Rating = updatedMovie.Rating;
        
        if (formFile != null)
        {
            var filePath = $"images/{formFile.FileName}";
            using (var stream = new FileStream(filePath, FileMode.Create))
            {
                formFile.CopyTo(stream);
            }
            movie.Image = filePath;
        }

        return Task.FromResult(ResponseData<Movie>.Success(movie));
    }

    public Task DeleteMovieAsync(int id)
    {
        var movie = _movies.FirstOrDefault(m => m.ID == id);
        if (movie == null)
        {
            return Task.FromResult(ResponseData<Movie>.Error("Фильм не найден", null));
        }

        _movies.Remove(movie);
        return Task.FromResult(ResponseData<Movie>.Success(movie));
    }

    public Task<ResponseData<Movie>> CreateMovieAsync(Movie newMovie, IFormFile? formFile)
    {
        newMovie.ID = _movies.Max(m => m.ID) + 1;
        
        if (formFile != null)
        {
            var filePath = $"images/{formFile.FileName}";
            using (var stream = new FileStream(filePath, FileMode.Create))
            {
                formFile.CopyTo(stream);
            }
            newMovie.Image = filePath;
        }

        _movies.Add(newMovie);
        return Task.FromResult(ResponseData<Movie>.Success(newMovie));
    }

}