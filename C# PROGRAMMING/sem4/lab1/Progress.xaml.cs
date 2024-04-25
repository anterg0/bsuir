using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1;

public partial class Progress : ContentPage
{
    public Progress()
    {
        InitializeComponent();
    }
    private CancellationTokenSource cancellationTokenSource;

    private async void OnStartClicked(object sender, EventArgs e)
    {
        MainThread.BeginInvokeOnMainThread(() =>
        {
            startButton.IsEnabled = false;
            stopButton.IsEnabled = true;
            labelStatus.Text = "Вычисление";
            PBar.Progress = 0;
        });
        

        cancellationTokenSource = new CancellationTokenSource();
        CancellationToken cancellationToken = cancellationTokenSource.Token;

        try
        {
            double result = await Task.Run(()=> CalculateIntegralAsync(cancellationToken));
            MainThread.BeginInvokeOnMainThread(() =>
            {
                labelStatus.Text = $"Результат: {result}";
                startButton.IsEnabled = true;
                stopButton.IsEnabled = false;
            });
        }
        catch (OperationCanceledException)
        {
            MainThread.BeginInvokeOnMainThread(() =>
            {
                labelStatus.Text = "Задание отменено";
            });
            
        }
    }

    private void OnCancelClicked(object sender, EventArgs e)
    {
        cancellationTokenSource?.Cancel();
        startButton.IsEnabled = true;
        stopButton.IsEnabled = false;
    }

    private async Task<double> CalculateIntegralAsync(CancellationToken cancellationToken)
    {
        double result = 0;
        double step = 0.00000001;
        int iterations = 1000000;

        for (int i = 0; i < iterations; i++)
        {
           // await Task.Delay(1);

            if (cancellationToken.IsCancellationRequested)
            {
                cancellationToken.ThrowIfCancellationRequested();
            }
            

            result += Math.Sin(i) * step;
            double progress = Math.Round((double)i / iterations, 3);
            string percentage = Convert.ToString(Math.Round(progress * 100,1)) + "%";
            MainThread.BeginInvokeOnMainThread(() =>
            {
                PercentageProgress.Text = percentage;
                PBar.Progress = progress; 
            });
            
        }

        return result;
    }

}