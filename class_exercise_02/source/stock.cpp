#include <iostream>
#include "../header/stock.h"

Stock::Stock() {
    cout<<"default construct called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const string &co, long n, double pr) {
    cout<<"using construct "<<co<<"called\n";
    company = co;
    if (n < 0) {
        cout<<"the number of shares cannot be negative"
            <<company<<" shares set to be zero.\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock() {
    cout<<"Bye company"<<company<<"!\n";
}

void Stock::buy(long n, double pr) {
    if (n < 0) {
        cout<<"number of shares purchased cannot be negative"
            <<" transation is abort\n";
    } else {
        shares += n;
        share_val = pr;
        set_tot();
    }
}

void Stock::sell(long num, double pr) {
    if (num < 0) {
        cout<<"number of shares sold cannot be negative " 
            <<"transaction is abort\n";
    } else if (num > shares){
        cout<< " you cannot sell the shares more than you have"
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
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    streamsize prec = cout.precision(3);
    cout<<"company: "<<company
        <<"shares :"<<shares<<"\n"
        <<" share prices : $ "<<share_val;
    
    cout.precision(2);
    cout<<" total worth : $"<<total_val<<"\n";

    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}

