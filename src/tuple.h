#ifndef TUPLE_H
#define TUPLE_H

class Tuple {
    public:
        // default constructor
        Tuple();

        // parameterized constructor
        Tuple(double x, double y, double z, int w);
        
        // overloaded + operator
        Tuple operator+(const Tuple& other);

        // overloaded - operator
        Tuple operator-(const Tuple& other);

        // overloaded == operator
        bool operator==(const Tuple& other);

        // getter methods
        double getX() { return x_; };
        double getY() { return y_; };
        double getZ() { return z_; };
        double getW() { return w_; };

        // negate tuple
        Tuple neg();

        // scale tuple
        Tuple scale(double c);

        // debugger function
        void print();

    private:
        double x_;
        double y_;
        double z_;
        int w_;
};

#endif