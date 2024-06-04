using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Resources;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.UI.ValueConverters
{
    internal class IdToImageValueConverter : IValueConverter
    {
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            string fileName = "image" + value.ToString() + ".jpg";
            string filePath = Path.Combine(@"~/Documents/bsuir/C# PROGRAMMING/sem4/Shpakovsky_253505/Shpakovsky_253505.UI/Resources/Images", fileName);
            if (!File.Exists(filePath))
            {
                return "empty_photo.jpg";
            }
            return filePath;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    }
}
