namespace lab8;

public interface ITariff
{
    string Dest { get; }
    int Price { get; }
}

public interface IDiscounted : ITariff
{
    int Discount { get; }
}

public class DiscountedTariff : IDiscounted
{
    public string Dest { get; }
    public int Price { get; }
    public int Discount { get; }

    public DiscountedTariff(string dest, int price, int disc)
    {
        Dest = dest;
        Price = price;
        Discount = disc;
    }
}

public class Tariff : ITariff
{
    public string Dest { get; }
    public int Price { get; }

    public Tariff(string dest, int price)
    {
        Dest = dest;
        Price = price;
    }
}

public interface IAirport
{
    void AddTariff(ITariff tariff);
    ITariff MaxPriceTariff();
}

public class Airport : IAirport
{
    private List<ITariff> tariffs;

    public Airport()
    {
        tariffs = new List<ITariff>();
    }

    public void AddTariff(ITariff tariff)
    {
        tariffs.Add(tariff);
    }

    public ITariff MaxPriceTariff()
    {
        if (tariffs.Count == 0) return null;
        ITariff maxPrice = tariffs[0];
        foreach (var tariff in tariffs)
        {
            if (tariff.Price > maxPrice.Price) maxPrice = tariff;
        }

        return maxPrice;
    }
}