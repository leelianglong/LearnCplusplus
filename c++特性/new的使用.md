new的应用一般有2个方面

1. 负责在堆上找到一段满足需要的内存块

2. 定位new运算符（placement new），它能够让程序员指定要使用的位置。既将new运算符用于提供了的地址,定位运算符直接使用传递给他的地址，它不负责判断那些内存块被使用，也不查找未使用的内存块。


```
#include <iostream>
#include <new>
#include <string>
using namespace std;


const int BUF_SIZE = 512;

class JustTest {
    private:
        string words;
        int number;
    public:
        JustTest(const string &s=" Just Testing ", int n = 0) {
            words = s;
            number = n;
            cout << words << " constructed\n";
        }
        ~JustTest() {
            cout << words << " destoyed\n";
        }
        void Show() const {
            cout<<words<<", "<<number<<endl;
        }
};




int main(int, char**) {
    char* buffer = new char[BUF_SIZE];
    JustTest* pc1, *pc2;

    pc1 = new (buffer) JustTest; // new是占用运算符，把对象放在buffer中，
    pc2 = new JustTest("heap1", 20);  // 把对象放在堆上。

    cout << "memory block address :\n"<<"buffer: "<< (void*)buffer<<"   heap:  "<<pc2<<endl;
    cout << "memory contents:\n";
    
    cout << pc1 << ": ";
    pc1->Show(); // 指针引用调用函数

    cout << pc2 << ": ";
    pc2->Show();

    JustTest *pc3, *pc4;
    pc3 = new (buffer)JustTest("bad idea", 6); // new是占用运算符，把对象放在buffer中，
    pc4 = new JustTest("heap2", 10);

    cout << "memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();

    cout << pc4 << ": ";
    pc4->Show();

    delete pc3;
    delete pc4;

    return 0;
}

代码的输出是：
PS E:\vscode_cplusplus_project\placenew1\build> .\placenew1.exe
 Just Testing  constructed
heap1 constructed
memory block address :
buffer: 0x3f7450   heap:  0x3f7658
memory contents:
0x3f7450:  Just Testing , 0
0x3f7658: heap1, 20
bad idea constructed
heap2 constructed
memory contents:
0x3f7450: bad idea, 6
0x3f7680: heap2, 10
bad idea destoyed
heap2 destoyed
PS E:\vscode_cplusplus_project\placenew1\build>
```
