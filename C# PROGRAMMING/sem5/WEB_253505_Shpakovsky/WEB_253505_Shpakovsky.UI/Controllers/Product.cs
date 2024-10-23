using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_253505_Shpakovsky.UI.Models;
using WEB_253505_Shpakovsky.UI.Services.GenreService;
using WEB_253505_Shpakovsky.UI.Services.MovieService;

namespace WEB_253505_Shpakovsky.UI.Controllers
{
    public class ProductController : Controller
    {
        private readonly IMovieService _productService; // Use interface
        private readonly IGenreService _categoryService; // Use interface

        public ProductController(IMovieService productService, IGenreService categoryService)
        {
            _productService = productService;
            _categoryService = categoryService;
        }

        public async Task<IActionResult> Index()
        {
            var productResponse = await _productService.GetMovieListAsync();
            if (!productResponse.Successfull)
                return NotFound(productResponse.ErrorMessage);
    
            return View(productResponse.Data.Items);
        }
    }
}