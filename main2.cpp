#include <iostream>
#include <cstdlib>

class Shape
{
private:
	std::string name;
public:
	Shape(std::string setName = "Фигура") : name(setName)
	{}

	virtual void print_info()
	{
		std::cout << get_name() << ": " << '\n';
	}

	virtual ~Shape() = default;

protected:
	std::string get_name() { return name; }
};

class Triangle : public Shape
{
private:
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;

public:
	Triangle(int set_a, int set_b, int set_c, int set_A, int set_B, int set_C, std::string setName = "Треугольник") : Shape(setName), a(set_a), b(set_b), c(set_c), A(set_A), B(set_B), C(set_C)
	{}

	void print_info()
	{
		Shape::print_info();
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << '\n';
		std::cout << std::endl;
	}
protected:
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
};

class Right_angled_tri : public Triangle
{
public:
	Right_angled_tri(int set_a, int set_b, int set_c, int set_A, int set_B, std::string setName = "Прямоугольный треугольник") : Triangle(set_a, set_b, set_c, set_A, set_B, 90, setName)
	{}
};

class Isosceles_tri : public Triangle
{
public:
	Isosceles_tri(int set_a, int set_b, int set_A, int set_B, std::string setName = "Равнобедренный треугольник") : Triangle(set_a, set_b, set_a, set_A, set_B, set_A, setName)
	{}
};

class Equilateral_tri : public Triangle
{
public:
	Equilateral_tri(int set_a, std::string setName = "Равносторонний треугольник") : Triangle(set_a, set_a, set_a, 60, 60, 60, setName)
	{}
};

class Quadrilateral : public Shape
{
private:
	int a;
	int b;
	int c;
	int d;
	int A;
	int B;
	int C;
	int D;

public:
	Quadrilateral(int set_a, int set_b, int set_c, int set_d, int set_A, int set_B, int set_C, int set_D, std::string setName = "Четырёхугольник") : Shape(setName), a(set_a), b(set_b), c(set_c), d(set_d), A(set_A), B(set_B), C(set_C), D(set_D)
	{}

	void print_info()
	{
		Shape::print_info();
		std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << '\n';
		std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << '\n';
		std::cout << std::endl;
	}
private:
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }
};

class Rectangle : public Quadrilateral
{
public:
	Rectangle(int set_a, int set_b, std::string setName = "Прямоугольник") : Quadrilateral(set_a, set_b, set_a, set_b, 90, 90, 90, 90, setName)
	{}
};

class Square : public Rectangle
{
public:
	Square(int set_a, std::string setName = "Квадрат") : Rectangle(set_a, set_a, setName)
	{}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int set_a, int set_b, int set_A, int set_B, std::string setName = "Параллелограм") : Quadrilateral(set_a, set_b, set_a, set_b, set_A, set_B, set_A, set_B, setName)
	{}
};

class Rhomb : public Parallelogram
{
public:
	Rhomb(int set_a, int set_A, int set_B, std::string setName = "Ромб") : Parallelogram(set_a, set_a, set_A, set_B, setName)
	{}
};

void print_info(Shape* shape)
{
	shape->print_info();
}

int main(int argc, char** argv)
{
	Triangle shape1(10, 20, 30, 50, 60, 70);
	print_info(&shape1);

	Right_angled_tri shape2(10, 20, 30, 50, 60);
	print_info(&shape2);

	Isosceles_tri shape3(10, 20, 50, 60);
	print_info(&shape3);

	Equilateral_tri shape4(30);
	print_info(&shape4);

	Quadrilateral shape5(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&shape5);

	Rectangle shape6(10, 20);
	print_info(&shape6);

	Square shape7(20);
	print_info(&shape7);

	Parallelogram shape8(20, 30, 30, 40);
	print_info(&shape8);

	Rhomb shape9(30, 30, 40);
	print_info(&shape9);

	return 0;
}