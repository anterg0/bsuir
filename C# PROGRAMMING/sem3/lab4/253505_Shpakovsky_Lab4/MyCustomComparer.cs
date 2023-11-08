namespace Lab4;

public class MyCustomComparer<T> : IComparer<T> where T : FoodProduct
{
    public int Compare(T x, T y)
    {
        return string.Compare(x.Name, y.Name);
    }
}