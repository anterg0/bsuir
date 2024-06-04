using Shpakovsky_253505.UI.ViewModels;

namespace Shpakovsky_253505.UI.Pages;

public partial class AddBrigade : ContentPage
{
	private AddBrigadeViewModel _viewModel;
	public AddBrigade(AddBrigadeViewModel viewModel)
	{
		InitializeComponent();
		_viewModel = viewModel;
		BindingContext = _viewModel;
	}

}