#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "tuple.h"

struct Tuple tuple(double x, double y, double z, int w) {
    struct Tuple t;
    (t).x = x;
    (t).y = y;
    (t).z = z;
    (t).w = w;
    return t;
}

Point point(double x, double y, double z) {
    return tuple(x, y, z, 1);
}

Vector vector(double x, double y, double z) {
    return tuple(x, y, z, 0);
}

struct Tuple add(struct Tuple *a, struct Tuple *b) {
    struct Tuple c;
    c.x = (*a).x + (*b).x;
    c.y = (*a).y + (*b).y;
    c.z = (*a).z + (*b).z;
    c.w = (*a).w + (*b).w;
    return c;
}

struct Tuple sub(struct Tuple *a, struct Tuple *b) {
    struct Tuple c;
    c.x = (*a).x - (*b).x;
    c.y = (*a).y - (*b).y;
    c.z = (*a).z - (*b).z;
    c.w = (*a).w - (*b).w;
    return c;
}

struct Tuple neg(struct Tuple *t) {
    struct Tuple w;
    w.x = -(*t).x;
    w.y = -(*t).y;
    w.z = -(*t).z;
    w.w = -(*t).w;
    return w;
}

struct Tuple mul(struct Tuple *t, const double c) {
    struct Tuple w;
    w.x = (*t).x * c;
    w.y = (*t).y * c;
    w.z = (*t).z * c;
    w.w = (*t).w * c;
    return w;
}

double mag(struct Tuple *t) {
    return sqrt((*t).x * (*t).x + (*t).y * (*t).y + (*t).z * (*t).z + (*t).w * (*t).w);
}

struct Tuple norm(struct Tuple *t) {
    return mul(t, 1.0 / mag(t));
}

void printTuple(struct Tuple *t) {
    printf("( %lf, %lf, %lf, %d )\n", (*t).x, (*t).y, (*t).z, (*t).w);
}

int main(void) {
    Vector v = vector(1, 2, 3);
    Vector w = norm(&v);
    printTuple(&w);
    return 0;
}