using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.WorkUseCases.Queries
{
    public class GetWorksByGroupRequestHandler : IRequestHandler<GetWorksByGroupRequest, IEnumerable<Work>>
    {
        private IUnitOfWork _unitOfWork;

        public GetWorksByGroupRequestHandler(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }
        public async Task<IEnumerable<Work>> Handle(GetWorksByGroupRequest request, CancellationToken cancellationToken)
        {
            return await _unitOfWork.WorkRepository.ListAsync(t => t.BrigadeId == request.Id, cancellationToken);
        }

    }
}
