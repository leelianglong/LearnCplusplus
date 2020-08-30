### 代码
```
#include <iostream>
using namespace std;

class Apple {
    private:
        int people[100];
    public:
        Apple(int i); // 构造函数
        const int apple_number;
        void take(int num) const; // 表明这个方法是const的
        void add(int num); // 下面有2个函数重载
        void add(int num) const;
        int getCount() const;
};

Apple::Apple(int i):apple_number(i) // 这里：的作用是给const类型的成员变量 apple_number 赋初值，把i赋值给apple_number.
{
    cout<<"struct function execute"<<endl;
}

void Apple::add(int num){
    cout << "non const function execte" << endl;
    take(num); // 这里take不需要类型限定符Apple,是因为类中优先调自己的成员变量。
}

void Apple::add(int num) const 
{
    cout << "const function execte" << endl;
    take(num);
}

void Apple::take(int num) const 
{
    cout << "take function, num=" << num << endl;
}

int Apple::getCount() const 
{
    cout << "getCount function execute"<< endl;
    take(1);
    add(1); 
    return apple_number;
}


int main(void)
{
    Apple a(2); // 这里定义一个非const Apple类，并初始化了apple_number=2.
    cout << a.getCount() << endl;
    a.add(10);

    const Apple b(3); // 这里定义了一个const 类型的类 Apple，并初始化了app_number=3.
    b.add(100);
    system("pause");
    return 0;
}
```

### const 在类中使用

1、const可以在类中修饰成员变量，也可以修饰方法。如下：


2、const对象只能访问const的成员变量和成员函数，非const的对象可以访问任意的成员变量和函数。

