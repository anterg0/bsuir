using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.WorkUseCases.Commands
{
    public class AddWorkCommandHandler : IRequestHandler<AddWorkCommand, Work>
    {
        private readonly IUnitOfWork _unitOfWork;
        public AddWorkCommandHandler(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }
        public async Task<Work> Handle(AddWorkCommand request, CancellationToken cancellationToken)
        {
            Work newTrainee = new Work(new Person(request.Name), request.DeadLine, request.Quality);
            if (request.GroupId.HasValue)
            {
                newTrainee.AddToBrigade(request.GroupId.Value);
            }
            await _unitOfWork.WorkRepository.AddAsync(newTrainee, cancellationToken);
            await _unitOfWork.SaveAllAsync();
            return newTrainee;
        }
    }
}
