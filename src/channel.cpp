//* channel.cpp
#include "channel.h"

using namespace molcompbs;

// constructor and destructor
channel::channel() : D(0), dt(1), T(0), stddev(0), N(0) { }
channel::~channel() { }

// functions
void channel::setstddev() { channel::setVar(stddev, sqrt( 2. * channel::getVar(dt) * channel::getVar(D) )); }

// set/get parameter
void channel::setD(double Din) { channel::setVar(D, Din); channel::setstddev(); }
void channel::setdt(double dtin) { channel::setVar(dt, dtin); channel::setstddev(); }
void channel::setT(double Tin) { channel::setVar(T, Tin); }  
void channel::setN(int Nin) { channel::setVar(N, Nin); }  
void channel::setBit(std::vector<bool> bitin) { channel::setVar(bitseq, bitin); }
double channel::getD() { return channel::getVar(D); }                       
double channel::getdt() { return channel::getVar(dt); }
double channel::getT() { return channel::getVar(T); }
int channel::getN() { return channel::getVar(N); }
double channel::getstddev() { return channel::getVar(stddev); }
std::vector<bool> channel::getBit() { return channel::getVar(bitseq); }
// create transmitter/receiver
void channel::setTX(double xin, double yin, double zin) { TX.setPos(xin, yin, zin); }
void channel::setRX(double xin, double yin, double zin, double rin, bool transparentin) {
    RX.setPos(xin, yin, zin);
    RX.setR(rin);
    RX.setType(transparentin);
}
// simulation
void channel::propagation() {
    int Npar = particles.size();
    for (int n=0; n<Npar; n++) particles[n].step(stddev);
}
std::vector<int> channel::simulate() {
    int Nbit = bitseq.size();
    int Nsteps = static_cast<int> (1. * Nbit * T / dt) + 1;
    std::vector<int> Nrec(Nsteps);
    std::vector<int> Nrel;
    int relcnt = 0;

    // get release points
    for (int n=0; n<Nbit; n++)
        if (bitseq[n]) Nrel.emplace_back(static_cast<int> (1. * n * T / dt));
    Nrel.emplace_back(-1);

    // all time steps
    for (int n=0; n<Nsteps; n++)
    {
        // propagation
        propagation();

        // release
        if (n == Nrel[relcnt])
        {
            relcnt++;
            TX.release(particles, N);
        }

        // detection
        RX.count(particles);
        Nrec[n] = RX.getNum();
    }

    return Nrec;
}