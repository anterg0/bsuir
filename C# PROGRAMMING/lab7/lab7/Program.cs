using lab7;
QuadraticEquation equation1 = new QuadraticEquation(1, 5, 6);
Console.WriteLine($"Equation1: {equation1}");
double[] roots = equation1.Solve();
Console.WriteLine($"Equation1 roots: {string.Join(", ", roots)}");

QuadraticEquation equation2 = new QuadraticEquation(1, 5, 6);
equation1 *= 3;
equation1 -= 10;
roots = equation1.Solve();
Console.WriteLine($"Equation2 roots: {string.Join(", ", roots)}");
Console.WriteLine($"Equation1: {equation1}\nEquation2: {equation2}");
if (equation1 == equation2) Console.WriteLine("They are identical.");
else Console.WriteLine("They aren't identical.");

equation2 *= 3;
equation2 -= 10;
Console.WriteLine($"Equation1: {equation1}\nEquation2: {equation2}");
if (equation1 != equation2) Console.WriteLine("They aren't identical.");
else Console.WriteLine("They are identical.");


int hi = (int)equation1;
Console.WriteLine(hi);
equation2 = (QuadraticEquation)hi;
Console.WriteLine($"Equation2: {equation2}");


if (equation2) Console.WriteLine("True");
else Console.WriteLine("False");
if (equation1) Console.WriteLine("True");
else Console.WriteLine("False");

Console.WriteLine(equation1[1]);