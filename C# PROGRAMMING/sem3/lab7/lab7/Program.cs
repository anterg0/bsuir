using System;
using System.Diagnostics;
using System.Threading;
using IntegrationLib;
IntegrationCalculator calculator = new IntegrationCalculator();

calculator.CalculationCompleted += (sender, e) =>
{
    lock (Console.Out)
    {
        Console.SetCursorPosition(0, Console.CursorTop);
        Console.Write(
            $"Поток {Thread.CurrentThread.ManagedThreadId}: Завершен с результатом: {e.Result}, Время выполнения: {e.ElapsedTime}ms\n");
    }
};

calculator.ProgressChanged += (sender, progress) =>
{
    lock (Console.Out)
    {
        Console.SetCursorPosition(0, Console.CursorTop);
        Console.Write($"Поток {Thread.CurrentThread.ManagedThreadId}: [");
        Console.Write(new string('=', progress / 2));
        Console.Write(new string(' ', 50 - progress / 2));
        Console.Write($"] {progress}%");
    }
};

Thread calculationThread = new Thread(calculator.CalculateIntegral);
calculationThread.Start();

Thread calculationThread2 = new Thread(calculator.CalculateIntegral);
calculationThread2.Start();

Thread calculationThread3 = new Thread(calculator.CalculateIntegral);
calculationThread3.Start();

Thread calculationThread4 = new Thread(calculator.CalculateIntegral);
calculationThread4.Start();

Thread calculationThread5 = new Thread(calculator.CalculateIntegral);
calculationThread5.Start();
