namespace WEB_253505_Shpakovsky.Domain.Entities;

public class CartContainer
{
    public Dictionary<int, CartItem> CartItems { get; set; } = new();
    public virtual void AddToCart(Movie movie)
    {
        if (movie == null)
            throw new ArgumentNullException(nameof(movie));
        int id = movie.ID;
        if (CartItems.ContainsKey(id))
        {
            CartItems[id].Amount++;
        }
        else
        {
            CartItems[id] = new CartItem { Amount = 1, Item = movie };
        }
    }
    public virtual void RemoveItems(int id)
    {
        if (CartItems.ContainsKey(id))
        {
            var cartItem = CartItems[id];
            if (cartItem.Amount > 1)
            {
                cartItem.Amount--;
            }
            else
            {
                CartItems.Remove(id);
            }
        }
    }
    public virtual void ClearAll()
    {
        CartItems.Clear();
    }
    public int Count { get => CartItems.Sum(item => item.Value.Amount); }
    public double TotalDuration { get => CartItems.Sum(item => item.Value.Item.Duration * item.Value.Amount); }
}