namespace lab6;

public  class Vehicle
{
    private string make;
    private string model;
    private int year;

    public string Make => make;
    public string Model => model;
    public int Year => year;

    public Vehicle(string make, string model, int year)
    {
        this.make = make;
        this.model = model;
        this.year = year;
    }

    public virtual void DisplayInfo()
    {
        Console.WriteLine($"Manufacturer: {make}");
        Console.WriteLine($"Model: {model}");
        Console.WriteLine($"Year: {year}");
    }

    public virtual void StartEngine()
    {
        Console.WriteLine("Engine started.");
    }

    public virtual void StopEngine()
    {
        Console.WriteLine("Engine stopped.");
    }
}

public class Car : Vehicle
{
    private int numDoors;
    private bool isConvertible;

    public int NumDoors => numDoors;
    public bool IsConvertible => isConvertible;

    public Car(string make, string model, int year, int numDoors, bool isConvertible)
        : base(make, model, year)
    {
        this.numDoors = numDoors;
        this.isConvertible = isConvertible;
    }

    public override void StartEngine()
    {
        base.StartEngine();
        Console.WriteLine("Car engine started.");
    }

    public override void StopEngine()
    {
        base.StopEngine();
        Console.WriteLine("Car engine stopped.");
    }

    public void Accelerate()
    {
        Console.WriteLine("Car accelerating.");
    }

    public void Brake()
    {
        Console.WriteLine("Car braking.");
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Number of doors: {numDoors}\nConvertible: " + (isConvertible ? "yes" : "no"));
    }
}

public class Truck : Vehicle
{
    private int numAxles;
    private double cargoCapacity;

    public int NumAxles => numAxles;
    public double CargoCapacity => cargoCapacity;

    public Truck(string make, string model, int year, int numAxles, double cargoCapacity)
        : base(make, model, year)
    {
        this.numAxles = numAxles;
        this.cargoCapacity = cargoCapacity;
    }

    public override void StartEngine()
    {
        base.StartEngine();
        Console.WriteLine("Truck engine started.");
    }

    public override void StopEngine()
    {
        base.StopEngine();
        Console.WriteLine("Truck engine stopped.");
    }

    public void LoadCargo()
    {
        Console.WriteLine("Truck loading cargo.");
    }

    public void UnloadCargo()
    {
        Console.WriteLine("Truck unloading cargo.");
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Number of axles: {numAxles}\nCargo capacity: {cargoCapacity}");
    }
}
