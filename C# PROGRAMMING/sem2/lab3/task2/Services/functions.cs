namespace task2.Services;

public class Functions
{
    public double f(double z, double b)
    {
        double x;
        if (z <= 0)
        {
            x = Math.Pow(z,b) + Math.Abs(b / 2);
        }
        else
        {
            x = Math.Sqrt(z);
        }

        return  (1 / Math.Cos(x)) + Math.Log(Math.Tan(x / 2));
        //return result;
    }
}