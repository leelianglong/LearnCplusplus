#ifndef STOCK10_H
#define STOCK10_H

#include <string>

class Stock {
    private:
        std::string commpany;
        long shares;
        double share_val;
        double total_val;
        void set_tot() {
            total_val = shares * share_val;
        }
    public:
        Stock(); // 默认构造函数
        Stock(const std::string &co, long n = 0, double pr = 0.0);// 自定义构造函数
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};

#endif