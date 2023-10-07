namespace lab3.Entities;

public class Customer
{
    public string Name { get; set; }
    public List<Tariff> Tariffs { get; set; }
    public decimal Traffic { get; set; }

    public Customer()
    {
        Tariffs = new List<Tariff>();
    }
}