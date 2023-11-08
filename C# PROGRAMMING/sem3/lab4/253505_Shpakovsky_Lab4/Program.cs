using Lab4;

string directoryName = "Shpakovsky_Lab4";
Directory.CreateDirectory(directoryName);

List<string> extensions = new List<string> { ".txt", ".rtf", ".dat", ".inf" };

Random random = new Random();
for (int i = 0; i < 10; i++)
{
    string extension = extensions[random.Next(extensions.Count)];
    string fileName = Path.Combine(directoryName, Path.ChangeExtension(Path.GetRandomFileName(), extension));
    File.Create(fileName).Close();
}

Console.WriteLine("Список файлов в папке:");
string[] files = Directory.GetFiles(directoryName);
foreach (string file in files)
{
    string extension = Path.GetExtension(file);
    string fileName = Path.GetFileName(file);
    Console.WriteLine($"Файл: {fileName} имеет расширение {extension}");
}

List<FoodProduct> products = new List<FoodProduct>
{
    new FoodProduct { ID = 1, Name = "Apple", Calories = 52, IsOrganic = true },
    new FoodProduct { ID = 2, Name = "Banana", Calories = 89, IsOrganic = true },
    new FoodProduct { ID = 3, Name = "Pizza", Calories = 285, IsOrganic = false },
    new FoodProduct { ID = 4, Name = "Carrot", Calories = 41, IsOrganic = true },
    new FoodProduct { ID = 5, Name = "Chocolate", Calories = 546, IsOrganic = false }
};

FileService fileService = new FileService();
string dataFileName = Path.Combine(directoryName, "data.dat");
fileService.SaveData(products, dataFileName);

string renamedFileName = Path.Combine(directoryName, "new_data.dat");
File.Move(dataFileName, renamedFileName);

List<FoodProduct> loadedProducts = fileService.ReadFile(renamedFileName).ToList();

loadedProducts = loadedProducts.OrderBy(p => p, new MyCustomComparer<FoodProduct>()).ToList();

Console.WriteLine("Исходная коллекция продуктов:");
foreach (var product in products)
{
    Console.WriteLine($"ID: {product.ID}, Name: {product.Name}, Calories: {product.Calories}, IsOrganic: {product.IsOrganic}");
}

Console.WriteLine("Сортированная коллекция продуктов:");
foreach (var product in loadedProducts)
{
    Console.WriteLine($"ID: {product.ID}, Name: {product.Name}, Calories: {product.Calories}, IsOrganic: {product.IsOrganic}");
}

loadedProducts = loadedProducts.OrderBy(p => p.Calories).ToList();

Console.WriteLine("Сортированная коллекция продуктов по калориям:");
foreach (var product in loadedProducts)
{
    Console.WriteLine($"ID: {product.ID}, Name: {product.Name}, Calories: {product.Calories}, IsOrganic: {product.IsOrganic}");
}

Directory.Delete(directoryName,true);