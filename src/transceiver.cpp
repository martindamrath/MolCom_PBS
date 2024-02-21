//* transceiver.cpp
#include "transceiver.h"

using namespace molcompbs;

// constructor and destructor
transceiver::transceiver() : x(0), y(0), z(0), r(1), num(0), sum(0), transparent(false) { transceiver::update(); }
transceiver::transceiver(double xin, double yin, double zin, double rin, bool transparentin) : x(xin), y(yin), z(zin), r(rin), num(0), sum(0), transparent(transparentin) { transceiver::update(); }
transceiver::~transceiver() { }

// functions
void transceiver::update() {
  transceiver::setVar(xm, transceiver::getVar(x) - transceiver::getVar(r));
  transceiver::setVar(xp, transceiver::getVar(x) + transceiver::getVar(r));
  transceiver::setVar(ym, transceiver::getVar(y) - transceiver::getVar(r));
  transceiver::setVar(yp, transceiver::getVar(y) + transceiver::getVar(r));
  transceiver::setVar(zm, transceiver::getVar(z) - transceiver::getVar(r));
  transceiver::setVar(zp, transceiver::getVar(z) + transceiver::getVar(r));
  transceiver::setVar(rs, transceiver::getVar(r) * transceiver::getVar(r));    
}

// transceiver position, radius, type
void transceiver::setX(double xin) { transceiver::setVar(x, xin); transceiver::update(); }
void transceiver::setY(double yin) { transceiver::setVar(y, yin); transceiver::update(); }
void transceiver::setZ(double zin) { transceiver::setVar(z, zin); transceiver::update(); }
void transceiver::setR(double rin) { transceiver::setVar(r, rin); transceiver::update(); }
void transceiver::setType(bool transparentin) { transceiver::setVar(transparent, transparentin); }

void transceiver::setPos(double xin, double yin, double zin) { 
  transceiver::setX(xin);
  transceiver::setY(yin);
  transceiver::setZ(zin);
}

double transceiver::getX() { return transceiver::getVar(x); }
double transceiver::getY() { return transceiver::getVar(y); }
double transceiver::getZ() { return transceiver::getVar(z); }
double transceiver::getR() { return transceiver::getVar(r); }
bool transceiver::getType() { return transceiver::getVar(transparent); }

void transceiver::printDetails() {
  if ( transceiver::getType() )
    std::cout << "Transparent receiver ";
  else
    std::cout << "Absorbing receiver ";
  std::cout << "at [" << transceiver::getX() << "," << transceiver::getY() << "," << transceiver::getZ() << "] with radius " << transceiver::getR() << std::endl;
}

// particle count
void transceiver::setNum(int numin) { transceiver::setVar(num, numin); }
void transceiver::setSum(int sumin) { transceiver::setVar(sum, sumin); }
int transceiver::getNum() { return transceiver::getVar(num); }
int transceiver::getSum() { return transceiver::getVar(sum); }
void transceiver::clear() { transceiver::setNum(0); transceiver::setSum(0); }

// detection
//! template <typename T>
//! void transceiver::count(std::vector<T> &par) {}
//! function is defined in transceiver.h due to instantiation error

// release
//! template <typename T>
//! void transceiver::count(std::vector<T> &par) {}
//! function is defined in transceiver.h due to instantiation error