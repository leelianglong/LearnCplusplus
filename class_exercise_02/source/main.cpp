#include <iostream>
#include "../header/stock.h"

int main()
{
    {
        cout<<"using constructors to create new object";
        Stock Stock1("NanSmart", 10, 100);
        Stock1.show();

        Stock stock2 = Stock("boffo object ", 2, 10);
        stock2.show();
    }
    return 0;
}