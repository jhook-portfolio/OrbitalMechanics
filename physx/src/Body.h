#ifndef BODY_H
#define BODY_H

struct Body {
    double mass;
    double x, y;
    double vx, vy;

    Body(double m = 0, double x = 0, double y = 0, double vx = 0, double vy = 0);
};

#endif // BODY_H
