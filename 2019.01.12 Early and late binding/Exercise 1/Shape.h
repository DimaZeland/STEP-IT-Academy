#pragma once

#include<iostream>
#include<string>

class Shape{
public:
	Shape(){}
	virtual ~Shape() {}
	inline virtual void print() abstract;
	inline virtual std::string printShapeName() abstract;
	inline virtual double area() { return 0; }
	inline virtual double volume() { return 0; }
};

class Point : public Shape {
public:
	inline void print() override final { std::cout << printShapeName() << ", area: " << area() << ", volume: " << volume() << std::endl; }
	inline std::string printShapeName() override final { return typeid(*this).name() + 5; };
};

class Circle : public Point {
private:
	double width = 1, height = 1;
public:
	Circle(double Width = 1, double Height = 1): Point(), width(Width), height(Height){}
	inline double area() override final{ return width * height; }
};

class Cylinder : public Point {
private:
	const double  Pi = 3.14;
	double radius = 1, height = 1;
public:
	Cylinder(double Radius = 1, double Height = 1) : Point (), radius(Radius), height(Height) {}
	inline double area() override final { return 2 * Pi * radius * height; }
	inline double volume() override final { return Pi * radius * radius * height; }
};

