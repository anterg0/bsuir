using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Persistense.Data;

namespace Shpakovsky_253505.Persistense.Repository
{
    public class FakeUnitOfWork : IUnitOfWork
    {
        private readonly Lazy<IRepository<Brigade>> _brigadeRepository;
        private readonly Lazy<IRepository<Work>> _workRepository;

        public FakeUnitOfWork()
        {
            _brigadeRepository = new Lazy<IRepository<Brigade>>(() =>
            new FakeBrigadeRepository());
            _workRepository = new Lazy<IRepository<Work>>(() =>
            new FakeWorkRepository());
        }
        public IRepository<Brigade> BrigadeRepository
        => _brigadeRepository.Value;
        public IRepository<Work> WorkRepository
         => _workRepository.Value;
        public async Task CreateDataBaseAsync() =>
         throw new NotImplementedException();
        public async Task DeleteDataBaseAsync() =>
         throw new NotImplementedException();
        public async Task SaveAllAsync() =>
         throw new NotImplementedException();
    }
    
    
}
