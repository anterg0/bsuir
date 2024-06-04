using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.DependencyInjection;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Persistense.Data;
using Shpakovsky_253505.Persistense.Repository;

namespace Shpakovsky_253505.Persistense
{
    public static class DependencyInjection
    {
        public static IServiceCollection AddPersistence(this IServiceCollection services)
        {
            services.AddSingleton<IUnitOfWork, EfUnitOfWork>();
            return services;
        }
        public static IServiceCollection AddPersistence(this IServiceCollection services, DbContextOptions options)
        {
            services.AddPersistence()
                .AddSingleton<AppDbContext>(
                    new AppDbContext((DbContextOptions<AppDbContext>)options));
            return services;
        }

    }
}
