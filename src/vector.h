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

        // normalize vector
        Vector normalize();

        // dot product
        double dot(Vector& other);

        // cross product
        Vector cross(Vector& other);

    private:
};

#endif