//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_OSIEMNASTE_H
#define ROBOCZY_OSIEMNASTE_H

#include <fstream>
using namespace std;
class Base3 {
  int i;
protected:
  int read() const { return i; }
  void set(int ii) { i = ii; }
public:
  Base3(int ii = 0) : i(ii) {}
  int value(int m) const { return m*i; }
};
class Derived : protected Base3 {
  int j;
public:
  Derived(int jj = 0) : j(jj) {}
  void change(int x) { set(x); }
  void call() { read(); }
};

class SpaceShip {
public:
    void fly() {};
};

class Shuttle : public SpaceShip {
public:
    void land () {};
};


#endif //ROBOCZY_OSIEMNASTE_H
