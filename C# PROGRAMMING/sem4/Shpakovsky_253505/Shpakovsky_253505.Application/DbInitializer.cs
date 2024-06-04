using Microsoft.Extensions.DependencyInjection;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application
{
    public static class DbInitializer
    {
        public static async Task Initialize(IServiceProvider services)
        {
            var unitOfWork = services.GetRequiredService<IUnitOfWork>();

            await unitOfWork.DeleteDataBaseAsync();
            await unitOfWork.CreateDataBaseAsync();

           
            var brigade1 = new Brigade("Стахановцы", DateTime.Now.AddDays(-9), 15);
            brigade1.Id = 1;
            await unitOfWork.BrigadeRepository.AddAsync(brigade1);

            var brigade2 = new Brigade("Передовики", DateTime.Now.AddDays(-7).AddHours(-2), 10);
            brigade2.Id = 2;
            await unitOfWork.BrigadeRepository.AddAsync(brigade2);

            var brigade3 = new Brigade("Ye", DateTime.Now.AddDays(-5), 15);
            brigade3.Id = 3;
            await unitOfWork.BrigadeRepository.AddAsync(brigade3);

            var brigade4 = new Brigade("Yo", DateTime.Now.AddDays(-12), 31);
            brigade4.Id = 4;
            await unitOfWork.BrigadeRepository.AddAsync(brigade4);

            await unitOfWork.SaveAllAsync();

            int k = 1;
            for (int i =  1; i <= 4; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    var work = new Work(new Person($"Work {k++}"), DateTime.Now.AddDays(-Random.Shared.Next(4)), Random.Shared.Next(2,10));
                    work.AddToBrigade(i);
                    await unitOfWork.WorkRepository.AddAsync(work);
                }
            }
            

            await unitOfWork.SaveAllAsync();

        }

    }
}
