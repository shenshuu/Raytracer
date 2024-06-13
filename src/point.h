#include "tuple.h"

class Point : public Tuple {
    public:
        Point();
        Point(double x, double y, double z);

    private:
        double x_;
        double y_;
        double z_;
};