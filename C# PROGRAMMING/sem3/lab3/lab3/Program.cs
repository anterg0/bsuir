using lab3.Entities;

ISP beltelecom = new ISP();
beltelecom.AddTariff("FastInternet", 100);
beltelecom.AddTariff("SuperFastInternet", 200);
beltelecom.AddTariff("UltraFastInternet", 300);
beltelecom.AddCustomer("Anton", 901293);
beltelecom.AddCustomer("Vlad", 2837);
beltelecom.AddCustomer("Ivan", 1923);
beltelecom.AddCustomer("Egor", 237882);
beltelecom.AddTariffToCustomer("Anton", "UltraFastInternet");
beltelecom.AddTariffToCustomer("Vlad", "FastInternet");
beltelecom.AddTariffToCustomer("Ivan", "SuperFastInternet");
beltelecom.AddTariffToCustomer("Egor", "UltraFastInternet");

Console.WriteLine($"Total traffic cost is: {beltelecom.GetTotalTrafficCost()}");
Console.WriteLine($"Customer with the most payment: {beltelecom.GetCustomerWithMaxPayment()}");
int count = 0;
foreach (var item in beltelecom.GetSortedTariffNamesByCost())
{
    Console.WriteLine($"{++count}. {item}");
}
var list = beltelecom.GetCustomerCountByTariff();
foreach (var item in list)
{
    Console.WriteLine($"Tariff: {item.Tariff}, Count: {item.Count}");
}