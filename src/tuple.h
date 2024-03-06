#ifndef TUPLE_H
#define TUPLE_H

struct Tuple {
    double x;
    double y;
    double z;
    int w;
};

typedef struct Tuple Point;
typedef struct Tuple Vector;

// constructor methods
struct Tuple tuple(double x, double y, double z, int w);
Point point(double x, double y, double z);
Vector vector(double x, double y, double z);

// operations
struct Tuple cross(struct Tuple *a, struct Tuple *b);
struct Tuple add(struct Tuple *a, struct Tuple *b);
struct Tuple sub(struct Tuple *a, struct Tuple *b);
struct Tuple mul(struct Tuple *t, const double c);
struct Tuple neg(struct Tuple *t);
struct Tuple norm(struct Tuple *t);

double dot(struct Tuple *a, struct Tuple *b);
double mag(struct Tuple *t);

// helper methods 
void printTuple(struct Tuple *t);

#endif