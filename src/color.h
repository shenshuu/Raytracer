#ifndef COLOR_H
#define COLOR_H

#include "tuple.h"

class Color : public Tuple {
    public:
        // default constructor
        Color();

        // parameterized constructor
        Color(double r, double g, double b);

        // overloaded multiplication operator
        Color operator*(Color& other);  

        // overloaded equality operator
        bool operator==(Color& other);

    private:

};

#endif