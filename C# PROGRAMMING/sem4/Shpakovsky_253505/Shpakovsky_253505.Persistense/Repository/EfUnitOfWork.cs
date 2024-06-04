using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Domain.Entities;
using Shpakovsky_253505.Persistense.Data;

namespace Shpakovsky_253505.Persistense.Repository
{
    public class EfUnitOfWork : IUnitOfWork
    {
        private readonly AppDbContext _context;
        private readonly Lazy<IRepository<Brigade>> _brigadeRepository;
        private readonly Lazy<IRepository<Work>> _workRepository;

        public EfUnitOfWork(AppDbContext context)
        {
            _context = context;
            _brigadeRepository = new Lazy<IRepository<Brigade>>(() =>
            new EfRepository<Brigade>(context));
            _workRepository = new Lazy<IRepository<Work>>(() =>
            new EfRepository<Work>(context));
        }
        public IRepository<Brigade> BrigadeRepository => _brigadeRepository.Value;
        public IRepository<Work> WorkRepository => _workRepository.Value;
        public async Task CreateDataBaseAsync() => await _context.Database.EnsureCreatedAsync();
        public async Task DeleteDataBaseAsync() => await _context.Database.EnsureDeletedAsync();
        public async Task SaveAllAsync() => await _context.SaveChangesAsync();
    }

}
