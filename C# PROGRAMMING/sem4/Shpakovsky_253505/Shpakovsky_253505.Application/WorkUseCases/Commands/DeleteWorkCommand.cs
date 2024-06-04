using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.WorkUseCases.Commands
{
    public sealed record DeleteWorkCommand(Work work) : IRequest<Work>
    { }
}
