using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shpakovsky_253505.Domain.Entities
{
    public class Work : Entity
    {
        private Work()
        {
            
        }
        public Work(Person personalData, DateTime date, int? qualityMark = 0)
        {
            PersonalData = personalData;
            Quality = qualityMark;
            DeadLine = date;
        }

        public Person PersonalData {get; private set; }
        public DateTime DeadLine { get; private set; }
        public int? Quality { get; private set; }
        public int? BrigadeId { get; private set; }

        public void AddToBrigade(int brigadeId)
        {
            if (brigadeId <= 0) return;
            BrigadeId = brigadeId;
        }

        public void LeaveBrigade()
        { BrigadeId = 0; }
    
        public void ChangeQualityMark(int qualityMark)
        {
            if (qualityMark < 0 || qualityMark > 10) return;
            Quality = qualityMark;
        }

        public void ChangeDate(DateTime date)
        {
            DeadLine = date;
        }
    }
}
