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

void Apple::add(int num)
{
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

上面代码的运行结果：

![运行结果](https://github.com/leelianglong/LearnCplusplus/blob/master/icon/class.PNG)

运行结果：
+ struct function execute
+ getCount function execute
+ take function, num=1
+ const function execte
+ take function, num=1
+ 2
+ non const function execte
+ take function, num=10
+ struct function execute
+ const function execte
+ take function, num=100
+ 请按任意键继续. . .

### 本段程序说明

1. const可以在类中修饰成员变量，也可以修饰方法。如上面代码所示，修饰方法时，const在方法最后写，修饰变量时，写在变量前面。

2. const对象只能访问const的成员变量和成员函数，非const的对象可以访问任意的成员变量和函数。同样的一个const的方法也只能调用其他const的方法，不能调用非const的方法

3. 定义一个对象时，最先执行的是这个类的构造函数，如上面运行结果所示。

4. ::的作用有下面几个：
  + ：：是作用域操作符，void A::f() 表示 f是 类A中的方法
  + 全局作用域符号.当全局变量在局部函数中与其中某个变量重名，那么就可以用::来区分。 ：： int global_variable_name;
  + 作用域分解符，当一个类中定义了一个方法，但是没有给出实现，则可以在外面给出实现。 如上图中所有的方法都是这种写法 void Apple::add(int num)
  + 引用类中的方法，如System::Math::Sqrt()。
  
5. :的作用
  * 继承性， 子类：父类
  * 对类中const 成员变量的初始化 Apple::Apple(int i):apple_number(i) 这里就是把i赋值给const变量apple_number

