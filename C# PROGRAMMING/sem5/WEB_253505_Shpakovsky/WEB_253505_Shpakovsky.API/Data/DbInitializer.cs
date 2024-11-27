using Microsoft.EntityFrameworkCore;
using WEB_253505_Shpakovsky.Domain.Entities;

namespace WEB_253505_Shpakovsky.API.Data;

public class DbInitializer
{
public static async Task SeedData(WebApplication app)
    {
        using var scope = app.Services.CreateScope();
        var context = scope.ServiceProvider.GetRequiredService<AppDbContext>();

        await context.Database.MigrateAsync();

        if (!context.Genres.Any())
        {
            var genres = new List<Genre>
            {
                new Genre { Name = "Фантастика", NormalizedName = "scifi" },
                new Genre { Name = "Драма", NormalizedName = "drama" },
                new Genre { Name = "Боевик", NormalizedName = "action" },
                new Genre { Name = "Комедия", NormalizedName = "comedy" }
            };

            await context.Genres.AddRangeAsync(genres);
            await context.SaveChangesAsync();
        }

        if (!context.Movies.Any())
        {
            var genres = context.Genres.ToList();
            var baseUrl = "http://localhost:7002/";

            var movies = new List<Movie>
            {
                new Movie { Name = "Начало", Description = "Фантастический триллер о воровстве через сны.", Category = genres.FirstOrDefault(g => g.NormalizedName == "action"), Duration = 148, Rating = 8.8, Image = $"{baseUrl}images/inception.jpg", MimeType = "image/jpeg" },
                new Movie { Name = "Интерстеллар", Description = "Космическая драма о выживании человечества.", Category = genres.FirstOrDefault(g => g.NormalizedName == "scifi"), Duration = 169, Rating = 8.6, Image = $"{baseUrl}images/interstellar.jpg", MimeType = "image/jpeg" },
                new Movie { Name = "Темный рыцарь", Description = "История Бэтмена и его битвы с Джокером.", Category = genres.FirstOrDefault(g => g.NormalizedName == "action"), Duration = 152, Rating = 9.0, Image = $"{baseUrl}images/dark_knight.jpg", MimeType = "image/jpeg" },
                new Movie { Name = "Матрица", Description = "Фильм о мире, в котором все люди живут в виртуальной реальности.", Category = genres.FirstOrDefault(g => g.NormalizedName == "scifi"), Duration = 136, Rating = 8.7, Image = $"{baseUrl}images/matrix.jpg", MimeType = "image/jpeg" }
            };

            await context.Movies.AddRangeAsync(movies);
            await context.SaveChangesAsync();
        }
    }
}