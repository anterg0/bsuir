namespace task3;

public class DateService
{
    public string GetDay(string date)
    {
        DateTime dateTime = DateTime.Parse(date);
        return dateTime.DayOfWeek.ToString();
    }

    public int GetDaysSpan(int day, int month, int year)
    {
        DateTime currentDate = DateTime.Now.Date;
        DateTime specifiedDate = new DateTime(year, month, day);
        TimeSpan timeSpan = specifiedDate.Subtract(currentDate);
        return timeSpan.Days;
    }
}
