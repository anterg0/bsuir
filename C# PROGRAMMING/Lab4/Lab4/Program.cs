using Lab4;

Random rand = new Random();
AirportTicketContainer container = AirportTicketContainer.GetInstance();
AirportTicket ticket = new AirportTicket();
TicketInterface inter = new TicketInterface();

inter.IncreaseCost(ticket,1000);
Console.WriteLine(inter.GetCost(ticket));
inter.IncreaseCost(ticket, rand.Next(3001));
inter.ChangeAirportName(ticket,"Belavia");

container.AvailableSeats = 376;
container.AddTicket(ticket, 375);

Console.WriteLine(inter.GetCost(ticket));
Console.WriteLine(container.TotalTicketsCost());

AirportTicketContainer con2 = AirportTicketContainer.GetInstance();

Console.WriteLine(con2.TotalTicketsCost());
Console.WriteLine(container.TotalTicketsCost());

