using Shpakovsky_253505.UI.ViewModels;

namespace Shpakovsky_253505.UI.Pages;

public partial class AddWork : ContentPage
{
	private AddWorkViewModel _viewModel;
	public AddWork(AddWorkViewModel viewModel = null)
	{
		InitializeComponent();
		_viewModel = viewModel;
		BindingContext = _viewModel;	
	}
}