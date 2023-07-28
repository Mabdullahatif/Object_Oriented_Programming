/*
This C++ program defines three classes: 'Point', 'Circle', and 'Cylinder'.
The 'Point' class represents a point in 2D space with x and y coordinates.
It has constructors to initialize the coordinates and getters to access them.

The 'Circle' class represents a circle in 2D space and is defined using its center point (an instance of the 'Point' class) and radius.
The class contains functions to get the radius and center coordinates of the circle, as well as a function to check if a given point lies on the circle.

The 'Cylinder' class represents a cylinder in 3D space. It is defined by its height, two circles (top and bottom) to represent the base, and their respective radii.
The class includes a constructor to initialize the cylinder and functions to get its height.
It also has a function to check if a given point lies on the cylinder, either on its top and bottom circles or between them along the height.

In the 'main' function, the program demonstrates the usage of these classes.
It creates an instance of the 'Point' class, sets its coordinates, and displays them.
It then creates an instance of the 'Circle' class, sets its center point and radius, and checks if the previously created point lies on the circle.
Similarly, it creates an instance of the 'Cylinder' class, sets its attributes, and checks if the point lies on the cylinder.
The program then prints the results of these checks.
*/

#include <iostream>
using namespace std;

class Point {
private:
    int* x;
    int* y;

public:
    // Constructors, Getters and Destructor
    Point(int, int);
    int getx();
    int gety();
    ~Point();
    void display();
    void setx(int);
    void sety(int);
};

Point::Point(int X, int Y) {
    this->x = new int;
    this->y = new int;

    *x = X;
    *y = Y;
}

int Point::getx() {
    return *x;
}

int Point::gety() {
    return *y;
}

Point::~Point() {
    delete x, y;
}

void Point::display() {
    cout << "(" << *x << "," << *y << ")";
}

float square(int sqr) {
    return sqr * sqr;
}

class Circle {
private:
    float* radius;
    Point* coordinate;
    Point Pin;

public:
    // Constructors, Getters, Destructor
    Circle(float, int, int);
    float getradius();
    int getcenterX();
    int getcenterY();
    ~Circle();
    bool CheckOnCircle(Point& p1); // Returns true if point lies in circle, false otherwise
};

Circle::Circle(float R, int x, int y) : Pin(x, y) {
    this->radius = new float;
    *radius = R;
    coordinate = &Pin;
}

float Circle::getradius() {
    return *radius;
}

int Circle::getcenterX() {
    return coordinate->getx();
}

int Circle::getcenterY() {
    return coordinate->gety();
}

Circle::~Circle() {
    delete radius;
}

bool Circle::CheckOnCircle(Point& p1) {
    float length = square(p1.getx() - coordinate->getx()) - square(p1.gety() - coordinate->gety());
    if (length <= square(*radius)) {
        return true;
    } else {
        return false;
    }
}

class Cylinder {
private:
    int height;
    Circle* top; // Circle on top of Cylinder
    Circle* bottom; // Circle on bottom of Cylinder

public:
    // Constructors, Destructor
    Cylinder(int, float, int, int, float, int, int);
    int getheight();
    ~Cylinder();
    bool CheckOnCylinder(Point& p1); // Returns true if point lies in cylinder, false otherwise
};

Cylinder::Cylinder(int h, float rad1, int x1, int y1, float rad2, int x2, int y2)
    : top(new Circle(rad1, x1, y1)), bottom(new Circle(rad2, x2, y2)) {
    height = h;
}

int Cylinder::getheight() {
    return height;
}

Cylinder::~Cylinder() {
    delete top;
    delete bottom;
}

bool Cylinder::CheckOnCylinder(Point& p1) {
    bool isOnTop = top->CheckOnCircle(p1);
    bool isOnBottom = bottom->CheckOnCircle(p1);

    if (isOnTop && isOnBottom) {
        return true;
    }

    // Check if point lies between the top and bottom circles along the height of the cylinder
    int centerY = (top->getcenterY() + bottom->getcenterY()) / 2;
    int heightHalf = height / 2;
    int pointY = p1.gety();
    return (pointY >= centerY - heightHalf && pointY <= centerY + heightHalf);
}

int main() {
    cout << "x and y coordinate : ";
    Point a(3, 4);
    a.display();
    cout << endl;
    
    cout << "Check on circle : ";
    Circle c(5.3, 2, 3);
    cout << c.CheckOnCircle(a) << endl;

    cout << "Check on cylinder : ";
    Cylinder cl(7, 5.3, 2, 9, 5.3, 2, 3);
    cout << cl.CheckOnCylinder(a) << endl;

    return 0;
}
