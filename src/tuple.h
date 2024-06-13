class Tuple {
    public:
        // default constructor
        Tuple();

        // parameterized constructor
        Tuple(double x, double y, double z, int w);
        
        // overloaded + operator
        Tuple operator+(const Tuple& other);

        // getter methods
        double getX() { return x_; };
        double getY() { return y_; };
        double getZ() { return z_; };
        double getW() { return w_; };

    private:
        double x_;
        double y_;
        double z_;
        int w_;
};