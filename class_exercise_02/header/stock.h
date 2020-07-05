#ifndef STOCK_02_H
#define STOCK_02_H

#include<string>
using namespace std;

class Stock {
    private:
        string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() {total_val = shares * share_val;}
    public:
        Stock(); // 默认构造函数
        Stock(const string &co, long n = 0, double pr = 0.0); // 构造函数
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};

#endif