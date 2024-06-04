using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.UI.ValueConverters
{
    internal class QualityToColorValueConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if((int)value < 5)
                return Colors.LightPink;
            else if((int)value >= 9)
                return Colors.LightGreen;
            return Colors.LightYellow;

        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
