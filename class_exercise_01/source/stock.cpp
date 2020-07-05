#include <iostream>
#include "../header/stock.h"

void stock :: acquire(const std::string &co, long n, double pr) {
    company = co;
    if (n < 0) {
        std::cout<< "numbers of shares is not allowed to be negative"
                << company
                << "shares to be set 0\n";
        shares = 0;
    } else {
        shares = n;
    }
    shares = n;
    share_val = pr;
    set_tot();
}

void stock::buy(long num, double price)
{
    if (num < 0) {
        cout << "numbers of shares purchased cannot be negative"
             << "transaction is abort\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void stock::sell(long num, double price)
{
    if (num < 0) {
        cout << "numbers of shares sold cannot be negative"
            << "transaction is abort\n";
    } else if (num > shares) {
        cout << "you cannot sell more than you have"
            << "transaction is abort\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void stock::update(double price)
{
    share_val = price;
    set_tot();
}

void stock::show()
{
 #if 0
    cout<< "company:" << company << endl;
    cout<< "shares:" << shares << endl;
    cout<< "share price:$" << share_val<<endl;
    cout<< "total worth:$" << total_val<<endl;
#endif
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3); // 设置格式为3位小数。
    cout<< "Company "<< company<<"\n"
        <<"share:" << shares<<endl;
    cout<<"share price:$"<<share_val<<"\n";
    cout.precision(2); // 设置2位小数
    cout<<"total worth:$"<<total_val<<endl;
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

int main(void)
{
    stock fluffy_the_cat = {"NanoSmart", 20, 12.50};
   // fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();
    fluffy_the_cat.sell(400, 20);
    fluffy_the_cat.show();
    fluffy_the_cat.buy(40000, 20);
    fluffy_the_cat.sell(3000, 12.5);
    fluffy_the_cat.show();
    stock food = stock("BAIDU", 100, 78);
    food.show();
    stock vag("new oriention", 11, 8);
    vag.show();
    system("pause");
    return 0;
}
