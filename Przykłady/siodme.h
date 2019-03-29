//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_SIODME_H
#define ROBOCZY_SIODME_H
#include <iostream>
#include <string>
using namespace std;
class Base {
public:
    int f() const {
        cout << "Base::f()\n";
        return 1;
    }
    int f(string) const { return 1; }
    void g() {}
    void h() const { cout << "Base::h()\n";}
    int h(string) { return 3; };
    double h(char*) { return 2.0; }
};
class Derived1 : public Base {
public:
    void g() const {}
    float h(char*) {return 3.0;};
};
class Derived2 : public Base {
public:
    // Redefinition:
    int f() const {
        cout << "Derived2::f()\n";
        return 2;
    }
};
class Derived3 : public Base {
public:
    // Change return type:
    void f() const { cout << "Derived3::f()\n"; }
};
class Derived4 : public Base {
public:
    // Change argument list:
    int f(int) const {
        cout << "Derived4::f()\n";
        return 4;
    }
};
int siodzad() {
    string s("hello");
    Derived1 d1;
    int x = d1.f();
    d1.f(s);
    d1.h("dobrze");
//!    d1.h(); // zle
    Derived2 d2;
    x = d2.f();
//!  d2.f(s); // string version hidden
    Derived3 d3;
//!  x = d3.f(); // return int version hidden
    Derived4 d4;
//!  x = d4.f(); // f() version hidden
    x = d4.f(1);
} ///:~

#endif //ROBOCZY_SIODME_H
