using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_253505_Shpakovsky.API.Services;
using WEB_253505_Shpakovsky.UI.Models;

namespace WEB_253505_Shpakovsky.UI.Controllers
{
    public class ProductController : Controller
    {
        private readonly IMovieService _movieService;
        private readonly IGenreService _categoryService;

        public ProductController(IMovieService movieService, IGenreService categoryService)
        {
            _movieService = movieService;
            _categoryService = categoryService;
        }

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
            return View(productResponse.Data);
        }
    }
}