//
// Created by michal on 26.04.18.
//

#ifndef ROBOCZY3_CZWARTE_H
#define ROBOCZY3_CZWARTE_H

class A {
    int i;
public:
    A(int ii) : i(ii) {}
    ~A() {}
    virtual void f() const {}
};
class B {
    int i;
public:
    B(int ii) : i(ii) {}
    ~B() {}
    virtual void f() const {}
};
class C : public B {
    A a;
public:
    C(int ii) : B(ii), a(ii) {}
    ~C() {} // Calls ~A() and ~B()
    void f() const {  // Redefinition
        a.f();
        B::f();
    }
};

#endif //ROBOCZY3_CZWARTE_H
