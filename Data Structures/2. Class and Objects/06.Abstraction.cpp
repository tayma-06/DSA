#include<iostream>
#include<string>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing a Circle" << endl;
    }
};

int main()
{
    Shape* shape = new Circle();
    shape->draw(); // Output: Drawing a Circle
    delete shape;
    Circle c;
    c.draw(); // Output: Drawing a Circle
    
    return 0;
}