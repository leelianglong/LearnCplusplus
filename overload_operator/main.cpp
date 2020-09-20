#include <iostream>
#include "./header/timer.h"

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    Time planning;
    Time coding(2, 50);
    Time fixbugs(5, 55);
    Time total;
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time diff;
    Time adjust;


    cout<<"plan time=";
    planning.Show();
    cout<<endl;

    cout<<"code time=";
    coding.Show();
    cout<<endl;

    cout<<"fixbugs time=";
    fixbugs.Show();
    cout<<endl;

    total = coding.Sum(fixbugs); // 注意这里定义的引用类型的，可以传递对象进来，这个&和C语言中含义的不一样。
    cout<<"coding.sum(fixbugs)=";
    total.Show();
    cout<<endl;

    cout<<"using operate + overload"<<endl;
    total = coding.operator+(fixbugs);
    total.Show();
    cout<<endl;

    cout<<"using + overload"<<endl;
    total = coding + fixbugs; // 对 + 进行重载，这个 + 直接可以对2个对象进行操作
    total.Show();
    cout<<endl;

    cout<<"weeding time"<<endl;
    weeding.Show();
    cout<<endl;

    cout<<"waxing time"<<endl;
    waxing.Show();
    cout<<endl;

    cout<<"using operator -"<<endl;
    diff = weeding - waxing;
    diff.Show();
    cout<<endl;

    cout<<"using operator *"<<endl;
    adjust = total * 3;
    adjust.Show();
    cout<<endl;

    return 0;
}
