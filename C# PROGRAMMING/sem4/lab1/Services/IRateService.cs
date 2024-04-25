using lab1.Entities;

namespace lab1.Services;

public interface IRateService
{
    IEnumerable<Rate> GetRates(DateTime date);
}