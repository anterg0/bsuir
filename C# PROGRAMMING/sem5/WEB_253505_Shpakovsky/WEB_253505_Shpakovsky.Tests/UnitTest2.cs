using NSubstitute;
using Microsoft.Data.Sqlite;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using WEB_253505_Shpakovsky.API.Data;
using WEB_253505_Shpakovsky.API.Services;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;
using Xunit;

namespace WEB_253505.Shpakovsky.Tests
{
    public class ProductServiceApiTests
    {
        private AppDbContext CreateContext()
        {
            var connection = new SqliteConnection("Filename=:memory:");
            connection.Open();
            var options = new DbContextOptionsBuilder<AppDbContext>()
                .UseSqlite(connection)
                .Options;

            var context = new AppDbContext(options);
            context.Database.EnsureCreated();
            SeedData(context);
            return context;
        }

        private void SeedData(AppDbContext context)
        {
            var genres = new List<Genre>
            {
                new Genre { ID = 1, Name = "Комедия", NormalizedName = "comedy" },
                new Genre { ID = 2, Name = "Драма", NormalizedName = "drama" },
                new Genre { ID = 3, Name = "Экшен", NormalizedName = "action" }
            };

            context.Genres.AddRange(genres);

            var movies = new List<Movie>
            {
                new Movie { ID = 1, Name = "Фильм 1", Description = "Описание фильма 1", CategoryID = 1, Rating = 8.5 },
                new Movie { ID = 2, Name = "Фильм 2", Description = "Описание фильма 2", CategoryID = 2, Rating = 7.2 },
                new Movie { ID = 3, Name = "Фильм 3", Description = "Описание фильма 3", CategoryID = 1, Rating = 9.1 },
                new Movie { ID = 4, Name = "Фильм 4", Description = "Описание фильма 4", CategoryID = 3, Rating = 6.8 },
                new Movie { ID = 5, Name = "Фильм 5", Description = "Описание фильма 5", CategoryID = 2, Rating = 7.5 },
                new Movie { ID = 6, Name = "Фильм 6", Description = "Описание фильма 6", CategoryID = 1, Rating = 8.0 }
            };

            context.Movies.AddRange(movies);
            context.SaveChanges();
        }

        private IConfiguration CreateMockConfiguration()
        {
            var mockConfig = Substitute.For<IConfiguration>();
            var section = Substitute.For<IConfigurationSection>();
            section.Value.Returns("3");
            mockConfig.GetSection("ItemsPerPage").Returns(section);
            return mockConfig;
        }

        [Fact]
        public async Task GetMovieListAsync_ReturnsFirstPageOfThreeItems()
        {
            using var context = CreateContext();
            var mockConfig = CreateMockConfiguration();

            var movieService = new MovieService(context, mockConfig);
            var result = await movieService.GetMovieListAsync(null, pageNo: 1);

            Assert.IsType<ResponseData<ListModel<Movie>>>(result);
            Assert.True(result.Successfull);
            Assert.Equal(1, result.Data.CurrentPage);
            Assert.Equal(3, result.Data.Items.Count); 
            Assert.Equal(context.Movies.First(m => m.ID == 1), result.Data.Items[0]);
        }

        [Fact]
        public async Task GetMovieListAsync_ReturnsCorrectPage()
        {
            using var context = CreateContext();
            var mockConfig = CreateMockConfiguration();  
            var movieService = new MovieService(context, mockConfig);
            var result = await movieService.GetMovieListAsync(null, pageNo: 2);

            Assert.True(result.Successfull);
            Assert.Equal(2, result.Data.CurrentPage);
            Assert.Equal(3, result.Data.Items.Count);  
        }

        [Fact]
        public async Task GetMovieListAsync_FiltersMoviesByCategory()
        {
            using var context = CreateContext();
            var mockConfig = CreateMockConfiguration();
            var movieService = new MovieService(context, mockConfig);
            var result = await movieService.GetMovieListAsync("comedy", pageNo: 1);

            Assert.True(result.Successfull);
            Assert.Equal(3, result.Data.Items.Count); 
            Assert.All(result.Data.Items, movie => Assert.Equal("comedy", movie.Category.NormalizedName));
        }

        [Fact]
        public async Task GetMovieListAsync_PageSizeExceedsMax_ReturnsMaxPageSize()
        {
            using var context = CreateContext();
            var mockConfig = CreateMockConfiguration();
            var movieService = new MovieService(context, mockConfig);
            var result = await movieService.GetMovieListAsync(null, pageNo: 1);

            Assert.True(result.Successfull);
            Assert.Equal(3, result.Data.Items.Count);  
        }

        [Fact]
        public async Task GetMovieListAsync_PageNumberExceedsTotalPages_ReturnsError()
        {
            using var context = CreateContext();
            var mockConfig = CreateMockConfiguration(); 
            var movieService = new MovieService(context, mockConfig);
            var result = await movieService.GetMovieListAsync(null, pageNo: 10);

            Assert.False(result.Successfull);
            Assert.Equal("Такой страницы не существует", result.ErrorMessage); 
        }
    }
}
