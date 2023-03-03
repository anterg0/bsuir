using task2;

bool flag = true;
while (flag)
{
    Functions func = new Functions();
    bool flag1 = true;
    double z = 0, b = 0;
    while (flag1)
    {
        Console.WriteLine("Введите число z: ");
        try
        {
            z = Convert.ToDouble(Console.ReadLine());
        }
        catch (Exception)
        {
            Console.WriteLine("Неверный ввод. Попробуйте ещё раз.");
            continue;
        }

        flag1 = false;
    }

    if (z <= 0)
    {
        flag1 = true;
        while (flag1)
        {
            Console.WriteLine("Введите число b: ");
            try
            {
                b = Convert.ToDouble(Console.ReadLine());
            }
            catch (Exception)
            {
                Console.WriteLine("Неверный ввод. Попробуйте ещё раз.");
                continue;
            }

            flag1 = false;
        }
    }

    double result = func.f(z, b);
    Console.WriteLine("Результат вычисления: {0}", result);
    if (z > 0)
    {
        Console.WriteLine("Была выполнена ветка 2.");
    }
    else Console.WriteLine("Была выполнена ветка 1.");

    bool ch = true;
    while (ch)
    {
        Console.WriteLine("Продолжить (y) или закончить (n)? ");
        char choice = Convert.ToChar(Console.ReadLine());
        switch (choice)
        {
            case 'y':
                ch = false;
                break;
            case 'n':
                flag = false;
                ch = false;
                break;
            default:

                break;
        }
    }
}