using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using WEB_253505_Shpakovsky.Domain.Entities;

    public class MovieContext : DbContext
    {
        public MovieContext (DbContextOptions<MovieContext> options)
            : base(options)
        {
        }

        public DbSet<WEB_253505_Shpakovsky.Domain.Entities.Movie> Movie { get; set; } = default!;
    }
