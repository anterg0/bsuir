using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Domain.Entities;

namespace Shpakovsky_253505.Persistense.Data
{
    public class AppDbContext : DbContext
    {

        public AppDbContext(DbContextOptions<AppDbContext> dbContextOptions) : base(dbContextOptions)
        {
            Database.EnsureCreated();
        }

        public DbSet<Brigade> Brigades { get; set; }
        
        public DbSet<Work> Works { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Work>()
            .OwnsOne<Person>(t => t.PersonalData);

        }

    }
}
