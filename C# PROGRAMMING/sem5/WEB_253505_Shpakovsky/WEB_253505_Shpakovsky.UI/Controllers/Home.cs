using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_253505_Shpakovsky.UI.Models;

namespace WEB_253505_Shpakovsky.UI.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            var items = new List<ListDemo>
            {
                new ListDemo { Id = 1, Name = "Опция 1" },
                new ListDemo { Id = 2, Name = "Опция 2" },
                new ListDemo { Id = 3, Name = "Опция 3" }
            };
            
            ViewBag.ItemList = new SelectList(items, "Id", "Name");
            return View();
        }
    }
}