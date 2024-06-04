using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shpakovsky_253505.Application.WorkUseCases.Commands;
using Shpakovsky_253505.Application.BrigadeUseCases.Queries;

namespace Shpakovsky_253505.UI.ViewModels
{
    [QueryProperty(nameof(Work), nameof(Work))]
    public partial class EditWorkViewModel : ObservableObject
    {
        IMediator _mediator;
        public EditWorkViewModel(IMediator mediator)
        {
            _mediator = mediator;
        }

        public ObservableCollection<Brigade> _brigades { get; set; } = new();

        [ObservableProperty]
        Brigade selectedBrigade;

        [ObservableProperty]
        Work work;

        [ObservableProperty]
        string _date;

        [ObservableProperty]
        string _quality;
      
        [RelayCommand]
        async void EditWork() => await Edit();

        [RelayCommand]
        async void UpdateBrigadesList() => await GetAllBrigades();

        [RelayCommand]
        async void ChooseImage() => await LoadImage();

        public async Task Edit()
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

            if (dateTime != null && q <= 10 && q > 0 && Work != null)
            {
                Work.ChangeDate(dateTime);
                Work.ChangeQualityMark(q);
                if (selectedBrigade != null)
                {
                    Work.LeaveBrigade();
                    Work.AddToBrigade(selectedBrigade.Id);
                }
                await _mediator.Send(new EditWorkCommand(Work));
                await Shell.Current.GoToAsync("../..");
            }
            else if (_date == null && _quality != null)
            {
                Work.ChangeQualityMark(int.Parse(_quality));
                Work.ChangeDate(Work.DeadLine);
                if (selectedBrigade != null)
                {

                    Work.LeaveBrigade();
                    Work.AddToBrigade(selectedBrigade.Id);
                }
                await _mediator.Send(new EditWorkCommand(Work));
                await Shell.Current.GoToAsync("../..");
            }
            else if (_date != null && _quality == null && DateTime.TryParse(_date, out DateTime date2)) 
            {
                Work.ChangeQualityMark((int)Work.Quality);
                Work.ChangeDate(date2);
                if (selectedBrigade != null)
                {
                    Work.LeaveBrigade();
                    Work.AddToBrigade(selectedBrigade.Id);
                }
                await _mediator.Send(new EditWorkCommand(Work));
                await Shell.Current.GoToAsync("../..");
            }
            else if (_date == null && _quality == null)
            {
                Work.ChangeQualityMark((int)Work.Quality);
                Work.ChangeDate(Work.DeadLine);
                if (selectedBrigade != null)
                {
                    Work.LeaveBrigade();
                    Work.AddToBrigade(selectedBrigade.Id);
                }
                await _mediator.Send(new EditWorkCommand(Work));
                await Shell.Current.GoToAsync("../..");
            }
            else
            {
                await App.Current.MainPage.DisplayAlert("Ошибка", "Введите данные корректно", "ОК");
            }
        }
        public async Task GetAllBrigades()
        {
            var brigades = await _mediator.Send(new GetAllBrigadesRequest());
            await MainThread.InvokeOnMainThreadAsync(() =>
            {
                _brigades.Clear();
                foreach (var author in brigades)
                    _brigades.Add(author);
            });
        }
        public async Task LoadImage()
        {
            var options = new PickOptions
            {
                PickerTitle = "Выберите фотографию",
                FileTypes = FilePickerFileType.Images
            };
            var result = await FilePicker.Default.PickAsync(options);
            if (result != null && Work != null)
            {
                // Генерация имени файла
                string targetFileName = "image";
                string file = Work.Id.ToString();
                targetFileName += file;
                int dotIndex = result.FileName.LastIndexOf('.');
                string fileFormat = result.FileName.Substring(dotIndex);
                targetFileName += fileFormat;

                // Генерация пути  
                string targetFile = Path.Combine(@"C:\4sem\ISP\Shpakovsky_253505\Shpakovsky_253505.UI\Resources\Images", targetFileName); //"C:\\Manager\\Manager.UI\\Resources\\Images"

                // Копирование изображения в директорию
                using var stream = await result.OpenReadAsync();
                using FileStream outputStream = File.OpenWrite(targetFile);
                await stream.CopyToAsync(outputStream);
            }
        }
    }
}

