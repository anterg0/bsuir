namespace lab7;

public class QuadraticEquation
    {
        private int a;
        private int b;
        private int c;
        private double d;

        public QuadraticEquation(int a, int b, int c)
        {
            if (a == 0) throw new ArgumentException("Coefficient 'a' cannot be zero.");
            this.a = a;
            this.b = b;
            this.c = c;
            this.d = b * b - (4 * a * c);
        }
        
        public double[] Solve()
        {
            if (d < 0)
                return new double[0];
            else if (d == 0)
                return new double[] { -b / (2 * a) };
            else
                return new double[] {
                    (-b + Math.Sqrt(d)) / (2 * a),
                    (-b - Math.Sqrt(d)) / (2 * a)
                };
        }

        public override string ToString()
        {
            return $"{a}x^2 + {b}x + {c} = 0";
        }

        public static QuadraticEquation operator +(QuadraticEquation equation, int value)
        {
            return new QuadraticEquation(equation.a, equation.b, equation.c + value);
        }

        public static QuadraticEquation operator -(QuadraticEquation equation, int value)
        {
            return new QuadraticEquation(equation.a, equation.b, equation.c - value);
        }

        public static QuadraticEquation operator ++(QuadraticEquation equation)
        {
            return new QuadraticEquation(equation.a, equation.b, equation.c + 1);
        }

        public static QuadraticEquation operator --(QuadraticEquation equation)
        {
            return new QuadraticEquation(equation.a, equation.b, equation.c - 1);
        }

        public static QuadraticEquation operator *(QuadraticEquation equation, int value)
        {
            return new QuadraticEquation(equation.a * value, equation.b * value, equation.c * value);
        }

        public static QuadraticEquation operator /(QuadraticEquation equation, int value)
        {
            return new QuadraticEquation(equation.a / value, equation.b / value, equation.c / value);
        }

        public static bool operator ==(QuadraticEquation equation1, QuadraticEquation equation2)
        {
            return equation1.a == equation2.a &&
                   equation1.b == equation2.b &&
                   equation1.c == equation2.c;
        }

        public static bool operator !=(QuadraticEquation equation1, QuadraticEquation equation2)
        {
            return !(equation1 == equation2);
        }

        public static explicit operator QuadraticEquation(int value)
        {
            return new QuadraticEquation(value, 0, 0);
        }

        public static explicit operator int(QuadraticEquation equation)
        {
            return equation.a;
        }

        public static bool operator true(QuadraticEquation equation)
        {
            return equation.d != 0;
        }
        
        public static bool operator false(QuadraticEquation equation)
        {
            return equation.d == 0;
        }
        
        
        public int this[int index]
        {
            get => index == 1 ? a : (index == 2 ? b : (index == 3 ? c : throw new ArgumentException("There's only 3 elements in QuadraticEquation.")));
        }
    }