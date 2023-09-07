
enum TicketType {
    Economy,
    Business
}

class Customer {
    public string passportNumber;
    public string name;
    public string surname;
    public DateTime birthDate;

    public Customer(string passportNumber, string name, string surname, DateTime birthDate) {
        this.passportNumber = passportNumber;
        this.name = name;
        this.surname = surname;
        this.birthDate = birthDate;
    }
}

class Ticket {
    public Customer customer;
    public TicketType ticketType;
    public double ticketPrice;

    public Ticket(Customer customer, TicketType ticketType, double ticketPrice) {
        this.customer = customer;
        this.ticketType = ticketType;
        this.ticketPrice = ticketPrice;
    }
}

class AirportTicketManager {
    private List<Ticket> tickets = new List<Ticket>();
    private Dictionary<string, double> tariffs = new Dictionary<string, double>();

    public void AddTariff(string direction, double price) {
        tariffs.Add(direction, price);
    }

    public double CalculateTicketPrice(string direction, TicketType ticketType) {
        if (!tariffs.ContainsKey(direction)) {
            throw new ArgumentException("Tariff for direction not found");
        }

        double basePrice = tariffs[direction];
        double multiplier = ticketType == TicketType.Economy ? 1.0 : 1.5;

        return basePrice * multiplier;
    }

    public void RegisterTicket(Customer customer, string direction, TicketType ticketType) {
        double ticketPrice = CalculateTicketPrice(direction, ticketType);

        Ticket ticket = new Ticket(customer, ticketType, ticketPrice);

        tickets.Add(ticket);
    }

    public double CalculateTotalRevenue() {
        double totalRevenue = 0;

        foreach (Ticket ticket in tickets) {
            totalRevenue += ticket.ticketPrice;
        }

        return totalRevenue;
    }

    public double CalculateTotalCostByCustomer(Customer customer) {
        double totalCost = 0;

        foreach (Ticket ticket in tickets) {
            if (ticket.customer.passportNumber == customer.passportNumber) {
                totalCost += ticket.ticketPrice;
            }
        }

        return totalCost;
    }
}

class Program
{
    static void Main(string[] args)
    {
        AirportTicketManager ticketManager = new AirportTicketManager();

        ticketManager.AddTariff("New York", 1000);
        ticketManager.AddTariff("London", 800);
        ticketManager.AddTariff("Paris", 900);

        Customer customer1 = new Customer("1234567890", "John", "Doe", new DateTime(1990, 1, 1));
        Customer customer2 = new Customer("0987654321", "Jane", "Doe", new DateTime(1985, 2, 2));
        Customer customer3 = new Customer("1111111111", "Bob", "Smith", new DateTime(1970, 3, 3));

        ticketManager.RegisterTicket(customer1, "New York", TicketType.Economy);
        ticketManager.RegisterTicket(customer2, "London", TicketType.Business);
        ticketManager.RegisterTicket(customer3, "Paris", TicketType.Economy);
        ticketManager.RegisterTicket(customer1, "Paris", TicketType.Economy);

        double totalRevenue = ticketManager.CalculateTotalRevenue();
        double totalRevenueCust1 = ticketManager.CalculateTotalCostByCustomer(customer1);
        Console.WriteLine(totalRevenueCust1);
        Console.WriteLine(totalRevenue);
    }
}
