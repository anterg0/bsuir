using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.UI.Services;

namespace WEB_253505_Shpakovsky.UI.Areas.Admin.Pages
{
    public class CreateModel : PageModel
    {
        private readonly IMovieService _movieService;
        private readonly IGenreService _categoryService;

        public CreateModel(IMovieService movieService, IGenreService categoryService)
        {
            _movieService = movieService;
            _categoryService = categoryService;
        }

        [BindProperty]
        public Movie Movie { get; set; } = default!;
        [BindProperty]
        public IFormFile? Image { get; set; }


        public async Task<IActionResult> OnGet()
        {
            var categoryResponse = await _categoryService.GetGenreListAsync();
            if (categoryResponse.Successfull)
            {
                ViewData["Categories"] = new SelectList(categoryResponse.Data, "ID", "Name");
            }

            return Page();
        }

        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }
            
            var response = await _movieService.CreateMovieAsync(Movie, Image);
            if (!response.Successfull)
            {
                ModelState.AddModelError(string.Empty, response.ErrorMessage);
                return Page();
            }

            return RedirectToPage("./Index");
        }
    }
}