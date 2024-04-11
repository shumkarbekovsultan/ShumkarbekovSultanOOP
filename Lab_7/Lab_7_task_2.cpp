include <iostream>
#include <cmath>

using namespace std;

class Figure {
public:
    
    virtual double area() const = 0;

    virtual double perimeter() const = 0;
};

class Rectangle : public Figure {
private:
    double length;
    double width;  

public:
    
    Rectangle(double l, double w) : length(l), width(w) {}

    virtual double area() const override {
        return length * width;
    }

    virtual double perimeter() const override {
        return 2 * (length + width);
    }
};


class Circle : public Figure {
private:
    double radius; 

public:
    Circle(double r) : radius(r) {}

    virtual double area() const override {
        return 3,14 * radius * radius; 
    }

  
    virtual double perimeter() const override {
        return 2 * 3,14 * radius; 
    }
};

class Trapezium : public Figure {
private:
    double a;
    double b; 
    double h; 

public:
   
    Trapezium(double biggerBase, double smallerBase, double height) : a(biggerBase), b(smallerBase), h(height) {}

 
    virtual double area() const override {
        return (a + b) * h / 2;
    }

    virtual double perimeter() const override {
        return a + b + 2 * sqrt((h * h) + (((a - b) / 2) * ((a - b) / 2))); // a + b + 2 * v(h^2 + ((a - b)/2)^2)
    }
};

int main() {

    double lengthRect, widthRect;
    cout << "Enter the length of the rectangle: ";
    cin >> lengthRect;
    cout << "Enter the width of the rectangle: ";
    cin >> widthRect;

  
    Rectangle rect(lengthRect, widthRect);

    double radiusCircle;
    cout << "Enter the radius of the circle: ";
    cin >> radiusCircle;

    Circle circle(radiusCircle);

  
    double biggerBaseTrapezium, smallerBaseTrapezium, heightTrapezium;
    cout << "Enter the bigger base of the trapezium: ";
    cin >> biggerBaseTrapezium;
    cout << "Enter the smaller base of the trapezium: ";
    cin >> smallerBaseTrapezium;
    cout << "Enter the height of the trapezium: ";
    cin >> heightTrapezium;

    
    Trapezium trapezium(biggerBaseTrapezium, smallerBaseTrapezium, heightTrapezium);

    cout << endl << "Rectangle:" << endl;
    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;

    cout << endl << "Circle:" << endl;
    cout << "Area: " << circle.area() << endl;
    cout << "Perimeter: " << circle.perimeter() << endl;

    cout << endl << "Trapezium:" << endl;
    cout << "Area: " << trapezium.area() << endl;
    cout << "Perimeter: " << trapezium.perimeter() << endl;

    return 0;
}


power bi 
orange 
