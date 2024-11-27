using Microsoft.AspNetCore.Mvc;
using WEB_253505_Shpakovsky.API.Services;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class GenresController : ControllerBase
    {
        private readonly IGenreService _genreService;

        public GenresController(IGenreService genreService)
        {
            _genreService = genreService;
        }

        [HttpGet]
        public async Task<ActionResult<ResponseData<List<Genre>>>> GetGenres()
        {
            var result = await _genreService.GetGenreListAsync();
            if (!result.Successfull)
            {
                return BadRequest(result.ErrorMessage);
            }
            return Ok(result);
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<ResponseData<Genre>>> GetGenre(int id)
        {
            var result = await _genreService.GetGenreByIdAsync(id);
            if (!result.Successfull)
            {
                return NotFound(result.ErrorMessage);
            }
            return Ok(result);
        }
    }
}