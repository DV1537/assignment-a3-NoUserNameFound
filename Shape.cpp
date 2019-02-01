#include "Shape.h"
#include"Point.h"
#include"Polygon.h"
#include"Triangle.h"
#include"Line.h"
void Shape::setVert(float* verts, int number)
{

	vertices = new float[number];
	this->number = number;
	for (int i=0; i < number; i++)
	{
		vertices[i] = verts[i];
	}
	
}

void Shape::deleting()
{
	
	delete vertices;
	delete center;

}

int Shape::getNumber() const
{
	return number;
}

void Shape::setNumber(int number)
{
	this->number = number;
}

void Shape::setType(string type)
{
	this->type = type;
}

void Shape::setCenter(float x, float y)
{
	delete center;
	this->center = new float[2];
	center[0] = x;
	center[1] = y;
}

float * Shape::getVertices() const
{
	return vertices;
}

float* Shape::position() const
{
	return center;
}

string Shape::getType() const
{
	return type;
}

bool Shape::isConvex() const
{
	bool value = false;
	if (convex == true)
	{
		value = true;
	}
	return value;
}

float Shape::distance(Shape* shape)
{
	return sqrt(pow(center[0]-shape->position()[0],2)+pow(center[1]-shape->position()[1],2));
}


Shape & Shape::operator=( Shape & other)
{
	deleting();
	this->vertices = new float[other.number];

	setVert(other.vertices, other.number);
	
	this->number = other.number;
	return *this;
}

Shape * Shape::operator+(Shape const & other)
{
	float* temp = new float[getNumber() + other.getNumber()];
	for (int i = 0; i < getNumber(); i++)
	{
		temp[i] = getVertices()[i];
	}
	for (int i = getNumber(); i < getNumber() + other.getNumber(); i++)
	{
		temp[i] = other.getVertices()[i - getNumber()];

	}
	deleting();
	Shape * tempShape;
	if (getNumber() + other.getNumber() == 2)
	{

		tempShape = new Point(temp[0], temp[1]);
	}
	else if (getNumber() + other.getNumber() == 4)
	{

		tempShape = new Line(temp[0], temp[1], temp[2], temp[3]);
	}
	else if (getNumber() + other.getNumber() == 6)
	{
		tempShape = new Triangle(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
	}
	else
	{
		tempShape = new Polygon(temp, getNumber() + other.getNumber());
	}


	setVert(temp, getNumber() + other.getNumber());
	delete temp;
	return tempShape;
}

 ostream & operator<<(ostream & other, const Shape& shape)
{
	
 	other <<  "First shape vertices: ";
	for (int i = 0; i < shape.getNumber(); i++)
	{
		other << to_string(shape.vertices[i]) + " ";
	}

	return other;
}
