namespace WEB_253505_Shpakovsky.Domain.Models;

public class ResponseData<T>
{
    // Запрашиваемые данные
    public T? Data { get; set; }
    
    // Признак успешного завершения запроса
    public bool Successfull { get; set; } = true;
    
    // Сообщение в случае ошибки
    public string? ErrorMessage { get; set; }

    /// <summary>
    /// Получить успешный ответ
    /// </summary>
    public static ResponseData<T> Success(T data)
    {
        return new ResponseData<T> { Data = data };
    }

    /// <summary>
    /// Получить ошибочный ответ
    /// </summary>
    public static ResponseData<T> Error(string message, T? data = default)
    {
        return new ResponseData<T> { ErrorMessage = message, Successfull = false, Data = data };
    }
}
