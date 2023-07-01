#include <iostream>

using namespace std;

// here we are defining a generic class.
// it is generic in the data type that it can take - for instance, we don't have to define
// one arithmetic class for integers and one for float, we define all the methods only once
// and make it generic concerning the data type
template <class T> // T is the generic data type
class Arithmetic
{
private:
    T operatorA;
    T operatorB;

public:
    Arithmetic(T operatorA, T operatorB);
    T add();
    T sub();
};

// here in the scope definition, we must pass the type parameter with the scope resolution,
// it is coming from the class template, the generic type
template <class T>
Arithmetic<T>::Arithmetic(T operatorA, T operatorB)
{
    this->operatorA = operatorA; // the this -> notation is used because we chose to name the parameters same as the class properties, so we must distinguish one from the other
    this->operatorB = operatorB;
}

template <class T>
T Arithmetic<T>::add()
{
    T result;
    result = operatorA + operatorB;
    return result;
}

template <class T>
T Arithmetic<T>::sub()
{
    T result;
    result = operatorA - operatorB;
    return result;
}

int main()
{
    Arithmetic<int> ar(10, 5); // here we used the template class with an integer type

    cout << ar.add() << endl;

    Arithmetic<float> ar2(10.1, 5.3); // here we used the template class with an float type

    cout << ar2.sub() << endl;

    return 0;
}