#include <iostream>
#include "stock10.h"

/* 默认构造函数会把成员变量都初始化一遍 */
Stock::Stock() {
    std::cout << "Default contructor called \n";
    commpany = "no name";
    shares = 0;
    total_val = 0.0;
    share_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr) {
    std::cout << "Constructor using " << co << "called\n";
    commpany = co;
    if (n < 0) {
        std::cout << "Number of shares cannot be negative;" << commpany << "shares set to 0";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock() {
    std::cout << "bye"<< commpany <<"!\n"<<std::endl;
}

void Stock::buy(long num, double price) {
    if (num < 0) {
         std::cout << "Number of shares cannot be negative; transaction is abort" << std::endl;
    } else {
        shares += num;
    }
    share_val = price;
    set_tot();
}

void Stock::sell(long num, double pr) {
    if (num < 0) {
        std::cout<<"number of shares sold cannot be negative " 
            <<"transaction is abort\n";
    } else if (num > shares){
        std::cout<< " you cannot sell the shares more than you have"
            << " transaction is abort\n";
    } else {
        shares -= num;
        share_val = pr;
        set_tot();
    }
}

void Stock::update(double pr) {
    share_val = pr;
    set_tot();
}

void Stock::show() {
    using std::ios_base;
    using std::cout;
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout<<"company: "<< commpany
        <<"shares :"<<shares<<"\n"
        <<" share prices : $ "<<share_val;
    
    cout.precision(2);
    cout<<" total worth : $"<<total_val<<"\n";

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}


