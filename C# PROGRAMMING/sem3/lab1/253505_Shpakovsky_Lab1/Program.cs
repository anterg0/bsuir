using _253505_Shpakovsky_Lab1.Entities;

Client j1 = new Client("Jane");
Client j2 = new Client("John");
Client j3 = new Client("Jerry");
ISP beltelecom = new ISP();
Tariff econom = new Tariff("Econom", 0.05M);
Tariff premium = new Tariff("Premium", 0.5M);
j1.SubToTariff(econom);
j2.SubToTariff(premium);
// j1.SubToTariff(premium);
j3.SubToTariff(premium);

beltelecom.AddClient(j1);
beltelecom.AddClient(j2);
beltelecom.AddClient(j3);
beltelecom.AddTariff(econom);
beltelecom.AddTariff(premium);


beltelecom.SetClientTraffic(j1,8239465);
beltelecom.SetClientTraffic(j2,2756276);
beltelecom.SetClientTraffic(j3, 182637627);
Client richClient = beltelecom.GetRichClient();
Console.WriteLine("Client {0} has the highest total payment.", richClient.Name);

Console.WriteLine("Premium tariff total payment is {0}", beltelecom.EvalTariff(premium));

Console.WriteLine("Econom tariff total payment is {0}", beltelecom.EvalTariff(econom));

Console.WriteLine("Jane's total payment is {0}\nJohn's total payment is {1}\nJerry's total payment is {2}", j1.EvalCost(), j2.EvalCost(), j3.EvalCost());

Console.WriteLine("Total payment for all traffic: {0}", beltelecom.GetTotalPaymentForAllTraffic());