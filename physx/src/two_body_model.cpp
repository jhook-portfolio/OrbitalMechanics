#include <iostream>
#include <vector> 
#include "../src/two_body_model.h"

void two_body_model() {
    // Declare bodies and store them in a vector
    Body centralBody(1.989e30, 0, 0, 0, 0);
    Body orbitingBody(5.972e24, 1.496e11, 0, 0, 29780);
    std::vector<Body> bodies = {centralBody, orbitingBody};

    // stepper (seconds)
    double dt = 60;

    // simulate a year of orbit as 365 days in seconds
    for (int t = 0; t < 365 * 24 * 3600; t += dt){
        update_orbital_path(bodies, dt);
        std::cout << "Orbiting Body Position: (" << bodies[1].x << ", " << bodies[1].y <<")" << std::endl;
    }
}