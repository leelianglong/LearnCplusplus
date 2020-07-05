#ifndef STOCK_H
#define STOCK_H

#include <string>
using namespace std;

class stock
{
private:
    string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() {
        total_val = share_val * shares;
    }
public:
    void acquire(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
    stock(const string &co, long n, double pr); // ���캯����ʵ������ʱ���Զ����á�
    ~stock();
};

/*
* ���캯���еĲ�����Ҫ�����еĳ�Ա������һ����
*/
stock::stock(const string &co, long n, double pr)
{
    company = co;
    if (n < 0) {
        cerr<<"number of shares cannot be negative;"
            <<company<<"shares set to 0\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

stock::~stock()
{
}


#endif