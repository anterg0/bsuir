using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Application.WorkUseCases.Commands;

namespace Shpakovsky_253505.UI.ViewModels
{
    [QueryProperty(nameof(Brigade), nameof(Brigade))]
    public partial class AddWorkViewModel : ObservableObject
    {
        private IMediator _mediator;

        public AddWorkViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }

        [ObservableProperty]
        Brigade _brigade;

        [ObservableProperty]
        private string _name;

        [ObservableProperty]
        private string _quality;

        [ObservableProperty]
        private string _date;

        [RelayCommand]
        async void AddWork() => await AddNewWork();

        public async Task AddNewWork()
        {
            int q = 1;
            DateTime dateTime = DateTime.Now;

            if (int.TryParse(_quality, out int qual))
            {
                q = qual;
            }
            if (DateTime.TryParse(_date, out DateTime date))
            {
                dateTime = date;
            }
            if (_brigade != null)
            {
                if (q < 0 || q > 10)
                    await App.Current.MainPage.DisplayAlert("Ошибка", "Значение должно быть от 0 до 10", "Ок");
                else
                {
                    await _mediator.Send(new AddWorkCommand(_name, dateTime, q, _brigade.Id));
                    await Shell.Current.GoToAsync("..");
                }
            }
            else
            {
                await App.Current.MainPage.DisplayAlert("Ошибка", "Заполните все поля", "Ок");
            }
        }
    }
}
