using collections;

namespace _253505_Shpakovsky_Lab1.Entities;

public class Client
{
    private string _name;
    private decimal _traffic;
    private MyCustomCollection<Tariff> _subscribedTariffs;

    public Client(string name)
    {
        this._name = name;
        this._traffic = 0;
        _subscribedTariffs = new MyCustomCollection<Tariff>();
    }

    public void SubToTariff(Tariff tariff)
    {
        _subscribedTariffs.Add(tariff);
    }

    public decimal EvalCost()
    {
        decimal totalPrice = 0;
        int count = 0;
        while (count != _subscribedTariffs.Count)
        {
            count++;
            totalPrice += _subscribedTariffs.Current().Price;
            _subscribedTariffs.Next();
        }
        _subscribedTariffs.Reset();
        return (totalPrice * _traffic);
    }

    public void SetTraffic(decimal traffic)
    {
        this._traffic = traffic;
    }

    public string Name
    {
        get
        {
            return _name;
        }
    }

    public decimal Traffic
    {
        get { return _traffic; }
    }

    public MyCustomCollection<Tariff> GetTariffList()
    {
        return _subscribedTariffs;
    }
}