﻿using Microsoft.Extensions.DependencyInjection;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application
{
    public static class DependencyInjection
    {
        public static IServiceCollection AddApplication(this IServiceCollection services)
        {
            {
                services.AddMediatR(conf =>
                   conf.RegisterServicesFromAssembly(typeof(DependencyInjection).Assembly));
                return services;
            }
        }
    }
}
