using WEB_253505_Shpakovsky.UI.Services.Authentication;

namespace WEB_253505_Shpakovsky.UI.Services;

public class ApiFileService : IFileService
{
    private readonly HttpClient _httpClient;
    private readonly ITokenAccessor _tokenAccessor;
    public ApiFileService(HttpClient httpClient, ITokenAccessor tokenAccessor)
    {
        _httpClient = httpClient;
        _tokenAccessor = tokenAccessor;
    }

    public async Task<string> SaveFileAsync(IFormFile formFile)
    {
        var extension = Path.GetExtension(formFile.FileName);
        var newName = Path.ChangeExtension(Path.GetRandomFileName(), extension);

        var content = new MultipartFormDataContent
        {
            { new StreamContent(formFile.OpenReadStream()), "file", newName }
        };
        await _tokenAccessor.SetAuthorizationHeaderAsync(_httpClient);
        var response = await _httpClient.PostAsync("", content);
        response.EnsureSuccessStatusCode();

        return await response.Content.ReadAsStringAsync();
    }

    public async Task DeleteFileAsync(string fileName)
    {
        await _tokenAccessor.SetAuthorizationHeaderAsync(_httpClient);
        var response = await _httpClient.DeleteAsync($"?fileName={fileName}");
        response.EnsureSuccessStatusCode();
    }
}
