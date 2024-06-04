using Shpakovsky_253505.UI.Pages;

namespace Shpakovsky_253505.UI;

public partial class AppShell : Shell
{
	public AppShell()
	{
        Routing.RegisterRoute(nameof(Details), typeof(Details));
        Routing.RegisterRoute(nameof(AddWork), typeof(AddWork));
        Routing.RegisterRoute(nameof(AddBrigade), typeof(AddBrigade));
        Routing.RegisterRoute(nameof(EditWork), typeof(EditWork));

		InitializeComponent();
    }
}
