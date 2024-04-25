using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using lab1.Entities;
using lab1.Services;
using SQLite;
namespace lab1.Services;

public class SQLiteService : IDbService
{
    private SQLiteConnection _database;

    public SQLiteService(string dbPath)
    {
        _database = new SQLiteConnection(dbPath);
        _database.CreateTable<Brand>();
        _database.CreateTable<Product>();
        Init();
    }

    public IEnumerable<Brand> GetBrands()
    {
        return _database.Table<Brand>().ToList();
    }

    public IEnumerable<Product> GetProducts(int brandId)
    {
        return _database.Table<Product>().Where(p => p.BrandId == brandId).ToList();
    }

    public void Init()
    {
        if (!_database.Table<Brand>().Any())
        {
            // Добавляем несколько брендов и продуктов для примера
           var brands = new List<Brand>
            {
                new Brand { Name = "Glamour Cosmetics" },
                new Brand { Name = "Radiant Beauty" },
                new Brand { Name = "Ethereal Elegance" },
                new Brand { Name = "Luxe Luxuries" },
                new Brand { Name = "Opulent Glam" }
            };

            var products = new List<Product>
            {
                new Product { Name = "Foundation", BrandId = 1 },
                new Product { Name = "Mascara", BrandId = 1 },
                new Product { Name = "Lipstick", BrandId = 1 },
                new Product { Name = "Eyeshadow Palette", BrandId = 1 },
                new Product { Name = "Blush", BrandId = 1 },
                new Product { Name = "Highlighter", BrandId = 1 },
                new Product { Name = "Eyeliner", BrandId = 1 },
                new Product { Name = "Concealer", BrandId = 1 },
                new Product { Name = "Setting Powder", BrandId = 1 },
                new Product { Name = "Bronzer", BrandId = 1 },
                
                new Product { Name = "Lip Gloss", BrandId = 2 },
                new Product { Name = "Foundation Stick", BrandId = 2 },
                new Product { Name = "Eyebrow Pencil", BrandId = 2 },
                new Product { Name = "Setting Spray", BrandId = 2 },
                new Product { Name = "Eyelash Curler", BrandId = 2 },
                new Product { Name = "Contour Kit", BrandId = 2 },
                new Product { Name = "Face Primer", BrandId = 2 },
                new Product { Name = "Liquid Eyeliner", BrandId = 2 },
                new Product { Name = "Lip Balm", BrandId = 2 },
                new Product { Name = "Makeup Remover", BrandId = 2 },
                new Product { Name = "Scroll Test", BrandId = 2},
                new Product { Name = "Scroll Test", BrandId = 2},
                new Product { Name = "Scroll Test", BrandId = 2},
                
                new Product { Name = "Blush Palette", BrandId = 3 },
                new Product { Name = "Highlighter Palette", BrandId = 3 },
                new Product { Name = "Eyeshadow Primer", BrandId = 3 },
                new Product { Name = "Lip Stain", BrandId = 3 },
                new Product { Name = "Brow Gel", BrandId = 3 },
                new Product { Name = "Cream Contour", BrandId = 3 },
                new Product { Name = "Face Serum", BrandId = 3 },
                new Product { Name = "Makeup Sponge", BrandId = 3 },
                new Product { Name = "Eyeshadow Brush Set", BrandId = 3 },
                new Product { Name = "Lash Serum", BrandId = 3 },
                
                new Product { Name = "Liquid Foundation", BrandId = 4 },
                new Product { Name = "Blush Stick", BrandId = 4 },
                new Product { Name = "Glow Mist", BrandId = 4 },
                new Product { Name = "Lip Liner", BrandId = 4 },
                new Product { Name = "Magnetic Eyelashes", BrandId = 4 },
                new Product { Name = "Makeup Setting Powder", BrandId = 4 },
                new Product { Name = "Cream Highlighter", BrandId = 4 },
                new Product { Name = "Face Mask", BrandId = 4 },
                new Product { Name = "Eyeshadow Singles", BrandId = 4 },
                new Product { Name = "Lip Plumper", BrandId = 4 },
                
                new Product { Name = "BB Cream", BrandId = 5 },
                new Product { Name = "Liquid Lipstick", BrandId = 5 },
                new Product { Name = "Eyelash Extensions", BrandId = 5 },
                new Product { Name = "Brow Powder", BrandId = 5 },
                new Product { Name = "Makeup Brushes", BrandId = 5 },
                new Product { Name = "Powder Contour", BrandId = 5 },
                new Product { Name = "Facial Cleanser", BrandId = 5 },
                new Product { Name = "Eyeshadow Primer", BrandId = 5 },
                new Product { Name = "Lip Scrub", BrandId = 5 },
                new Product { Name = "Makeup Bag", BrandId = 5 }
            };

            _database.InsertAll(brands);
            _database.InsertAll(products);
        }
    }
}