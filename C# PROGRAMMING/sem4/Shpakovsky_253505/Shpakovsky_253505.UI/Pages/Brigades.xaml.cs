using Shpakovsky_253505.UI.ViewModels;

namespace Shpakovsky_253505.UI.Pages;

public partial class Brigades : ContentPage
{
    private BrigadesViewModel _brigadesViewModel;
    public Brigades(BrigadesViewModel viewModel)
    {
		InitializeComponent();
        _brigadesViewModel = viewModel;
		BindingContext = _brigadesViewModel;
	}
}