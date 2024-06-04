using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Application.BrigadeUseCases.Queries;
using Shpakovsky_253505.Application.BrigadeUseCases.Commands;
using Shpakovsky_253505.Application.WorkUseCases.Queries;
using Shpakovsky_253505.UI.Pages;

namespace Shpakovsky_253505.UI.ViewModels
{
    public partial class BrigadesViewModel : ObservableObject
    {
        private readonly IMediator _mediator;
        public BrigadesViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }
        public ObservableCollection<Brigade> Brigades { get; set; } = new();
        public ObservableCollection<Work> Works { get; set; } = new();

        [ObservableProperty]
        Brigade selectedBrigade;

        [RelayCommand]
        async Task ShowDetails(Work work) => await GotoDetailsPage(work);

        [RelayCommand]
        async Task UpdateBrigadesList() => await GetBrigades();

        [RelayCommand]
        async Task UpdateWorksList() => await GetWorks();

        [RelayCommand]
        async Task AddBrigade() => await GoToAddBrigade();

        [RelayCommand]
        async Task AddWork() => await GoToAddWork();

        [RelayCommand]
        async Task DeleteBrigade() => await Delete();

        private async Task GotoDetailsPage(Work work)
        {
            IDictionary<string, object> parameters = new Dictionary<string, object>()
            {
                { "Work", work }
            };
            await Shell.Current.GoToAsync(nameof(Details), parameters);
        }
        public async Task GetWorks()
        {
            if (SelectedBrigade != null)
            {
                var works = await _mediator.Send(new GetWorksByGroupRequest(SelectedBrigade.Id)); //
                await MainThread.InvokeOnMainThreadAsync(() =>
                {
                    Works.Clear();
                    foreach (var work in works)
                        Works.Add(work);
                });

            }
        }

        public async Task GetBrigades()
        {
            var brigades = await _mediator.Send(new GetAllBrigadesRequest());
            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                //Brigades = new ObservableCollection<Brigade>();
                Brigades.Clear(); ///////////

                foreach (var brigade in brigades)
                {
                    Brigades.Add(brigade);
                }
            });
        }
        public async Task GoToAddBrigade()
        {
            await Shell.Current.GoToAsync(nameof(AddBrigade));
        }

        public async Task GoToAddWork()
        {
            if (SelectedBrigade != null)
            {
                IDictionary<string, object> parametrs = new Dictionary<string, object>()
                {
                    {"Brigade", SelectedBrigade }
                };
                await Shell.Current.GoToAsync(nameof(AddWork), parametrs);
            }
        }

        public async Task Delete()
        {

            if (SelectedBrigade != null)
            {
                bool deleteConfirmed = await App.Current.MainPage.DisplayAlert("Подтверждение",
                    "Вы уверены, что хотите удалить выбранную бригаду?", "Да", "Отмена");

                if (deleteConfirmed)
                {
                    await _mediator.Send(new DeleteBrigadeCommand(SelectedBrigade));
                    /*var brigades = await _mediator.Send(new GetAllBrigadesRequest());
                    await MainThread.InvokeOnMainThreadAsync(() =>
                    {
                        Brigades.Clear();

                        foreach (var brigade in brigades)
                        {
                            Brigades.Add(brigade);
                        }
                    });*/
                    await Shell.Current.GoToAsync("..");
                }
            }
            else
            {
                await App.Current.MainPage.DisplayAlert("Ошибка", "Выберите бригаду", "OK");
            }
        }
    }
}
