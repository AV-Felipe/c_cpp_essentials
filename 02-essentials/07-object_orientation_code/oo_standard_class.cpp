#include<iostream>

using namespace std;

//class definition
class Rectangle
{
    private:
    int length;
    int breadth;

    public:
    //default constructor
    Rectangle(){length=breadth=1;}
    //custom constructor
    Rectangle(int l, int b);
    //facilitators methods
    int area();
    int perimeter();
    //getters methods
    int getLength(){return length;}
    //setter methods
    void setLength(int l){length=l;}
    //destructor - to destroy any memory allocation related to the class instance
    ~Rectangle();
};

//methods definitions - because these are not independent functions and we choose to implement
//them outside the class block, we have to use scope resolution here (the Rectangle:: notation)
Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int Rectangle::area()
{
    return length * breadth;
}

int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

Rectangle::~Rectangle()
{
    // this is blank because we don't have any deallocation to do
}

int main()
{
    Rectangle r(10,5);
    cout << "area: " << r.area() << endl;
    cout << "perimeter: " << r.area() << endl;
    r.setLength(20);
    cout << "changed the length to " << r.getLength() << endl;

    Rectangle defaultRec;
    cout << defaultRec.getLength() << endl;
    return 0;
    //at this point the destructor is called
}