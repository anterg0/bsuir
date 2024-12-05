using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.UI.Services;

namespace WEB_253505_Shpakovsky.UI.Areas.Admin.Pages
{
    public class DetailsModel : PageModel
    {
        private readonly IMovieService _movieService;

        public DetailsModel(IMovieService movieService)
        {
            _movieService = movieService;
        }

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
    }
}