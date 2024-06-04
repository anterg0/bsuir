using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.BrigadeUseCases.Queries
{
    public sealed record GetAllBrigadesRequest : IRequest<IEnumerable<Brigade>>
    {
    }

    
}
