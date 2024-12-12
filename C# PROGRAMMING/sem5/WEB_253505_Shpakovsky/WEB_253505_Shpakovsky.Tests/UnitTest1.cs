using Microsoft.AspNetCore.Http;
using NSubstitute;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.ViewFeatures;
using WEB_253505_Shpakovsky.Domain.Models;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.UI.Controllers;
using WEB_253505_Shpakovsky.UI.Services;
using Xunit;

public class ProductControllerTests
{
    private readonly IGenreService _mockGenreService;
    private readonly IMovieService _mockMovieService;
    private readonly ProductController _controller;

    public ProductControllerTests()
    {
        _mockGenreService = Substitute.For<IGenreService>();
        _mockMovieService = Substitute.For<IMovieService>();
        _controller = new ProductController(_mockMovieService, _mockGenreService);
    }

    [Fact]
    public async Task Index_Returns404_IfGenresNotSuccessful()
    {
        _mockGenreService.GetGenreListAsync().Returns(ResponseData<List<Genre>>.Error("Ошибка получения жанров"));
        _mockMovieService.GetMovieListAsync(null, 1).Returns(ResponseData<ListModel<Movie>>.Success(new ListModel<Movie>()));

        var result = await _controller.Index(null);

        Assert.IsType<NotFoundObjectResult>(result);
    }

    [Fact]
    public async Task Index_Returns404_IfMoviesNotSuccessful()
    {
        _mockGenreService.GetGenreListAsync().Returns(ResponseData<List<Genre>>.Success(new List<Genre>()));
        _mockMovieService.GetMovieListAsync(null, 1).Returns(ResponseData<ListModel<Movie>>.Error("Ошибка загрузки фильмов"));
        
        var result = await _controller.Index(null);
        
        Assert.IsType<NotFoundObjectResult>(result);
    }

    [Fact]
    public async Task Index_SetsCategoriesAndReturnsView_WhenSuccessful()
    {
        var genres = new List<Genre>
        {
            new Genre { ID = 1, Name = "Комедия", NormalizedName = "comedy" },
            new Genre { ID = 2, Name = "Драма", NormalizedName = "drama" }
        };

        var movies = new ListModel<Movie>
        {
            Items = new List<Movie>
            {
                new Movie { ID = 1, Name = "Фильм 1", CategoryID = 1, Rating = 8.5 },
                new Movie { ID = 2, Name = "Фильм 2", CategoryID = 1, Rating = 7.2 }
            },
            CurrentPage = 1,
            TotalPages = 1
        };

        _mockGenreService.GetGenreListAsync().Returns(ResponseData<List<Genre>>.Success(genres));
        _mockMovieService.GetMovieListAsync("comedy", 1).Returns(ResponseData<ListModel<Movie>>.Success(movies));
        
        var result = await _controller.Index("comedy");
        
        var viewResult = Assert.IsType<ViewResult>(result);
        Assert.Equal("Комедия", _controller.ViewData["currentCategory"]);
        Assert.Equal(genres, _controller.ViewBag.Categories);
        Assert.Equal(movies, viewResult.Model);
    }
    [Fact]
    public async Task Index_ReturnsPartialView_WhenAjaxRequest()
    {
        var genres = new List<Genre>
        {
            new Genre { ID = 1, Name = "Комедия", NormalizedName = "comedy" },
            new Genre { ID = 2, Name = "Драма", NormalizedName = "drama" }
        };

        var movies = new ListModel<Movie>
        {
            Items = new List<Movie>
            {
                new Movie { ID = 1, Name = "Фильм 1", CategoryID = 1, Rating = 8.5 },
                new Movie { ID = 2, Name = "Фильм 2", CategoryID = 1, Rating = 7.2 }
            },
            CurrentPage = 1,
            TotalPages = 1
        };

        _mockGenreService.GetGenreListAsync().Returns(ResponseData<List<Genre>>.Success(genres));
        _mockMovieService.GetMovieListAsync("comedy", 1).Returns(ResponseData<ListModel<Movie>>.Success(movies));
        
        var httpContext = Substitute.For<HttpContext>();
        var request = Substitute.For<HttpRequest>();
        httpContext.Request.Returns(request);
        request.Headers.Returns(new HeaderDictionary { { "X-Requested-With", "XMLHttpRequest" } });
        
        var tempData = Substitute.For<ITempDataDictionary>();
        _controller.TempData = tempData;

        _controller.ControllerContext = new ControllerContext
        {
            HttpContext = httpContext
        };
        
        var result = await _controller.Index("comedy");
        
        var partialViewResult = Assert.IsType<PartialViewResult>(result);
        Assert.Equal("_MovieListPartial", partialViewResult.ViewName);
        Assert.Equal(movies, partialViewResult.Model);
    }


}
