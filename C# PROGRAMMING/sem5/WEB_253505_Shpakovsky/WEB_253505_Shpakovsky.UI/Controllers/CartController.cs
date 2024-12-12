using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using WEB_253505_Shpakovsky.Domain.Entities;
using WEB_253505_Shpakovsky.UI.Services;
using WEB_253505_Shpakovsky.UI.Extensions;

namespace WEB_253505_Shpakovsky.UI.Controllers
{
    public class CartController : Controller
    {
        private readonly IMovieService _productService;
        private readonly CartContainer _cart;

        public CartController(IMovieService productService, CartContainer cart)
        {
            _productService = productService;
            _cart = cart;
        }

        [HttpGet]
        [Authorize]
        public IActionResult Index()
        {
            return View(_cart);
        }

        [HttpPost]
        [Authorize]
        public async Task<ActionResult> Add(int id, string returnUrl)
        {
            var response = await _productService.GetMovieByIdAsync(id);
            if (response.Successfull && response.Data != null)
            {
                _cart.AddToCart(response.Data);
                // HttpContext.Session.Set("cart", _cart);
            }
            return Redirect(returnUrl);
        }

        [HttpPost]
        [Authorize]
        public ActionResult Remove(int id, string returnUrl)
        {
            _cart.RemoveItems(id);

            // HttpContext.Session.Set("cart", _cart);
            return Redirect(returnUrl);
        }

        [HttpPost]
        [Authorize]
        public ActionResult Clear(string returnUrl)
        {
            _cart.ClearAll();
            // HttpContext.Session.Set("cart", _cart);
            return Redirect(returnUrl);
        }
    }
}
