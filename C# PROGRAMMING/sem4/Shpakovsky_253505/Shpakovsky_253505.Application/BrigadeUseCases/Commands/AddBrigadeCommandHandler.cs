using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Application.BrigadeUseCases.Commands
{
    internal class AddBrigadeCommandHandler : IRequestHandler<AddBrigadeCommand, Brigade>
    {
        private readonly IUnitOfWork _unitOfWork;
        public AddBrigadeCommandHandler(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }
        public async Task<Brigade> Handle(AddBrigadeCommand request, CancellationToken cancellationToken)
        {
            Brigade newBrigade = new Brigade(request.Name, request.CommenceFrom, request.NumberOfPeople);
            newBrigade.Id = Random.Shared.Next(5, 100);
            
            await _unitOfWork.BrigadeRepository.AddAsync(newBrigade, cancellationToken);
            await _unitOfWork.SaveAllAsync();

            return newBrigade;
        }
    }
}
