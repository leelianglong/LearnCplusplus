//
// Created by Administrator on 2020/9/20.
//
#include "iostream"
#include "../header/timer.h"

// 无参数的构造函数
Time::Time() {
    hours = minutes = 0;
}

// 有参数的构造函数
Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHour(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

// 参数定义成 Time& 表示引用类型，不直接写成 time,这种按值传递的原因是，提高效率
Time Time::Sum(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + sum.minutes / 60 + t.hours;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + sum.minutes / 60 + t.hours;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator-(const Time &t) const {
    Time diff;
    int tot1;
    int tot2;

    std::cout<<"hours="<<hours<<std::endl;
    std::cout<<"minutes="<<minutes<<std::endl;

    std::cout<<"t.hours="<<t.hours<<std::endl;
    std::cout<<"t.minutes="<<t.minutes<<std::endl;

    tot1 = t.minutes + t.hours * 60;
    tot2 = minutes + 60 * hours; // minutes hours实际上是重载操作符 - 的第一个参数中的值
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(int factor) const {
    Time result;
    long totalMintes = hours * factor * 60 + minutes * factor;
    result.hours = totalMintes / 60;
    result.minutes = totalMintes % 60;
    return  result;
}

void Time::Show() const {
    std::cout<<hours<<" hours,"<<minutes<<" minutes"<<std::endl;
}


