using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.WorkUseCases.Commands
{
    public class DeleteWorkCommandHandler : IRequestHandler<DeleteWorkCommand, Work>
    {
        private readonly IUnitOfWork _unitOfWork;
        public DeleteWorkCommandHandler(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }
        public async Task<Work> Handle(DeleteWorkCommand request, CancellationToken cancellationToken)
        {
            await _unitOfWork.WorkRepository.DeleteAsync(request.work, cancellationToken);
            await _unitOfWork.SaveAllAsync();
            return request.work;
        }
    }
}
