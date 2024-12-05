using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.UI.Services;

namespace WEB_253505_Shpakovsky.UI.Areas.Admin.Pages
{
    public class IndexModel : PageModel
    {
        private readonly IMovieService _movieService;

        public IndexModel(IMovieService movieService)
        {
            _movieService = movieService;
        }

        public List<Movie> Movies { get; set; } = new();

        public async Task OnGetAsync()
        {
            var response = await _movieService.GetMovieListAsync(null, 1);
            if (response.Successfull)
            {
                Movies = response.Data?.Items ?? new List<Movie>();
            }
        }
    }
}
