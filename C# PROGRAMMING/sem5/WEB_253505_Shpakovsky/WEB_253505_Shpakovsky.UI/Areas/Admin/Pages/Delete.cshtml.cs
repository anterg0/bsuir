using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.UI.Services;

namespace WEB_253505_Shpakovsky.UI.Areas.Admin.Pages
{
    public class DeleteModel : PageModel
    {
        private readonly IMovieService _movieService;

        public DeleteModel(IMovieService movieService)
        {
            _movieService = movieService;
        }

        [BindProperty]
        public Movie Movie { get; set; } = default!;

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
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            try
            {
                await _movieService.DeleteMovieAsync(id.Value);
            }
            catch (Exception ex)
            {
                ModelState.AddModelError(string.Empty, $"Ошибка при удалении: {ex.Message}");
                return Page();
            }

            return RedirectToPage("./Index");
        }
    }
}