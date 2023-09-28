namespace _253505_Shpakovsky_Lab1.Entities;

public class Tariff
{
    private string _name;
    private decimal _price;

    public Tariff(string name, decimal price)
    {
        this._name = name;
        this._price = price;
    }

    public string Name
    {
        get { return _name; }
    }
    
    public decimal Price
    {
        get { return _price; }
    }
}