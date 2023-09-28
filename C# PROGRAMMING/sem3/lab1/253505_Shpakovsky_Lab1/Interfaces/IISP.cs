namespace inter;
using _253505_Shpakovsky_Lab1.Entities;

public interface IISP
{
    void AddClient(Client client);
    void AddTariff(Tariff tariff);
    void SetClientTraffic(Client client, decimal traffic);
    decimal EvalTariff(Tariff tariff);
    Client GetRichClient();
    decimal GetTotalPaymentForAllTraffic();
    
}