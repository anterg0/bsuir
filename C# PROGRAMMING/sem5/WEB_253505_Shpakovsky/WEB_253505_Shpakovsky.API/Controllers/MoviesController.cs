using Microsoft.AspNetCore.Mvc;
using WEB_253505_Shpakovsky.API.Services;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.Domain.Models;

namespace WEB_253505_Shpakovsky.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class MoviesController : ControllerBase
    {
        private readonly IMovieService _movieService;

        public MoviesController(IMovieService movieService)
        {
            _movieService = movieService;
        }

        [HttpGet]
        public async Task<ActionResult<ResponseData<ListModel<Movie>>>> GetAllMovies(int pageNo = 1)
        {
            var result = await _movieService.GetMovieListAsync(null, pageNo); // null для всех категорий
            if (!result.Successfull)
            {
                return BadRequest(result.ErrorMessage);
            }
            return Ok(result);
        }

        [HttpGet("genre/{categoryNormalizedName}")]
        public async Task<ActionResult<ResponseData<ListModel<Movie>>>> GetMoviesByCategory(string categoryNormalizedName, int pageNo = 1)
        {
            var result = await _movieService.GetMovieListAsync(categoryNormalizedName, pageNo);
            if (!result.Successfull)
            {
                return BadRequest(result.ErrorMessage);
            }
            return Ok(result);
        }

        [HttpGet("{id}")]
        public async Task<ActionResult<ResponseData<Movie>>> GetMovie(int id)
        {
            var result = await _movieService.GetMovieByIdAsync(id);
            if (!result.Successfull)
            {
                return NotFound(result.ErrorMessage);
            }
            return Ok(result);
        }

        [HttpPut("{id}")]
        public async Task<IActionResult> PutMovie(int id, [FromForm] Movie movie, [FromForm] IFormFile? formFile)
        {
            try
            {
                await _movieService.UpdateMovieAsync(id, movie, formFile);
                return NoContent();
            }
            catch (KeyNotFoundException ex)
            {
                return NotFound(ex.Message);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }

        [HttpPost]
        public async Task<ActionResult<ResponseData<Movie>>> PostMovie([FromForm] Movie movie, [FromForm] IFormFile? formFile)
        {
            var result = await _movieService.CreateMovieAsync(movie, formFile);
            if (!result.Successfull)
            {
                return BadRequest(result.ErrorMessage);
            }
            return CreatedAtAction("GetMovie", new { id = result.Data!.ID }, result.Data);
        }

        [HttpDelete("{id}")]
        public async Task<IActionResult> DeleteMovie(int id)
        {
            try
            {
                await _movieService.DeleteMovieAsync(id);
                return NoContent();
            }
            catch (KeyNotFoundException ex)
            {
                return NotFound(ex.Message);
            }
            catch (Exception ex)
            {
                return BadRequest(ex.Message);
            }
        }
    }
}
