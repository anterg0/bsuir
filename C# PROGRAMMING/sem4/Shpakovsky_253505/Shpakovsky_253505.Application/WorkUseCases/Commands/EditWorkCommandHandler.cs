using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.WorkUseCases.Commands
{
    public class EditWorkCommandHandler : IRequestHandler<EditWorkCommand, Work>
    {
        private readonly IUnitOfWork _unitOfWork;
        public EditWorkCommandHandler(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }
        public async Task<Work> Handle(EditWorkCommand request, CancellationToken cancellationToken)
        {
            await _unitOfWork.WorkRepository.UpdateAsync(request.work, cancellationToken);
            await _unitOfWork.SaveAllAsync();
            return request.work;
        }
    }
}
