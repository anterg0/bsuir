namespace Lab4;

public class FileService : IFileService<FoodProduct>
{
    public IEnumerable<FoodProduct> ReadFile(string fileName)
    {
        using (BinaryReader reader = new BinaryReader(File.Open(fileName, FileMode.Open)))
        {
            while (reader.BaseStream.Position < reader.BaseStream.Length)
            {
                yield return new FoodProduct
                {
                    ID = reader.ReadInt32(),
                    Name = reader.ReadString(),
                    Calories = reader.ReadInt32(),
                    IsOrganic = reader.ReadBoolean()
                };
            }
        }
    }

    public void SaveData(IEnumerable<FoodProduct> data, string fileName)
    {
        using (BinaryWriter writer = new BinaryWriter(File.Open(fileName, FileMode.Create)))
        {
            foreach (var item in data)
            {
                writer.Write(item.ID);
                writer.Write(item.Name);
                writer.Write(item.Calories);
                writer.Write(item.IsOrganic);
            }
        }
    }
}