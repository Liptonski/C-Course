//#include "drugie.h"
#include "czwarte.h"
//#include "szoste.h"
#include "siodme.h"
#include "trzynaste.h"
#include "pietnaste.h"
#include "osiemnaste.h"
#include "dwajeden.h"
#include "dwatrzy.h"

class vehicle{
    int year;
public:
    vehicle(int y) : year(y){};
    ~vehicle() {};
    void insure() const {};
};

class Engine {
public:
    void start() const {}
    void rev() const {}
    void stop() const {}
};
class Wheel {
public:
    void inflate(int psi) const {}
};
class Window {
public:
    void rollup() const {}
    void rolldown() const {}
};
class Door {
public:
    Window window;
    void open() const {}
    void close() const {}
};
class Car : public vehicle {
public:
    Car(int y) : vehicle(y){}
    ~Car() {};
    Engine engine;
    Wheel wheel[4];
    Door left, right;
    void insure() const {
        vehicle::insure();
    }
};
int main() {
    Car car(2005);
    car.left.window.rollup();
    car.wheel[0].inflate(72);
    //C c;
    //third t;
    //D d(1);
    //Derived3 d3;

    //siodzad();

    //Chess d1;
    //Chess d2(d1);

    //der d1;
    //d1.bar(5);
    //d1.foo();

    //der1 d1;
    //der2 d2;
    //!nie dziala fun(d1);
    //!tez nie fun(d2);

    Derived d(10);
    d.call();
//!nie da sie    d.value(10);
    Shuttle s;
    SpaceShip &ss = s;
//!nie ma takiej metody    ss.land()

    //Wind w;
    //tune(w);

    Mem m(10);
} ///:~ 