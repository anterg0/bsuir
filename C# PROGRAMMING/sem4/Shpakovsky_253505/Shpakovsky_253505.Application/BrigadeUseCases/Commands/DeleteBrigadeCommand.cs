using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.BrigadeUseCases.Commands
{
    public sealed record DeleteBrigadeCommand(Brigade brigade) : IRequest<Brigade>
    { }
}
