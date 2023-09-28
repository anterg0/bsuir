using collections;

namespace _253505_Shpakovsky_Lab1.Entities;

public class ISP
{
    private MyCustomCollection<Client> clientList;
    private MyCustomCollection<Tariff> tariffList;

    public delegate void TariffChangeHandler(string message);

    public delegate void ClientChangeHandler(string message);

    public delegate void SetTrafficHandler(string message);

    public event SetTrafficHandler TrafficSet;

    public event TariffChangeHandler TariffChange;
    
    public event ClientChangeHandler ClientChange;

    public ISP()
    {
        clientList = new MyCustomCollection<Client>();
        tariffList = new MyCustomCollection<Tariff>();
    }

    public void AddClient(Client newClient)
    {
        clientList.Add(newClient);
        
        ClientChange?.Invoke($"Client {newClient.Name} was added.");
    }

    public void AddTariff(Tariff newTariff)
    {
        tariffList.Add(newTariff);
        TariffChange?.Invoke($"Tariff {newTariff.Name} was added.");
    }

    public void SetClientTraffic(Client client, decimal traffic)
    {
        clientList.Reset();
        while (clientList.Current() != client) clientList.Next();
        clientList.Current().SetTraffic(traffic);
        TrafficSet?.Invoke($"Traffic amount of {traffic} was set to client {clientList.Current().Name}");
        clientList.Reset();
    }

    public decimal EvalTariff(Tariff tariff)
    {
        tariffList.Reset();
        clientList.Reset();
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

            if (!validClient)
            {
                clientList.Next();
                clientTariffs.Reset();
                continue;
            }
            sumTraffic += currentClient.Traffic;
            clientTariffs.Reset();
            clientList.Next();
        }
        clientList.Reset();
        tariffList.Reset();
        return (sumTraffic * currentTariff.Price);
    }

    public Client GetRichClient()
    {
        tariffList.Reset();
        clientList.Reset();
        int count = 0;
        decimal Max = 0;
        Client RichClient = null;
        while (count != clientList.Count)
        {
            count++;
            // decimal totalPrice = 0;
            // int tariffcount = 0;
            // MyCustomCollection<Tariff> currentTariffList = clientList.Current().GetTariffList();
            // while (tariffcount != currentTariffList.Count)
            // {
            //     tariffcount++;
            //     totalPrice += currentTariffList.Current().Price;
            // }

            decimal totalPayment = clientList.Current().EvalCost();
            if (totalPayment > Max)
            {
                Max = totalPayment;
                RichClient = clientList.Current();
            }
            clientList.Next();
        }
        clientList.Reset();
        return RichClient;
    }

    public decimal GetTotalPaymentForAllTraffic()
    {
        tariffList.Reset();
        clientList.Reset();
        decimal totalpayment = 0;
        int count = 0;
        while (count != clientList.Count)
        {
            count++;
            totalpayment += clientList.Current().EvalCost();
            clientList.Next();
        }
        clientList.Reset();
        return totalpayment;
    }
}