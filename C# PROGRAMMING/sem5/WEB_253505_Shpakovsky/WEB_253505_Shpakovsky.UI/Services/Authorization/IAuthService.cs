namespace WEB_253505_Shpakovsky.UI.Services.Authorization;

public interface IAuthService
{
    Task<(bool Result, string ErrorMessage)> RegisterUserAsync(string email, string password, IFormFile? avatar);
}