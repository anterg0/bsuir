namespace _253505_Shpakovsky_Lab6;

public class Employee
{
    public string Name { get; set; }
    public int Age { get; set; }
    public bool Employed { get; set; }

    public Employee(string name, int age, bool employed)
    {
        Name = name;
        Age = age;
        Employed = employed;
    }

    public override string ToString()
    {
        return $"{Name} {Age} {Employed}";
    }
}