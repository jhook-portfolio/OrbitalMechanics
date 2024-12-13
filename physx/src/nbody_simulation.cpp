#include <cmath>
#include "../src/nbody_simulation.h"

void update_orbital_path(std::vector<Body>& bodies, double dt) {
    for (size_t i = 0; i < bodies.size(); i++) {
        double ax = 0, ay = 0; // Acceleration components for body i
        for (size_t j = 0; j < bodies.size(); j++) {
            if (i != j) {
                // Compute distance components
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;

                // Calculate distance (r)
                double r = std::sqrt(dx * dx + dy * dy);

                // Avoid division by zero and prevent forces from blowing up
                if (r > 1e-5) {
                    // Gravitational force magnitude
                    double force = G * bodies[i].mass * bodies[j].mass / (r * r);

                    // Decompose force into x and y components
                    ax += force * dx / (r * bodies[i].mass);
                    ay += force * dy / (r * bodies[i].mass);
                }
            }
        }

        // Update velocity of body i
        bodies[i].vx += ax * dt;
        bodies[i].vy += ay * dt;
    }

    // Update positions of all bodies
    for (auto& body : bodies) {
        body.x += body.vx * dt;
        body.y += body.vy * dt;
    }
}