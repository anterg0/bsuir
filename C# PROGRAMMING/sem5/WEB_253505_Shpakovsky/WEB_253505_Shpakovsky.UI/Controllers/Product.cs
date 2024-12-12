using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_253505_Shpakovsky.UI.Extensions;
using WEB_253505_Shpakovsky.UI.Models;
using WEB_253505_Shpakovsky.UI.Services;

namespace WEB_253505_Shpakovsky.UI.Controllers
{
    [Route("catalog")]
    public class ProductController : Controller
    {
        private readonly IMovieService _movieService;
        private readonly IGenreService _categoryService;
        public ProductController(IMovieService movieService, IGenreService categoryService)
        {
            _movieService = movieService;
            _categoryService = categoryService;
        }
        [HttpGet("{category?}")]
        public async Task<IActionResult> Index(string? category, int pageNo = 1)
        {
            var categoryResponse = await _categoryService.GetGenreListAsync();
            var productResponse = await _movieService.GetMovieListAsync(category, pageNo);
            if (!productResponse.Successfull)
                return NotFound(productResponse.ErrorMessage);
            else if (!categoryResponse.Successfull)
                return NotFound(categoryResponse.ErrorMessage);
            ViewData["currentCategory"] = category != null
                ? categoryResponse.Data.FirstOrDefault(c => c.NormalizedName == category)?.Name
                : "Все категории";
            ViewBag.Categories = categoryResponse.Data;
            if (Request.IsAjaxRequest())
            {
                return PartialView("_MovieListPartial", productResponse.Data);
            }
            return View(productResponse.Data);
        }
    }
}