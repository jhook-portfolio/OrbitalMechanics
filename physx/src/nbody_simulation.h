#ifndef NBODY_SIMULATION_H
#define NBODY_SIMULATION_H  
#include <vector>
#include "../src/Body.h"

const double G = 6.67430e-11;

void update_orbital_path(std::vector<Body>& bodies, double dt);

#endif // NBODY_SIMULATION_H