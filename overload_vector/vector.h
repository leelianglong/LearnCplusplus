#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

namespace VECTOR {
    class Vector {
        public:
            enum Mode {RECT, POL};
        private:
            double x;
            double y;
            double mag;
            double ang;
            Mode mode;

            void SetMag();
            void SetAng();
            void SetX();
            void SetY();
        public:
            Vector();
            Vector(double n1, double n2, Mode form = RECT);
            void Reset(double n1, double n2, Mode form = RECT);
            ~Vector();
            double Xval() const { return x; }
            double Yval() const { return y; }
            double magval() const { return mag; }
            double Angval() const { return ang; }
            void PolarMode();
            void RectMode();
            
            Vector operator+(const Vector &b) const;
            Vector operator-(const Vector &b) const;
            Vector operator-() const;
            Vector operator*(double n) const;

            friend Vector operator*(double n, const Vector & a);
            friend std::ostream & operator << (std::ostream & os, const Vector & v);
    };
}



#endif
