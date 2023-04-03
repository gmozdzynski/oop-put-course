
#include <iostream>
#include <string>

using namespace std;

class Shape{
public:
    Shape(){};
    virtual ~Shape(){}
    virtual Shape *Multiply(float height) = 0;
    virtual string Area() = 0;

};

class Rectangle: public Shape{
private:
    float length;
public:
    Rectangle *Multiply(float height){return new Rectangle(length * height); }
    string Area(){return "m^2"; }
    Rectangle(float length){this->length = length; }

};

class Triangle: public Shape{
private:
    float length;
public:
    Triangle *Multiply(float height){return new Triangle((length * height)/2); }
    string Area(){return "m^2";}
    Triangle(float length){this->length = length; }

};

int main(){
Rectangle rec1(5.0);
Rectangle *areaRec1 = rec1.Multiply(7.0);
}
