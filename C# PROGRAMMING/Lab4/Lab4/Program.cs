using Lab4;

Random rand = new Random();
AirportTicketContainer container = AirportTicketContainer.GetInstance();
AirportTicket ticket = new AirportTicket();
TicketController control = new TicketController();

control.IncreaseCost(ticket,1000);
Console.WriteLine(control.GetCost(ticket));
control.IncreaseCost(ticket, rand.Next(3001));
control.ChangeAirportName(ticket,"Belavia");

container.AvailableSeats = 376;
container.AddTicket(ticket, 375);

Console.WriteLine(control.GetCost(ticket));
Console.WriteLine(container.TotalTicketsCost());

AirportTicketContainer con2 = AirportTicketContainer.GetInstance();

Console.WriteLine(con2.TotalTicketsCost());
Console.WriteLine(container.TotalTicketsCost());

