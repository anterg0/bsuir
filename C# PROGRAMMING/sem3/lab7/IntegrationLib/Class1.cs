using System;
using System.Diagnostics;
using System.Threading;

namespace IntegrationLib
{
    public class IntegrationCalculator
    {
        public static Semaphore semaphore = new Semaphore(2, 2);
        public event EventHandler<IntegrationResultEventArgs> CalculationCompleted;
        public event EventHandler<int> ProgressChanged;

        public void CalculateIntegral()
        {
            semaphore.WaitOne();
            Stopwatch stopwatch = new Stopwatch();
            stopwatch.Start();

            double result = 0.0;
            double step = 0.0001;
            int iterations = 100000;

            for (double x = 0; x < 1; x += step)
            {
                for (int i = 0; i < iterations; i++)
                {
                    double dummy = 2 * i * i;
                }

                result += Math.Sin((x + 1) / 2) * (1 - x);
                int progressPercentage = (int)((x / 1) * 100);

                OnProgressChanged(progressPercentage);
            }

            stopwatch.Stop();

            OnCalculationCompleted(new IntegrationResultEventArgs(result, stopwatch.ElapsedMilliseconds));
            semaphore.Release();
        }

        private void OnCalculationCompleted(IntegrationResultEventArgs e)
        {
            CalculationCompleted?.Invoke(this, e);
        }

        private void OnProgressChanged(int progress)
        {
            ProgressChanged?.Invoke(this, progress);
        }

    }

    public class IntegrationResultEventArgs : EventArgs
    {
        public double Result { get; }
        public long ElapsedTime { get; }

        public IntegrationResultEventArgs(double result, long elapsedTime)
        {
            Result = result;
            ElapsedTime = elapsedTime;
        }
    }
}