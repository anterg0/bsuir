using System.Reflection;
using _253505_Shpakovsky_Lab6;

string dllPath = "Classes.dll";

Assembly assembly = Assembly.LoadFrom(dllPath);

Type type = assembly.GetType("Classes.FileService`1").MakeGenericType(typeof(Employee));

var fileSer = Activator.CreateInstance(type);

var save = type.GetMethod("SaveData");
var load = type.GetMethod("ReadFile");

List<Employee> employees = new List<Employee>() 
{
    new Employee("Ivan", 20, true),
    new Employee("Petya", 25, false),
    new Employee("Vasya", 30, true),
    new Employee("Kolya", 35, false)
};

save.Invoke(fileSer,new object[]{employees,"empl.json"});

List<Employee> JsonDeSerialize = (List<Employee>)load.Invoke(fileSer, new object[] { "empl.json" });

foreach(var empl in JsonDeSerialize)
{
    Console.WriteLine(empl);
}