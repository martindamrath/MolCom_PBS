//* particle.cpp
#include "particle.h"

using namespace molcompbs;

// constructor and destructor
particle::particle() : x(0), y(0), z(0) { setRandomSeed(); }
particle::particle(double x0, double y0, double z0) : x(x0), y(y0), z(z0) { setRandomSeed(); }
particle::particle(const particle &par) : x(par.x), y(par.y), z(par.z), gen(par.gen), distribution(par.distribution) {}
particle::~particle() { }

// functions
void particle::setVar(double &var, double in) { var = in; }
double particle::getVar(double &var) { return var; }
void particle::setRandomSeed() { 
  std::random_device rd; 
  # pragma omp critical
  {
  if (rd.entropy() > 0.)
    gen.seed(rd()); 
  else {
    auto ref = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    while(ref == seed){
      seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    }
    gen.seed(static_cast<unsigned>(seed));
  }
  }
};

// particle position
void particle::setX(double xin) { particle::setVar(x, xin); }
void particle::setY(double yin) { particle::setVar(y, yin); }
void particle::setZ(double zin) { particle::setVar(z, zin); }

void particle::setPos(double xin, double yin, double zin) {
  particle::setX(xin);
  particle::setY(yin);
  particle::setZ(zin);
}

double particle::getX() { return particle::getVar(x); }
double particle::getY() { return particle::getVar(y); }
double particle::getZ() { return particle::getVar(z); }

void particle::printPos() {
  std::cout << "Particle position = [" << particle::getX() << "," << particle::getY() << "," << particle::getZ() << "]" << std::endl;
}

// random walk
void particle::step(double s) { particle::step(s, s, s); }
void particle::step(double sx, double sy, double sz) {
  x += sx * distribution(gen);
  y += sy * distribution(gen);
  z += sz * distribution(gen);
}