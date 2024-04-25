using lab1.Entities;

namespace lab1.Services;

public interface IDbService
{
    IEnumerable<Brand> GetBrands();
    IEnumerable<Product> GetProducts(int id);
    void Init();
}