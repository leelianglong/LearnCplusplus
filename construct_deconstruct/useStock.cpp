#include <iostream>
#include "stock10.h"


int main(void) 
{
    {
        using std::cout;
        cout << "Using constructors to create new objects \n";
        Stock Stock1("NanoSmart", 12, 20.0);
        Stock1.show();
        Stock Stock2 = Stock("bobf", 2, 2.0);
        Stock2.show();
    }
}