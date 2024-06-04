using CommunityToolkit.Maui;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.UI.Pages;
using Shpakovsky_253505.UI.ViewModels;

namespace Shpakovsky_253505.UI.Services
{
    public static class DependencyInjection
    {
        public static IServiceCollection RegisterPages(this IServiceCollection services)
        {
            services
                .AddTransient<Brigades>()
                .AddTransient<Details>()
                .AddTransient<AddBrigade>()
                .AddTransient<EditWork>()
                .AddTransient<AddWork>();
            return services;
        }

        public static IServiceCollection RegisterViewModels(this IServiceCollection services)
        {
            services
                .AddTransient<BrigadesViewModel>()
                .AddTransient<DetailsViewModel>()
                .AddTransient<AddBrigadeViewModel>()
                .AddTransient<EditWorkViewModel>()
                .AddTransient<AddWorkViewModel>();
            return services;
        }
    }
}