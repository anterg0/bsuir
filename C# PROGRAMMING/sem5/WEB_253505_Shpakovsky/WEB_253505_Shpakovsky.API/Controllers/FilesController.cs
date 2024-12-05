using Microsoft.AspNetCore.Mvc;

namespace WEB_253505_Shpakovsky.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class FilesController : ControllerBase
    {
        private readonly string _imagePath;

        public FilesController(IWebHostEnvironment webHost)
        {
            _imagePath = Path.Combine(webHost.WebRootPath, "Images");
        }

        [HttpPost]
        public async Task<IActionResult> SaveFile(IFormFile file)
        {
            if (file == null || file.Length == 0)
            {
                return BadRequest("Файл не передан или пуст.");
            }

            var extension = Path.GetExtension(file.FileName);
            var newName = Path.ChangeExtension(Path.GetRandomFileName(), extension);
            var filePath = Path.Combine(_imagePath, newName);

            // Сохраняем файл
            using var stream = new FileStream(filePath, FileMode.Create);
            await file.CopyToAsync(stream);

            var fileUrl = $"{Request.Scheme}://{Request.Host}/Images/{newName}";
            return Ok(fileUrl);
        }

        [HttpDelete]
        public IActionResult DeleteFile(string fileName)
        {
            var filePath = Path.Combine(_imagePath, fileName);
            if (System.IO.File.Exists(filePath))
            {
                System.IO.File.Delete(filePath);
                return Ok("Файл удалён.");
            }

            return NotFound("Файл не найден.");
        }
    }
}