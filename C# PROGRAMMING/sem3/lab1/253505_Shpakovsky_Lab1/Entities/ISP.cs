using collections;

namespace _253505_Shpakovsky_Lab1.Entities;

public class ISP
{
    private MyCustomCollection<Client> clientList;
    private MyCustomCollection<Tariff> tariffList;

    public ISP()
    {
        clientList = new MyCustomCollection<Client>();
        tariffList = new MyCustomCollection<Tariff>();
    }

    public void AddClient(Client newClient)
    {
        clientList.Add(newClient);
    }

    public void AddTariff(Tariff newTariff)
    {
        tariffList.Add(newTariff);
    }

    public void SetClientTraffic(Client client, decimal traffic)
    {
        while (clientList.Current() != client) clientList.Next();
        clientList.Current().SetTraffic(traffic);
        clientList.Reset();
    }

    public decimal EvalTariff(Tariff tariff)
    {
        Tariff currentTariff = null;
        while (tariffList.Current() != tariff)
        {
            if (tariffList.Current() == null) throw new InvalidOperationException("There's no such tariff.");
            tariffList.Next();
        }

        currentTariff = tariffList.Current();
        int count = 0;
        decimal sumTraffic = 0;
        while (count != clientList.Count)
        {
            count++;
            MyCustomCollection<Tariff> clientTariffs = clientList.Current().GetTariffList();
            Client currentClient = clientList.Current();
            int tariffCount = 0;
            bool validClient = false;
            while (tariffCount != clientTariffs.Count)
            {
                if (currentTariff == clientTariffs.Current())
                {
                    validClient = true;
                    break;
                }
                tariffCount++;
                clientTariffs.Next();
            }
            if (!validClient) continue;
            sumTraffic += currentClient.Traffic;
        }
        clientList.Reset();
        tariffList.Reset();
        return (sumTraffic * currentTariff.Price);
    }

    public Client GetRichClient()
    {
        int count = 0;
        decimal Max = 0;
        Client RichClient = null;
        while (count != clientList.Count)
        {
            count++;
            decimal totalPrice = 0;
            int tariffcount = 0;
            MyCustomCollection<Tariff> currentTariffList = clientList.Current().GetTariffList();
            while (tariffcount != currentTariffList.Count)
            {
                tariffcount++;
                totalPrice += currentTariffList.Current().Price;
            }

            decimal totalPayment = totalPrice * clientList.Current().Traffic;
            if (totalPayment > Max)
            {
                Max = totalPayment;
                RichClient = clientList.Current();
            }
        }

        return RichClient;
    }
}