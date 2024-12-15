# Orbital Mechanics:
![Application Architecture](images/orbital-mechanics-architecture.png)
This is an Orbital Mechanics Simulator, a project dedicated to emulating the complex dynamics of the N-body problem. The project starts with a simple two body problem providing; insights into orbital mechanics, astrophysics and celestial systems.

## Physx:
A simple physics engine written in C++ 14, tested using GTest, and built using CMake. The engine models the two body problem using Newtonian Physics.

## Boot Services:
I use a RaspberryPi 4 to act as a custom CI/CD server, the boot services highlight systmd processes that are set to start on boot, and to re-start after crash. This ensures that the github actions runner process is always active an listening with minimal setup. Using this setup gives me more control over the deployment environment.