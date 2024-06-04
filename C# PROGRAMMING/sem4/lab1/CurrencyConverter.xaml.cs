using System;
using System.Security.Cryptography.X509Certificates;
using lab1.Entities;
using lab1.Services;

namespace lab1;

public partial class CurrencyConverter : ContentPage
{
    public DateTime TodayDate { get; init; }
    public IRateService _rateService;
    public List<Rate> RatesList { get; set; }
    private Rate _curRate { get; set; } = null;

    public CurrencyConverter(IRateService rateService)
    {
        InitializeComponent();
        TodayDate = DateTime.Now;
        RatesList = new List<Rate>();
        _rateService = rateService;
        BindingContext = this;
    }
    public void OnLoaded(object sender, EventArgs e)
    {
        RatesList = _rateService.GetRates(dataPicker.Date).ToList();
        CollView.ItemsSource = RatesList;
        CurrencyPicker.ItemsSource = RatesList;
    }
    public void DateSelected(object sender, EventArgs e)
    {
        int selectedIndex = CurrencyPicker.SelectedIndex;
        RatesList = _rateService.GetRates(dataPicker.Date).ToList();
        CollView.ItemsSource = RatesList;
        CurrencyPicker.ItemsSource = RatesList;
        CurrencyPicker.SelectedIndex = selectedIndex;
        if (CurrencyPicker.SelectedIndex != -1)
        {
            _curRate = (Rate)CurrencyPicker.SelectedItem;
        }
    }
    public void OnCurrentRateChanged(object sender, EventArgs e)
    {
        _curRate = (Rate)CurrencyPicker.SelectedItem;
        if (CurrencyEntry.Text == String.Empty || CurrencyEntry.Text == null)
        {
            if (BynEntry.Text != String.Empty && BynEntry.Text != null)
            {
                CurrencyEntry.TextChanged -= OnCurrencyEntryTextChanged;
                CurrencyEntry.Text = $"{ConvertBYNToCurrency(Convert.ToDouble(_curRate.Cur_OfficialRate / _curRate.Cur_Scale), Convert.ToDouble(BynEntry.Text)):0.###}";
                CurrencyEntry.TextChanged += OnCurrencyEntryTextChanged;
            }
        }
        else if (_curRate != null)
        {
            BynEntry.TextChanged -= OnBynTextChanged;
            BynEntry.Text = $"{ConvertCurrencyToBYN(Convert.ToDouble(_curRate.Cur_OfficialRate / _curRate.Cur_Scale), Convert.ToDouble(CurrencyEntry.Text)):0.###}";
            BynEntry.TextChanged += OnBynTextChanged;
        }

    }
    public void OnBynTextChanged(object sender, TextChangedEventArgs e)
    {
        if (BynEntry.Text == String.Empty)
            CurrencyEntry.Text = String.Empty;
        else
        {
            if (_curRate != null)
            {
                double num;
                if (Double.TryParse(BynEntry.Text, out num))
                {
                    CurrencyEntry.TextChanged -= OnCurrencyEntryTextChanged;
                    CurrencyEntry.Text = $"{ConvertBYNToCurrency(Convert.ToDouble(_curRate.Cur_OfficialRate / _curRate.Cur_Scale), num):0.###}";
                    CurrencyEntry.TextChanged += OnCurrencyEntryTextChanged;
                }
                else
                {
                    BynEntry.Text = BynEntry.Text.Substring(0, BynEntry.Text.Length - 1);
                }
            }
            else
            {
                char symb = BynEntry.Text[BynEntry.Text.Length - 1];
                if (!char.IsDigit(symb) || symb != ',')
                {
                    if (!char.IsDigit(symb))
                        BynEntry.Text = BynEntry.Text.Substring(0, BynEntry.Text.Length - 1);
                    else if (BynEntry.Text.Count(c => c == ',') > 1)
                        BynEntry.Text = BynEntry.Text.Substring(0, BynEntry.Text.Length - 1);
                }
            }
        }
    }
    public void OnCurrencyEntryTextChanged(object sender, TextChangedEventArgs e)
    {
        if (CurrencyEntry.Text == String.Empty)
            BynEntry.Text = String.Empty;
        else
        {
            double num;
            if (_curRate != null)
            {
                if (Double.TryParse(CurrencyEntry.Text, out num))
                {
                    BynEntry.TextChanged -= OnBynTextChanged;
                    BynEntry.Text = $"{ConvertCurrencyToBYN(Convert.ToDouble(_curRate.Cur_OfficialRate / _curRate.Cur_Scale), num):0.###}";
                    BynEntry.TextChanged += OnBynTextChanged;
                }
                else
                {
                    CurrencyEntry.Text = CurrencyEntry.Text.Substring(0, CurrencyEntry.Text.Length - 1);
                }
            }
            else
            {
                char simb = CurrencyEntry.Text[CurrencyEntry.Text.Length - 1];
                if (!char.IsDigit(simb) || simb != ',')
                { 
                    if (!char.IsDigit(simb))
                        CurrencyEntry.Text = CurrencyEntry.Text.Substring(0, CurrencyEntry.Text.Length - 1);
                    else if (CurrencyEntry.Text.Count(c => c == ',') > 1)
                        CurrencyEntry.Text = CurrencyEntry.Text.Substring(0, CurrencyEntry.Text.Length - 1);
                }
            }
        }
    }
    private double ConvertBYNToCurrency(double curRate, double enteredByn)
    {
        return enteredByn / curRate;
    }
    private double ConvertCurrencyToBYN(double curRate, double enteredCurrency)
    {
        return enteredCurrency * curRate;
    }
}