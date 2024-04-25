using SQLite;

namespace lab1.Entities;

[Table("Brands")]
public class Brand
{
    [PrimaryKey, AutoIncrement, Indexed]
    public int ID { get; set; }
    public string Name { get; set; }
    public override string ToString()
    {
        return Name;
    }
}