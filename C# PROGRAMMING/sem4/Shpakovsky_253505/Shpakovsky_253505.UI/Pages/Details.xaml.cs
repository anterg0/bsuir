using Shpakovsky_253505.UI.ViewModels;

namespace Shpakovsky_253505.UI.Pages;

public partial class Details : ContentPage
{
    private DetailsViewModel _detailsViewModel;
    public Details(DetailsViewModel detailsViewModel)
	{
		InitializeComponent();
		_detailsViewModel = detailsViewModel;
		BindingContext = _detailsViewModel;
	}
}