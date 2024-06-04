using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Domain.Entities
{
    public class Brigade : Entity
    {
        private List<Work> _works = new();
        private Brigade() { }
        public Brigade(string name, DateTime commenceFrom, int number)
        {
            Name = name; 
            CommenceFrom = commenceFrom; 
            NumberOfPeople = number;
        }

        public string? Name { get; set; }
        public DateTime CommenceFrom { get; private set; }
        public int NumberOfPeople { get; private set; }
        public IReadOnlyList<Work> Works { get => _works.AsReadOnly(); }
    }
}
