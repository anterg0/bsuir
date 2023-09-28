using _253505_Shpakovsky_Lab1.Entities;
using collections;

Client j1 = new Client("Jane");
Client j2 = new Client("John");
Client j3 = new Client("Jerry");
ISP beltelecom = new ISP();
Tariff econom = new Tariff("Econom", 0.05M);
Tariff premium = new Tariff("Premium", 0.5M);
Journal journal = new Journal();

j1.SubToTariff(econom);
j2.SubToTariff(premium);
// j1.SubToTariff(premium);
j3.SubToTariff(premium);

beltelecom.TariffChange += journal.Log;
beltelecom.ClientChange += journal.Log;

beltelecom.AddClient(j1);
beltelecom.AddClient(j2);
beltelecom.AddClient(j3);
beltelecom.AddTariff(econom);
beltelecom.AddTariff(premium);

Console.WriteLine(journal.GetLogs());

beltelecom.TrafficSet += message => Console.WriteLine($"Traffic log: {message}");

beltelecom.SetClientTraffic(j1,8239465);
beltelecom.SetClientTraffic(j2,2756276);
beltelecom.SetClientTraffic(j3, 182637627);

MyCustomCollection<int> intCol = new MyCustomCollection<int>();
intCol.Add(1);
intCol.Add(2);
Console.WriteLine(intCol[2]);