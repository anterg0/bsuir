using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1;

public partial class CalculatorPage : ContentPage
{
    public CalculatorPage()
    {
        InitializeComponent();
    }

    // private string currentLabel = "";
    private char currentOperator = '+';
    private double firstNumber, secondNumber;
    private int currentState = 0; // 0 - new calculation, 1 - first number is being  (negative if decimal), 2 - transition to second number, 3 - second number is being entered (negative if decimal), 4 - repeating calculation

    private double Calculate()
    {
        switch (currentOperator)
        {
            case '+':
                return firstNumber + secondNumber;
            case '-':
                return firstNumber - secondNumber;
            case '*':
                return firstNumber * secondNumber;
            case '/':
                return firstNumber / secondNumber;
            default:
                return 0;
        }
    }

    private void OnCalculate(object? sender, EventArgs e)
    {
        if (currentState == 4)
        {
            firstNumber = Convert.ToDouble(EnterField.Text);
            EnterField.Text = (this.Calculate()).ToString();
            return;
        } else if (currentState == 0)
        {
            EnterField.Text = "0";
            return;
        }
        if (currentState == 3 || currentState == -3) secondNumber = Convert.ToDouble(EnterField.Text);
        if (secondNumber == 0)
        {
            EnterField.Text = "Error";
            currentState = 0;
            return;
        }
        EnterField.Text = (this.Calculate()).ToString();
        currentState = 4;
    }

    private void OnNumberClicked(object? sender, EventArgs e)
    {
        Button button = (Button)sender;
        string pressed = button.Text;
        if (currentState < 0 && pressed == ".") return;
        if (currentState == 0 || currentState == 4)
        {
            EnterField.Text = pressed;
            if (pressed == ".") currentState = -1;
            else currentState = 1;
            return;
        } else if (currentState == 2)
        {
            EnterField.Text = pressed;
            currentState = 3;
            return;
        } else if (pressed == "." && currentState > 0) currentState *= -1;
        
        EnterField.Text += pressed;
    }

    private void OnOperatorClicked(object? sender, EventArgs e)
    {
        Button button = (Button)sender;
        char oper = button.Text[0];
        if (currentState == 1 || currentState == -1 || currentState == 4)
        {
            currentOperator = oper;
            firstNumber = Convert.ToDouble(EnterField.Text);
            currentState = 2;
        }
    }

    private void OnClear(object? sender, EventArgs e)
    {
        EnterField.Text = "0";
        currentState = 0;
        currentOperator = '+';
        firstNumber = 0;
        secondNumber = 0;
    }

    private void OnNegative(object? sender, EventArgs e)
    {
        EnterField.Text = (Convert.ToDouble(EnterField.Text) * -1).ToString();
    }

    private void OnSin(object? sender, EventArgs e)
    {
        double degrees_to_rad = Convert.ToDouble(EnterField.Text) * Double.Pi / 180.0;
        EnterField.Text = (Math.Sin(degrees_to_rad)).ToString();
    }

    private void OnPercentage(object? sender, EventArgs e)
    {
        EnterField.Text = (Convert.ToDouble(EnterField.Text) * 0.01).ToString();
    }
}