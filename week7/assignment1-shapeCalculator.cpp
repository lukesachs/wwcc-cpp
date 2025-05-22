#include<iostream>
#include<iomanip>
using namespace std;


class Rectangle {
private:
    double width;
    double length;

public:
    // Constructor
    Rectangle(double i, double g) : width(i), length(g){}
	//Getters
	double getWidth()const {return width;}
	double getLength()const {return length;}

	double getArea() const {
        return  width * length;
    }

	void getArea(double& area) const {
    	area = length * width;
	}

	void print(double area);

	Rectangle& resize(int r){
		this->width = width*r;
		this->length = length*r;
		return *this;
	}

};

class Circle {
private:

    double radius;

public:
	const double pi = 3.14159;
    // Constructor
    Circle(double r) : radius(r) {}

	double getRadius()const {return radius;}

	double getArea() const {
        return  pi * radius * radius;
    }
	
	double getCircumference() const {
		return pi * radius * 2.0;
	}

	void print();

	void print(bool b);
};

void Rectangle::print(double area){
	cout << "Rectangle (Length: " << getLength() << ", Width: " << getWidth() << ")" << endl;
	cout << "Area: " << fixed << setprecision(2) << getArea() << endl;
	cout << "Passing area by reference: " << fixed << setprecision(2) << area << endl;
}

void Circle::print(){
		cout << "Circle (Radius " << fixed << setprecision(2) << radius << ")" << endl;
		cout << "Area: " << fixed << setprecision(2) << getArea() << endl;
		cout << "Circumference: " << fixed << setprecision(2) << getCircumference() << endl;
}

void Circle::print(bool b){
	if(b){
		cout << "Circle details: " << endl;
		cout << "Radius: " << fixed << setprecision(2) << radius << endl;
		cout << "Area:  pi * radius^2 = 3.14159 * " << fixed << setprecision(2) << radius << " = " << getArea() << endl;
		cout << "Circumference: 2 * pi * radius = 2 * 3.14159 * " << fixed << setprecision(2) << radius << " = " << getCircumference() << endl;
	}
}

int main(){

	Rectangle r(5,3);
	Circle c(4);



	cout << "SHAPE CALCULATOR" << endl;
	cout << "----------------------------" << endl;
	cout << endl;

	double area;
	r.getArea(area);
	r.print(area);

	cout << endl;

	c.print();

	cout << endl;
	
	c.print(true);

	cout << endl;

	cout << "Method chaining demonstration:" << endl;
	cout << "Original rectangle: Length = " << r.getLength() << ", Width = " << r.getWidth() << endl;
	cout << "After resizing: Length = " << r.resize(2).getLength() << ", Width = " << r.getWidth() << endl;

	return 0;
}