//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_DWATRZY_H
#define ROBOCZY_DWATRZY_H

#include <iostream>
using namespace std;
class Parent {
  int i;
public:
  Parent(int ii) : i(ii) {
    cout << "Parent(int ii)\n";
  }
  Parent(const Parent& b) : i(b.i) {
    cout << "Parent(const Parent&)\n";
  }
  Parent() : i(0) { cout << "Parent()\n"; }
  friend ostream&
    operator<<(ostream& os, const Parent& b) {
    return os << "Parent: " << b.i << endl;
  }
};
class Member {
  int i;
public:
  Member(int ii) : i(ii) {
    cout << "Member(int ii)\n";
  }
  Member(const Member& m) : i(m.i) {
    cout << "Member(const Member&)\n";
  }
  friend ostream&
    operator<<(ostream& os, const Member& m) {
    return os << "Member: " << m.i << endl;
  }
};
class Child : public Parent {
  int i;
  Member m;
public:
  Child(int ii) : Parent(ii), i(ii), m(ii) {
    cout << "Child(int ii)\n";
  }
  friend ostream&
    operator<<(ostream& os, const Child& c){
    return os << (Parent&)c << c.m
              << "Child: " << c.i << endl;
  }
};
class Mem : public Child {
    Member m;
public:
    Mem(int ii) : Child(ii), m(ii){};
    Mem(const Mem& mm) : Child(10), m(mm.m){}
    Mem& operator=(const Mem& mm){
        m=mm.m;
        return *this;
    }
    friend ostream&
    operator<<(ostream& os, const Mem& c){
        return os << (Child&)c << c.m
                  << "Mem: " << c.m << endl;
    }
    ~Mem(){};
};

#endif //ROBOCZY_DWATRZY_H
