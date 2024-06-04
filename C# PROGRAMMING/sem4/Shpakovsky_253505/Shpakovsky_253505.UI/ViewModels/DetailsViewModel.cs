using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Shpakovsky_253505.UI.Pages;
using Microsoft.Maui.Controls;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Application.WorkUseCases.Commands;

namespace Shpakovsky_253505.UI.ViewModels
{
    [QueryProperty(nameof(Work), nameof(Work))]
    public partial class DetailsViewModel : ObservableObject
    {
        IMediator _mediator;
        public DetailsViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }

        [ObservableProperty]
        Work work;

        [RelayCommand]
        async void Edit() => await GoToEditObjectPage();

        [RelayCommand]
        async void Delete() => await DeleteWork();

        public async Task GoToEditObjectPage()
        {
            IDictionary<string, object> parametrs = new Dictionary<string, object>()
            {
                { "Work", Work}
            };
            await Shell.Current.GoToAsync(nameof(EditWork), parametrs);
        }

        public async Task DeleteWork()
        {
            await _mediator.Send(new DeleteWorkCommand(Work));
            await Shell.Current.GoToAsync("..");
        }

    }
}
