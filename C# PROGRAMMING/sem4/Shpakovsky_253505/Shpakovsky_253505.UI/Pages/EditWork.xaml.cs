using Shpakovsky_253505.UI.ViewModels;

namespace Shpakovsky_253505.UI.Pages;

public partial class EditWork : ContentPage
{
    private EditWorkViewModel _ViewModel;
    public EditWork(EditWorkViewModel viewModel)
    {
        InitializeComponent();
        _ViewModel = viewModel;
        BindingContext = _ViewModel;
    }
}