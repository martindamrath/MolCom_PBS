//* channel.h
#pragma once

#include <vector>
#include <cmath>
#include <random>
#include "transceiver.h"
#include "particle.h"


namespace molcompbs
{
  class channel
  {
    private:
      // variables
      double D;               // diffusion coefficient
      double dt;              // simulation step size
      double T;               // symbol duration
      double Toff;            // time offset
      double stddev;          // random walk standard deviation
      double stddevoff;       // random walk standard deviation for time offset
      int N;                  // number of particles released for bit 1 (OOK)
      std::vector<bool> bitseq;    // bitsequence
      transceiver TX;         // transmitter
      transceiver RX;         // receiver
      std::vector<particle> particles;     // particles
      //TODO multiple transmitter and receiver
      //TODO other modulation schemes 
      // functions
      template <typename T>
      void setVar(T &var, const T in) { var = in; }; // set private variable
      template <typename T>
      T getVar(const T &var) const { return var; };  // get private variable
      void setstddev();                     // set standard deviation
      void setstddevoff();                  // set standard deviation for time offset

    public:
      // constructor and destructor
      channel();                            // default constructor at origin
      ~channel();                           // destructor
      // set/get parameters
      void setD(double Din);                // set diffusion coefficient
      void setdt(double dtin);              // set simulation step size
      void setT(double Tin);                // set symbol duration
      void setToff(double Toffin);          // set time offset
      void setN(int Nin);                   // set number of particles released for bit-1
      void setBit(std::vector<bool> bitin); // set bit sequence
      double getD();                        // get diffusion coefficient
      double getdt();                       // get simulation step size
      double getT();                        // get symbol duration
      int getN();                           // get number of particles released for bit-1
      double getstddev();                   // get random walk standard deviation
      double getstddevoff();                // get random walk standard deviation for time offset
      std::vector<bool> getBit();           // get bit sequence
      // create transmitter/receiver
      void setTX(double xin, double yin, double zin);
      void setRX(double xin, double yin, double zin, double rin, bool transparentin);
      // simulation
      std::vector<bool> random_bits(int Kin); // create random bit sequence
      void propagation();                   // propagation of all particles
      std::vector<int> simulate();          // simulate
      //TODO drift, anomalous diffusion,...
  };
}