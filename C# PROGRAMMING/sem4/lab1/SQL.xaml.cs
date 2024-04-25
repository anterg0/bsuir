using System;
using System.Collections.Generic;
using Microsoft.Maui.Controls;
using lab1.Entities;
using lab1.Services;

namespace lab1
{
    public partial class SQL : ContentPage
    {
        private static string dbPath = Path.Combine(FileSystem.AppDataDirectory, "test.db");
        private readonly IDbService _dbService = new SQLiteService(dbPath);
        
        public List<Brand> Brands { get; set; }
        public List<Product> Products { get; set; }
        
        public SQL()
        {
            InitializeComponent();
        }
        
        private void BrandPicker_Loaded(object sender, EventArgs e)
        {
            Brands = new List<Brand>(_dbService.GetBrands());
            Products = new List<Product>();
            
            BrandPicker.ItemsSource = Brands;
            
            if (BrandPicker.ItemsSource != null && Brands.Count > 0)
            {
                BrandPicker.SelectedIndex = 0;
            }
        }
        
        private void BrandPicker_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (BrandPicker.SelectedItem is Brand selectedBrand)
            {
                Products = new List<Product>(_dbService.GetProducts(selectedBrand.ID));
                ProductCollectionView.ItemsSource = Products;
            }
        }
    }
}