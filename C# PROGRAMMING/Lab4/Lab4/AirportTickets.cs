namespace Lab4;

class AirportTicket {
    public string AirportName { get; set; }
    public float TicketPrice { get; set; }
    public int TotalSeats { get; set; }
    public int SoldTickets { get; set; }

    public AirportTicket(string airportName, float ticketPrice, int totalSeats, int soldTickets) {
        AirportName = airportName;
        TicketPrice = ticketPrice;
        TotalSeats = totalSeats;
        SoldTickets = soldTickets;
    }

    public float CalculateTotalSales() {
        return SoldTickets * TicketPrice;
    }

    public void UpdateTicketPrice(float newPrice) {
        TicketPrice = newPrice;
    }
}

class AirportTicketContainer {
    private List<AirportTicket> airportTickets;

    private static AirportTicketContainer instance = null;
    private static readonly object padlock = new object();

    AirportTicketContainer() {
        airportTickets = new List<AirportTicket>();
    }

    public static AirportTicketContainer Instance {
        get {
            lock (padlock) {
                if (instance == null) {
                    instance = new AirportTicketContainer();
                }
                return instance;
            }
        }
    }

    public void AddTicket(AirportTicket airportTicket) {
        airportTickets.Add(airportTicket);
    }

    public void RemoveTicket(AirportTicket airportTicket) {
        airportTickets.Remove(airportTicket);
    }

    public List<AirportTicket> GetTickets() {
        return airportTickets;
    }

    public AirportTicket GetTicketByName(string airportName) {
        return airportTickets.Find(ticket => ticket.AirportName == airportName);
    }

    public AirportTicket GetTicketByIndex(int index) {
        if (index >= 0 && index < airportTickets.Count) {
            return airportTickets[index];
        } else {
            return null;
        }
    }

    public void UpdateTicketPrice(string airportName, float newPrice) {
        AirportTicket airportTicket = GetTicketByName(airportName);
        if (airportTicket != null) {
            airportTicket.UpdateTicketPrice(newPrice);
        }
    }
}
