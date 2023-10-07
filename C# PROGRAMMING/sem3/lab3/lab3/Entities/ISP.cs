namespace lab3.Entities
{
    public class ISP
    {
        private Dictionary<string, Tariff> tariffs;
        private List<Customer> customers;
        private event Action<string> onCustomerAdded;
        private event Action<string> onTariffAdded;

        public ISP()
        {
            tariffs = new Dictionary<string, Tariff>();
            customers = new List<Customer>();
        }

        public void AddTariff(string name, decimal cost)
        {
            tariffs[name] = new Tariff { Name = name, Cost = cost };
            onTariffAdded?.Invoke(name);
        }

        public void AddCustomer(string name, decimal traffic)
        {
            customers.Add(new Customer { Name = name, Traffic = traffic });
            onCustomerAdded?.Invoke(name);
        }

        public void AddTariffToCustomer(string customerName, string tariffName)
        {
            var customer = customers.FirstOrDefault(c => c.Name == customerName);
            if (customer != null && tariffs.ContainsKey(tariffName))
            {
                customer.Tariffs.Add(tariffs[tariffName]);
            }
        }

        public void UpdateCustomerTraffic(string name, decimal newTraffic)
        {
            var customer = customers.FirstOrDefault(c => c.Name == name);
            if (customer != null)
            {
                customer.Traffic = newTraffic;
            }
        }

        public List<string> GetSortedTariffNamesByCost()
        {
            var sortedTariffNames = (from tariff in tariffs
                orderby tariff.Value.Cost
                select tariff.Key).ToList();
            return sortedTariffNames;
        }

        public decimal GetTotalTrafficCost()
        {
            decimal totalCost = (from customer in customers
                from tariff in customer.Tariffs
                select customer.Traffic * tariff.Cost).Sum();
            return totalCost;
        }

        public string GetCustomerWithMaxPayment()
        {
            var customer = (from c in customers
                orderby c.Traffic * c.Tariffs.Sum(t => t.Cost) descending
                select c).FirstOrDefault();
            return customer?.Name;
        }

        public int GetCustomersCountWithPaymentAbove(decimal amount)
        {
            int count = (from customer in customers
                where customer.Traffic * customer.Tariffs.Sum(t => t.Cost) > amount
                select customer).Count();
            return count;
        }


        public List<TariffCustomerCount> GetCustomerCountByTariff()
        {
            var customerCounts = (from customer in customers
                from tariff in customer.Tariffs
                group customer by tariff.Name into tariffGroup
                select new TariffCustomerCount
                {
                    Tariff = tariffGroup.Key,
                    Count = tariffGroup.Count()
                }).ToList();
            return customerCounts;
        }

    }
    public class TariffCustomerCount
    {
        public string Tariff { get; set; }
        public int Count { get; set; }
    }
}
