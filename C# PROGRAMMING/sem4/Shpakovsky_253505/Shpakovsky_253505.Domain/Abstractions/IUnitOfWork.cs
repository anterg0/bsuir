using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Domain.Entities;

namespace Shpakovsky_253505.Domain.Abstractions
{
        public interface IUnitOfWork
        {
            IRepository<Brigade> BrigadeRepository { get; }
            IRepository<Work> WorkRepository { get; }
            public Task SaveAllAsync();
            public Task DeleteDataBaseAsync();
            public Task CreateDataBaseAsync();
        }
}
