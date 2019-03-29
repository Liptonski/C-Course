//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_CZWARTE_H
#define ROBOCZY_CZWARTE_H

#include <iostream>

class A {
    int i;
public:
    A(int ii) : i(ii) { std::cout << "A Constructor\n"; }
    ~A() { std::cout << "A Destructor\n"; }
    void f() const {}
};
class B {
    int i;
public:
    B(int ii) : i(ii) { std::cout << "B Constructor\n"; }
    ~B() { std::cout << "B Destructor\n"; }
    void f() const {}
};
class C : public B {
    A a;
public:
    C(int ii) : B(ii), a(ii) { std::cout << "C Constructor\n"; }
    ~C() { std::cout << "C Destructor\n"; }
    void f() const {
        a.f();
        B::f();
    }
};

class E {
    int i;
public:
    E(int ii) : i(ii) { std::cout << "E Constructor\n"; }
    ~E() { std::cout << "E Destructor\n"; }
};

class D : public B{
    C c;
public:
    D(int ii) : B(ii), c(ii){ std::cout << "D Constructor\n"; }
    ~D(){ std::cout << "D Destructor\n"; }
};

#endif //ROBOCZY_CZWARTE_H
