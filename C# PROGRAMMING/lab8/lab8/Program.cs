using lab8;

IAirport airport = new Airport();

airport.AddTariff(new Tariff("New York", 500));
airport.AddTariff(new Tariff("London", 700));
airport.AddTariff(new DiscountedTariff("Paris", 1000, 200)); 

ITariff maxPriceTariff = airport.MaxPriceTariff();
if (maxPriceTariff != null)
{
    Console.WriteLine($"Destination: {maxPriceTariff.Dest}");
    Console.WriteLine($"Price: {maxPriceTariff.Price}");

    if (maxPriceTariff is IDiscounted discountedTariff)
    {
        Console.WriteLine($"Discount: {discountedTariff.Discount}");
    }
}
else
{
    Console.WriteLine("No tariffs found.");
}