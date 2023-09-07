using lab6;

Car car = new Car("Toyota", "Trueno", 1986, 4, false);
car.StartEngine();
car.Accelerate();
car.Brake();
car.StopEngine();
car.DisplayInfo();

Console.WriteLine();

Truck truck = new Truck("Ford", "F-150", 2021, 2, 5000);
truck.StartEngine();
truck.LoadCargo();
truck.UnloadCargo();
truck.StopEngine();
truck.DisplayInfo();

