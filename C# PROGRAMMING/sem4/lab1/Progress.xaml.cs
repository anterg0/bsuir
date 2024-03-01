using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1;

public partial class Progress : ContentPage, IProgress<double>
{
    public Progress()
    {
        InitializeComponent();
    }
    
    void Report(double value)
    {
        
    }
}