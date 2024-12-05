namespace WEB_253505_Shpakovsky.UI.Services;

public interface IFileService
{
    Task<string> SaveFileAsync(IFormFile formFile);
    Task DeleteFileAsync(string fileName);
}
