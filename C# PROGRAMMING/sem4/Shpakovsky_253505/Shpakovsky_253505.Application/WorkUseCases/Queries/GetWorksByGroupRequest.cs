using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Domain.Entities;

namespace Shpakovsky_253505.Application.WorkUseCases.Queries
{
    public sealed record GetWorksByGroupRequest(int Id) : IRequest<IEnumerable<Work>>
    { }

    
}
