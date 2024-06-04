using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.BrigadeUseCases.Queries
{
    public class GetAllBrigadesRequestHandler : IRequestHandler<GetAllBrigadesRequest, IEnumerable<Brigade>>
    {
        private IUnitOfWork _unitOfWork; 
        public GetAllBrigadesRequestHandler(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }

        public async Task<IEnumerable<Brigade>> Handle(GetAllBrigadesRequest request, CancellationToken cancellationToken)
        {
            return await _unitOfWork.BrigadeRepository.ListAllAsync(cancellationToken);
        }
    }
}
