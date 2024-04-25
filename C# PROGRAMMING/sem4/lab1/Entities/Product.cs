using SQLite;

namespace lab1.Entities;

[Table("Products")]
public class Product
{
    [PrimaryKey, AutoIncrement, Indexed]
    [Column("ID")]
    public int ProductID { get; set; }
    public string Name { get; set; }
    [Indexed]
    public int BrandId { get; set; }
}