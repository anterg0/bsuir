namespace WEB_253505_Shpakovsky.UI.Services;

public class ApiFileService : IFileService
{
    private readonly HttpClient _httpClient;

    public ApiFileService(HttpClient httpClient)
    {
        _httpClient = httpClient;
    }

    public async Task<string> SaveFileAsync(IFormFile formFile)
    {
        var extension = Path.GetExtension(formFile.FileName);
        var newName = Path.ChangeExtension(Path.GetRandomFileName(), extension);

        var content = new MultipartFormDataContent
        {
            { new StreamContent(formFile.OpenReadStream()), "file", newName }
        };

        var response = await _httpClient.PostAsync("", content);
        response.EnsureSuccessStatusCode();

        return await response.Content.ReadAsStringAsync();
    }

    public async Task DeleteFileAsync(string fileName)
    {
        var response = await _httpClient.DeleteAsync($"?fileName={fileName}");
        response.EnsureSuccessStatusCode();
    }
}
