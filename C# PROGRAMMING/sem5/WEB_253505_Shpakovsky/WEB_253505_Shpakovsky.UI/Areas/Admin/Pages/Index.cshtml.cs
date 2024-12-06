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
        public int CurrentPage { get; set; }
        public int TotalPages { get; set; }


        public async Task OnGetAsync(int pageNo = 1)
        {
            CurrentPage = pageNo;

            var response = await _movieService.GetMovieListAsync(null, pageNo);
            if (response.Successfull && response.Data != null)
            {
                Movies = response.Data.Items ?? new List<Movie>();
                TotalPages = response.Data.TotalPages;
            }
        }
    }
}
