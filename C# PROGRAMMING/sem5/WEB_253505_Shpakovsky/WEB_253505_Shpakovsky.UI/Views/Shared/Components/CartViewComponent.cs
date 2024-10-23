using Microsoft.AspNetCore.Mvc;

namespace WEB_253505_Shpakovsky.UI.Components;

public class CartViewComponent : ViewComponent
{
    public IViewComponentResult Invoke()
    {
        return View();
    }
}