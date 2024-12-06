namespace WEB_253505_Shpakovsky.UI.Services.Authentication;

public interface ITokenAccessor
{
    Task<string> GetAccessTokenAsync();
    Task SetAuthorizationHeaderAsync(HttpClient httpClient);
}