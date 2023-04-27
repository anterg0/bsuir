namespace Lab4;
public class AirportTicketContainer
{
    private static AirportTicketContainer instance = null;
    private List<AirportTicket> tickets = new List<AirportTicket>();
    private int SoldTickets = 0;
    // public string AirportName { get; set; } 
    // public int TicketCost { get; set; }
    public int AvailableSeats { get; set; }

    private AirportTicketContainer() {}
    
    public static AirportTicketContainer GetInstance()
    {
        if (instance == null)
        {
            instance = new AirportTicketContainer();
        }

        return instance;
    }

    public void AddTicket(AirportTicket ticket)
    {
        if (SoldTickets < AvailableSeats)
        {
            tickets.Add(ticket);
            SoldTickets++;
        } else throw new ArgumentOutOfRangeException("AvailableSeats","Not enough available seats for that amount of tickets.");
    }
    
    public void AddTicket(AirportTicket ticket, int amount)
    {
        if (SoldTickets + amount <= AvailableSeats)
        {
            for (int i = 0; i < amount; i++) tickets.Add(ticket);
            SoldTickets += amount;
        } else throw new ArgumentOutOfRangeException("AvailableSeats","Not enough available seats for that amount of tickets.");
    }

    public void RemoveTicket(int index)
    {
        if (AvailableSeats != 0)
        {
            tickets.RemoveAt(index);
            SoldTickets--;
        }
    }

    public int TotalTicketsCost()
    {
        int sum = 0;
        foreach (AirportTicket ticket in tickets)
        {
            sum += ticket.Cost;
        }

        return sum;
    }
    
}

public class AirportTicket
{

    private string _airportName;
    private int _cost;
    
    public string AirportName
    {
        get { return _airportName; }
        set { _airportName = value; }
    }

    public int Cost
    {
        get { return _cost; }
        set { _cost = value; }
    }
}

public class TicketInterface
{
    public void IncreaseCost(AirportTicket ticket, int amount)
    {
        ticket.Cost += amount;
    }

    public int GetCost(AirportTicket ticket)
    {
        return ticket.Cost;
    }
    public void DecreaseCost(AirportTicket ticket, int amount)
    {
        ticket.Cost -= amount;
    }
    
    public void ChangeAirportName(AirportTicket ticket, string name)
    {
        ticket.AirportName = name;
    }

    public string GetAirportName(AirportTicket ticket)
    {
        return ticket.AirportName;
    }
}