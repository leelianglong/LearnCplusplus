//
// Created by Administrator on 2020/9/20.
//

#ifndef OPERATE_OVER_LOAD_TIMER_H
#define OPERATE_OVER_LOAD_TIMER_H
class Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHour(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time &t) const;
    Time operator+(const Time &t) const; // 对+进行重载
    Time operator-(const Time &t) const; // 对-进行重载
    Time operator*(int factor) const; // 对*进行重载
    void Show() const;
};
#endif //OPERATE_OVER_LOAD_TIMER_H
