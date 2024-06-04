using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Application.BrigadeUseCases.Commands;
using Shpakovsky_253505.Application.BrigadeUseCases.Queries;

namespace Shpakovsky_253505.UI.ViewModels
{
    public partial class AddBrigadeViewModel : ObservableObject
    {
        private IMediator _mediator;

        public AddBrigadeViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }

        [ObservableProperty]
        private string _brigadeName;

        [ObservableProperty]
        private string _brigadeDate;

        [ObservableProperty]
        private string _brigadeNumber;


        [RelayCommand]
        async void AddBrigade() => await AddNewBrigade();

        public async Task AddNewBrigade()
        {
            int brnmbr = 1;
            DateTime dateTime = DateTime.Now;

            if (int.TryParse(_brigadeNumber, out int nmbr))
            {
                brnmbr = nmbr;
            }
            if (DateTime.TryParse(_brigadeDate, out DateTime date))
            {
                dateTime = date;
            }
            if (_brigadeName != "" && _brigadeName != null)
            {
                var pos = new Brigade(_brigadeName, dateTime, brnmbr);
                await _mediator.Send(new AddBrigadeCommand(_brigadeName, dateTime, brnmbr));
                await Shell.Current.GoToAsync("..");
            }
            else
            {
                await App.Current.MainPage.DisplayAlert("Ошибка", "Введите данные", "ОК");
            }
        }
    }
}
