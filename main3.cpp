#include <iostream>
#include <cstdlib>

class Shape
{
private:
	int sides;
	std::string name;

public:
	Shape(int setSides = 0, std::string setName = "Фигура") : sides(setSides), name(setName) {}

	virtual bool check()
	{
		if (sides == 0) { return true; }
		else { return false; }
	}

	virtual void print_info()
	{
		std::cout << name << ": " << "\n";
		std::cout << (check() ? "Правильная" : "Неправильная") << '\n';
		std::cout << "Количество сторон: " << sides << std::endl;
		if (sides == 0) { std::cout << std::endl; }
	}

	virtual ~Shape() = default;
protected:
	int getSides() { return sides; }
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
	Triangle(int set_a, int set_b, int set_c, int set_A, int set_B, int set_C, std::string setName = "Треугольник", int setSides = 3) : Shape(setSides, setName), a(set_a), b(set_b), c(set_c), A(set_A), B(set_B), C(set_C)
	{}

	virtual bool check()
	{
		if (this->getSides() == 3 && A + B + C == 180) { return true; }
		else { return false; }
	}

	void print_info()
	{
		Shape::print_info();
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
		std::cout << std::endl;
	}

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

	bool check()
	{
		if (Triangle::check() && this->get_C() == 90) { return true; }
		else { return false; }
	}
};

class Isosceles_tri : public Triangle
{
public:
	Isosceles_tri(int set_a, int set_b, int set_A, int set_B, std::string setName = "Равнобедренный треугольник") : Triangle(set_a, set_b, set_a, set_A, set_B, set_A, setName)
	{}

	bool check()
	{
		if (Triangle::check() && this->get_a() == this->get_c() && this->get_A() == this->get_C()) { return true; }
		else { return false; }
	}
};

class Equilateral_tri : public Triangle
{
public:
	Equilateral_tri(int set_a, std::string setName = "Правильный треугольник") : Triangle(set_a, set_a, set_a, 60, 60, 60, setName)
	{}

	bool check()
	{
		if (Triangle::check() && this->get_a() == this->get_b() && this->get_a() == this->get_c() && this->get_b() == this->get_c() && this->get_A() == 60 && this->get_B() == 60 && this->get_C() == 60) { return true; }
		else { return false; }
	}
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
	Quadrilateral(int set_a, int set_b, int set_c, int set_d, int set_A, int set_B, int set_C, int set_D, std::string setName = "Четырёхугольник", int setSides = 4) : Shape(setSides, setName), a(set_a), b(set_b), c(set_c), d(set_d), A(set_A), B(set_B), C(set_C), D(set_D)
	{}

	virtual bool check()
	{
		if (this->getSides() == 4 && A + B + C + D == 360) { return true; }
		else { return false; }
	}

	void print_info()
	{
		Shape::print_info();
		std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << '\n';
		std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
		std::cout << std::endl;
	}

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

	virtual bool check()
	{
		if (Quadrilateral::check() && this->get_a() == this->get_c() && this->get_b() == this->get_d() && this->get_A() == 90 && this->get_B() == 90 && this->get_C() == 90 && this->get_D() == 90) { return true; }
		else { return false; }
	}
};

class Square : public Rectangle
{
public:
	Square(int set_a, std::string setName = "Квадрат") : Rectangle(set_a, set_a, setName)
	{}

	bool check()
	{
		if (Rectangle::check() && this->get_a() == this->get_b() && this->get_a() == this->get_c() && this->get_a() == this->get_d() && this->get_b() == this->get_c() && this->get_b() == this->get_d() && this->get_c() == this->get_d()) { return true; }
		else { return false; }
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int set_a, int set_b, int set_A, int set_B, std::string setName = "Параллелограмм") : Quadrilateral(set_a, set_b, set_a, set_b, set_A, set_B, set_A, set_B, setName)
	{}

	virtual bool check()
	{
		if (Quadrilateral::check() && this->get_A() == this->get_C() && this->get_B() == this->get_D()) { return true; }
		else { return false; }
	}
};

class Rhomb : public Parallelogram
{
public:
	Rhomb(int set_a, int set_A, int set_B, std::string setName = "Ромб") : Parallelogram(set_a, set_a, set_A, set_B, setName)
	{}

	bool check()
	{
		if (Parallelogram::check() && this->get_a() == this->get_b() && this->get_a() == this->get_c() && this->get_a() == this->get_d() && this->get_b() == this->get_c() && this->get_b() == this->get_d() && this->get_c() == this->get_d()) { return true; }
		else { return false; }
	}
};

void print_info(Shape* shape) { shape->print_info(); }

int main(int argc, char** argv)
{
	Shape shape1;
	print_info(&shape1);

	Triangle shape2(10, 20, 30, 50, 60, 70);
	print_info(&shape2);

	Triangle shape3(10, 20, 30, 50, 30, 70);
	print_info(&shape3);

	Right_angled_tri shape4(10, 20, 30, 50, 40);
	print_info(&shape4);

	Right_angled_tri shape5(10, 20, 30, 50, 60);
	print_info(&shape5);

	Isosceles_tri shape6(10, 20, 50, 60);
	print_info(&shape6);

	Isosceles_tri shape7(10, 20, 65, 50);
	print_info(&shape7);

	Equilateral_tri shape8(10);
	print_info(&shape8);

	Quadrilateral shape9(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&shape9);

	Quadrilateral shape10(10, 20, 30, 40, 90, 90, 70, 110);
	print_info(&shape10);

	Rectangle shape11(10, 20);
	print_info(&shape11);

	Square shape12(10);
	print_info(&shape12);

	Parallelogram shape13(20, 30, 30, 40);
	print_info(&shape13);

	Parallelogram shape14(20, 30, 50, 130);
	print_info(&shape14);

	Rhomb shape15(20, 30, 130);
	print_info(&shape15);

	Rhomb shape16(20, 100, 80);
	print_info(&shape16);


	return 0;
}
