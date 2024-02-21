#include "src/transceiver.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace molcompbs;

int main() {

transceiver test;

cout << test.getX() << test.getY() << test.getZ() << endl;

random_device rd;

cout << rd() << " " << rd() << endl;

random_device rd2;

cout << rd2() << " " << rd2() << endl;

cout << rd.entropy() << endl;


cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count() << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;
cout << static_cast<unsigned int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count()) << endl;

//auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch());

}