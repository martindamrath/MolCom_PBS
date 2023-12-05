//* transceiver.h
//* point source with impulse release
//* spherical counting receiver
#pragma once

#include <vector>
#include <iostream>

namespace molcompbs 
{
  class transceiver 
  {
    private:
        // variables
        double x, y, z;                 // transceiver position
        double xm, xp, ym, yp, zm, zp;  // transceiver limits on x,y,z axis
        double r, rs;                   // radius, squared radius
        int num;                        // counted particles
        int sum;                        // accumulated number of received particles
        bool transparent;               // receiver type: transparent or fully absorbing receiver
        // functions
        template <typename T>
        void setVar(T &var, const T in); // set private variable
        template <typename T>
        T getVar(const T &var) const;    // get private variable
        void update();                   // update receiver limits

    public:
        // constructor and destructor
        transceiver();                                  // default constructor at origin, radius 1, and absorbing
        transceiver(double xin, double yin, double zin, double rin, bool transparentin); // constructor at x,y,z radius r, type
        ~transceiver();                                 // destructor
        // receiver position, radius, type
        void setX(double xin);                          // set x position
        void setY(double yin);                          // set y position
        void setZ(double zin);                          // set z position
        void setR(double rin);                          // set radius
        void setType(bool transparentin);               // set type
        void setPos(double xin, double yin, double zin);// set x,y,z position
        double getX();                                  // get x position
        double getY();                                  // get y position
        double getZ();                                  // get z position
        double getR();                                  // get radius
        bool getType();                                 // get type
        void printDetails();                            // print transceiver details
        // particle count
        void setNum(int numin);                         // set counted particles
        void setSum(int sumin);                         // set accumulated particle count
        int getNum();                                   // get particle count
        int getSum();                                   // get accumulated particle count
        void clear();
        // detection
        template <typename T>
        void count(std::vector<T> &par)                 // count particles
        {
          int count = 0;        // number of particles inside receiver
          int N = par.size();   // total number of particles
          double distance;      // distance between particle and receiver

          // create an iterator to keep track of the current position
          auto it = par.begin();

          // check all particles
          while (it != par.end())
          {
            // get the current particle
            T& p = *it;

            // rough check if particle is close to the receiver
            if (p.getX() >= xm && p.getX() <= xp &&
                p.getY() >= ym && p.getY() <= yp &&
                p.getZ() >= zm && p.getZ() <= zp)
            {
                
              // precise check
              distance = (p.getX() - x) * (p.getX() - x);
              distance += (p.getY() - y) * (p.getY() - y);
              distance += (p.getZ() - z) * (p.getZ() - z);

              if (distance <= rs)
              {
                // inside receiver
                count++;
                // delete particle for fully absorbing receiver
                if (!transparent) 
                {
                  it = par.erase(it);
                  it--;
                }
              } 
            }
            // next particle
            it++;
          }
          num = count;
          sum += count;
        };
        //TODO ligand receptor binding
        //TODO other shape than spherical
        // release
        template <typename T>
        void release(std::vector<T> &par, int N)          // point source impulse release
        {
          T particle(getVar(x), getVar(y), getVar(z));

          for (int n=0; n<N; n++)
            par.emplace_back(particle);
        };
        //TODO volumne source
        //TODO waveform release
  };
}