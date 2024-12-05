namespace WEB_253505_Shpakovsky.Domain.Entities;

public class Movie
{
    public int ID { get; set; }
    public string Name { get; set; }
    public string Description { get; set; }
    public Genre? Category { get; set; }
    public int CategoryID { get; set; }
    public int Duration { get; set; }
    public double Rating { get; set; }
    public string? Image { get; set; }
    public string? MimeType { get; set; }
}
