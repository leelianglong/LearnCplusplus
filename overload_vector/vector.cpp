#include <cmath>
#include "vector.h"

using std::sin;
using std::sqrt;
using std::atan;
using std::atan2;
using std::cout;


namespace VECTOR {
    const double radToDeg = 45.0 / atan(1.0);

    void Vector::SetMag() {
        mag = sqrt(x * x + y * y);
    }

    void Vector::SetAng() {
        if (x == 0.0 && y == 0.0) {
            ang = 0.0;
        } else {
            ang = atan2(y, x);
        }
    }
     void Vector::SetX() {
         x = mag * cos(ang);
     }

     void Vector::SetY() {
         y = mag * sin(ang);
     }

     Vector::Vector() {
         x=y=mag=ang=0.0;
         mode = RECT;
     }

     Vector::Vector(double n1, double n2, Mode form) {
         mode = form;
         if (form == RECT) {
             x = n1;
             y = n2;
             SetMag();
             SetAng();
         } else if (form == POL) {
             mag = n1;
             ang = n2 / radToDeg;
             SetX();
             SetY();
         } else {
             cout << "incorrect 3rd argurent to Vector()...";
             cout << "vector set to 0\n";
             x = y = mag = ang = 0.0;
             mode = RECT;
         }
     }

     void Vector::Reset(double n1, double n2, Mode form) {
         mode = form;
         if (form == RECT) {
             x = n1;
             y = n2;
             SetMag();
             SetAng();
         } else if (form == POL) {
             mag = n1;
             ang = n2 / radToDeg;
             SetX();
             SetY(); 
         } else {
             cout << "incorrect 3rd argument to vector ...";
             cout << "vector set to 0 \n";
             x = y = mag = ang = 0.0;
             mode = RECT;
         }
     }

     Vector::~Vector() {

     }

     void Vector::PolarMode() {
         mode = POL;
     }

     void Vector::RectMode() {
         mode = RECT;
     }

     Vector Vector::operator+(const Vector & b) const {
         return Vector(x + b.x, y + b.y);
     }

     Vector Vector::operator-(const Vector & b) const {
         return Vector(x - b.x, y - b.y);
     }

     Vector Vector::operator-() const {
         return Vector(-x, -y);
     }

     Vector Vector::operator*(double n) const {
         return Vector(n * x, n * y);
     }

     Vector operator*(double n, const Vector & a) {
         return a * n;
     }

     std::ostream & operator<<(std::ostream & os, const Vector & v) {
         if (v.mode == Vector::RECT) {
             os<<"(x,y) = (" << v.x << ", " << v.y << ")";
         } else if (v.mode == Vector::POL) {
             os<<"(m,a) = (" << v.mag << ", " << v.ang * radToDeg << ")";
         } else {
             os << "Vector object mode is invalid";
         }
         return os;
     }
}