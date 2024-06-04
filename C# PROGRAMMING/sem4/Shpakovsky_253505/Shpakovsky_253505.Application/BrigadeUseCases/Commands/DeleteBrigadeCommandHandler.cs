using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Application.WorkUseCases.Commands;

namespace Shpakovsky_253505.Application.BrigadeUseCases.Commands
{
    public class DeleteBrigadeCommandHandler : IRequestHandler<DeleteBrigadeCommand, Brigade>
    {
        private readonly IUnitOfWork _unitOfWork;
        public DeleteBrigadeCommandHandler(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }
        public async Task<Brigade> Handle(DeleteBrigadeCommand request, CancellationToken cancellationToken)
        {
            await _unitOfWork.BrigadeRepository.DeleteAsync(request.brigade, cancellationToken);
            await _unitOfWork.SaveAllAsync();
            return request.brigade;
        }
    }
}
