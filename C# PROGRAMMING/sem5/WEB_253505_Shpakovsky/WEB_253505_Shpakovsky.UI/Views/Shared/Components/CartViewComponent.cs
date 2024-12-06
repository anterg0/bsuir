using Microsoft.AspNetCore.Mvc;
using WEB_253505_Shpakovsky.Domain.Entities;

namespace WEB_253505_Shpakovsky.UI.Components;

public class CartViewComponent : ViewComponent
{
    private CartContainer _cart;
    public CartViewComponent(CartContainer cart)
    {
        _cart = cart;
    }
    public IViewComponentResult Invoke()
    {
        var totalItems = _cart.CartItems.Sum(item => item.Value.Amount);
        var totalPrice = _cart.CartItems.Sum(item => item.Value.Amount * item.Value.Item.Duration);
        var cartInfo = new { TotalItems = totalItems, TotalPrice = totalPrice };
        return View(cartInfo);                   
    }
}