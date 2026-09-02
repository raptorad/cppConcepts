#include <iostream>
//*******************************************************
// Using concepts to create a static interface
// requires C++ 2020 or newer
//*******************************************************

//************************************************
// Concept Printable which requires print method
//************************************************
template<class T>
concept Printable = requires(T a)
{
    a.print();
};

class ConcreteA
{
public:
    void print() const
    {
        std::cout<<"print a\n";
    }
};

class ConcreteB
{
public:
    // print with other return type also works with the Printable concept
    int print() const
    {
        std::cout<<"print b\n";
        return 0;
    }
};


//***************************************************************************
// Function which uses concept. Can use all classes which has a print method
//***************************************************************************
template<Printable P>
void universalPrint(const P& Pr)
{
    Pr.print();
}

int main()
{
    ConcreteA objA;
    ConcreteB objB;
    universalPrint(objA);
    universalPrint(objB);
    return 0;
}
