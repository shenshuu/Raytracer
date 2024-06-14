#ifndef CANVAS_H
#define CANVAS_H
#include "color.h"
#include <vector>

class Canvas {
    public:
        // default constructor
        Canvas();

        // parameterized constructor
        Canvas(int width, int height);

        // write pixels to a canvas
        void write_pixel(int r, int c, Color color);

        // returns pixel at specific position
        Color pixel_at(int r, int c);

        // write to PPM file
        void to_ppm();

    private:
        std::vector<std::vector<Color> > canvas_;
        int width_;
        int height_;

};

#endif