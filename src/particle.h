//* particle.h
#pragma once

#include <random>
#include <iostream>

namespace molcompbs
{
  class particle
  {
    private:
      // variables
      double x, y, z;         // particle position
      std::mt19937 gen;       // Mersenne Twister engine
      std::normal_distribution<double> distribution; // normal distribution
      // functions
      void setVar(double &var, double in);  // set private variable
      double getVar(double &var);           // get private variable

    public:
      // constructor and destructor
      particle();                                 // default constructor at origin
      particle(double x0, double y0, double z0);  // constructor at x,y,z position
      particle(const particle &par);              // copy constructor
      ~particle();                                // destructor
      // particle position
      void setX(double xin);                          // set x position
      void setY(double yin);                          // set y position
      void setZ(double zin);                          // set z position
      void setPos(double xin, double yin, double zin);// set x,y,z position
      double getX();                                  // get x position
      double getY();                                  // get y position
      double getZ();                                  // get z position
      void printPos();                                // print position
      // random walk
      void step(double s);                        // random walk with standard deviation
      void step(double sx, double sy, double sz); // random walk with x,y,z standard deviation
      //TODO degradation
      //TODO binding
      //TODO drift
      //TODO anomalous diffusion
      //TODO phase separation
  };
}