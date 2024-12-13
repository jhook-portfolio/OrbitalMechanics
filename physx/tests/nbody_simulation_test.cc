#include <gtest/gtest.h>
#include "../src/nbody_simulation.h"

TEST(ConstantTest, DefaultInitialization) {
    EXPECT_DOUBLE_EQ(G, 6.67430e-11);
}

TEST(UpdateOrbitalPathFunctionTest, TwoBodySystem) {
    
    Body centralBody(1.989e30, 0, 0, 0, 0);
    Body orbitingBody(5.972e24, 1.496e11, 0, 0, 29780);

    std::vector<Body> bodies = {centralBody, orbitingBody};
    double dt = 1.0;

    update_orbital_path(bodies, dt);

    // Oribting body should have moved closer to the central body
    EXPECT_LT(bodies[1].x, 1.496e11);
}