using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Domain.Entities;

namespace Shpakovsky_253505.Persistense.Repository
{
    public class FakeBrigadeRepository : IRepository <Brigade>
    {
        List<Brigade> _brigades;
        public FakeBrigadeRepository()
        {
            _brigades = new List<Brigade>();
            var brigade = new Brigade("Тест 1", DateTime.Now, 14);
            brigade.Id = 1;
            _brigades.Add(brigade);

            brigade = new Brigade("Тест 2", DateTime.Now.AddDays(5), 14);
            brigade.Id = 2;
            _brigades.Add(brigade);


        }

        public Task AddAsync(Brigade entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task DeleteAsync(Brigade entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task<Brigade> FirstOrDefaultAsync(Expression<Func<Brigade, bool>> filter, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task<Brigade> GetByIdAsync(int id, CancellationToken cancellationToken = default, params Expression<Func<Brigade, object>>[]? includesProperties)
        {
            throw new NotImplementedException();
        }

        public async Task<IReadOnlyList<Brigade>> ListAllAsync(CancellationToken cancellationToken = default)
        {
            return await Task.Run(() => _brigades);
        }

        public Task<IReadOnlyList<Brigade>> ListAsync(Expression<Func<Brigade, bool>>? filter, CancellationToken cancellationToken = default, params Expression<Func<Brigade, object>>[]? includesProperties)
        {
            throw new NotImplementedException();
        }

        public Task UpdateAsync(Brigade entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
    }

    public class FakeWorkRepository  : IRepository<Work>
    {
        List<Work> _works;
        public FakeWorkRepository()
        {
            _works= new List<Work>();
            int k = 1;
            for (int i = 1; i <= 2; i++)
                for (int j = 0; j < 10; j++)
                {
                    var work = new Work(new Person($"Work {k++}"), DateTime.Now.AddDays(-Random.Shared.Next(4)), j /2 * i );
                    work.AddToBrigade(i);
                    _works.Add(work);
                }
        }

        public Task AddAsync(Work entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task DeleteAsync(Work entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task<Work> FirstOrDefaultAsync(Expression<Func<Work, bool>> filter, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public Task<Work> GetByIdAsync(int id, CancellationToken cancellationToken = default, params Expression<Func<Work, object>>[]? includesProperties)
        {
            throw new NotImplementedException();
        }

        public Task<IReadOnlyList<Work>> ListAllAsync(CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }

        public async Task<IReadOnlyList<Work>> ListAsync(Expression<Func<Work, bool>> filter, 
                                                            CancellationToken cancellationToken = default, params Expression<Func<Work, 
            object>>[]? includesProperties)
        {
            var data = _works.AsQueryable();
            return data.Where(filter).ToList();
        }

        public Task UpdateAsync(Work entity, CancellationToken cancellationToken = default)
        {
            throw new NotImplementedException();
        }
    }
    
}

