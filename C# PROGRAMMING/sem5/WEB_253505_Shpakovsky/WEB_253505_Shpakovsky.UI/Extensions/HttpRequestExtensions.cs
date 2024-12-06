namespace WEB_253505_Shpakovsky.UI.Extensions;

public static class HttpRequestExtensions
    {
        public static bool IsAjaxRequest(this HttpRequest request)
        {
            return request.Headers["x-requested-with"].ToString().ToLower().Equals("xmlhttprequest");
        }
    }