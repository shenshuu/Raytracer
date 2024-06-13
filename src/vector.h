#ifndef VECTOR_H
#define VECTOR_H
#include "tuple.h"

class Vector : public Tuple {
    public:
        // default constructor
        Vector();

        // parameterized constructor
        Vector(double x, double y, double z);
        
        // magnitude of vector
        double mag();

    private:
};

#endif