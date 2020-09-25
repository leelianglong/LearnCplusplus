#include <iostream>
#include <ctime>
#include <cstdlib>
#include "vector.h"


int main() {
    using namespace std;
    using namespace VECTOR;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    cout<<"Enter target distance (q to quit) ";
    while (cin >> target) { // cin能够自动识别到是否是后面需要存储的类型，然后把它存储在后面的变量中，如果类型不符合，就退出
        cout << "Enter step length: ";
        if (!(cin >> dstep)) {
            break;
        }

        while (result.magval() < target) {
            direction = rand() % 360;
            step.Reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++; 
        }
        cout << "After " << steps << " steps, the subject  "
            "has the following location :\n";
        cout << result << endl;
        result.PolarMode();
        cout << "or\n" << result << endl;
        cout << "average outward distance per step = "
            << result.magval() / steps <<endl;
        steps = 0;
        result.Reset(0.0, 0.0);
        cout << "Enter target distance (q to quit):";
    }
    cout << "Byte !\n";
    cin.clear();
    while (cin.get() != '\n') { // 读取所有的输入的字符串，直到遇到换行符。
        continue;
    }
    return 0;
}
