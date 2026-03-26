#include <iostream>
#include <cstdlib>

class Shape
{
private:
	int sides;
	std::string name;

public:
	Shape(int setSides = 0, std::string setName = "Фигура") : sides{ setSides }, name{ setName }
	{}

	int get_sides()
	{
		return this->sides;
	}
	std::string get_name()
	{
		return this->name;
	}
};

class Triangle : public Shape
{
public:
	Triangle(int setSides = 3, std::string setName = "Треугольник") : Shape(setSides, setName)
	{}
};

class Quadrilateral : public Shape
{
public:
	Quadrilateral(int setSides = 4, std::string setName = "Четырехугольник") : Shape(setSides, setName)
	{}
};


int main(int argc, char** argv)
{
	std::cout << "Количество сторон:" << '\n';
	Shape shape1;
	std::cout << shape1.get_name() << ": " << shape1.get_sides() << std::endl;
	Triangle shape2;
	std::cout << shape2.get_name() << ": " << shape2.get_sides() << std::endl;
	Quadrilateral shape3;
	std::cout << shape3.get_name() << ": " << shape3.get_sides() << std::endl;
	return 0;
}