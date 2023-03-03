using System.Globalization;
using task3;

bool flag = true;
while (flag)
{
    DateService bruh = new DateService();
    DateTime entDate = new DateTime();
    bool flag1 = true;
    while (flag1)
    {
        Console.Write("Enter a date (dd.mm.yyyy): ");
        try
        {
            entDate = DateTime.ParseExact(Console.ReadLine(), "dd.MM.yyyy", CultureInfo.InvariantCulture);
        }
        catch (Exception)
        {
            Console.WriteLine("Incorrent format. Try again.");
            continue;
        }

        flag1 = false;
    }

    Console.WriteLine("{0} is {1}.\nIt's {2} days from now.", entDate.Date.ToShortDateString(),
        bruh.GetDay(entDate.ToString()), Math.Abs(bruh.GetDaysSpan(entDate.Day, entDate.Month, entDate.Year)));
    bool choi = true;
    int choice;
    while (choi)
    {
    Console.WriteLine("1. Continue\n2. Exit");
    choice = Convert.ToInt32(Console.ReadLine());
    switch (choice)
        {
            case 1:
                choi = false;
                break;
            case 2:
                choi = false;
                flag = false;
                break;
            default:
                break;
        }
    }
}