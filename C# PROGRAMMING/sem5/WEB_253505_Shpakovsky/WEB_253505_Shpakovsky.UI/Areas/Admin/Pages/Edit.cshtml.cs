using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.UI.Services;

namespace WEB_253505_Shpakovsky.UI.Areas.Admin.Pages
{
    public class EditModel : PageModel
    {
        private readonly IMovieService _movieService;
        private readonly IGenreService _categoryService;

        public EditModel(IMovieService movieService, IGenreService categoryService)
        {
            _movieService = movieService;
            _categoryService = categoryService;
        }

        [BindProperty]
        public Movie Movie { get; set; } = default!;
        [BindProperty]
        public IFormFile? Image { get; set; }


        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var response = await _movieService.GetMovieByIdAsync(id.Value);
            if (!response.Successfull || response.Data == null)
            {
                return NotFound(response.ErrorMessage);
            }

            Movie = response.Data;

            // Получение категорий
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

            try
            {
                await _movieService.UpdateMovieAsync(Movie.ID, Movie, Image);
            }
            catch (Exception ex)
            {
                ModelState.AddModelError(string.Empty, $"Ошибка при обновлении: {ex.Message}");
                return Page();
            }

            return RedirectToPage("./Index");
        }

    }
}