using Microsoft.EntityFrameworkCore;
using WEB_253505_Shpakovsky.Domain.Entities;

namespace WEB_253505_Shpakovsky.API.Data;

public class AppDbContext : DbContext
{
    public AppDbContext(DbContextOptions<AppDbContext> options) : base(options) { }

    public DbSet<Movie> Movies { get; set; }
    
    public DbSet<Genre> Genres { get; set; }
}