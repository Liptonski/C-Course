#include <iostream>
#include "czwarte.h"
#include "szoste.h"

class Shape {
public:
    Shape(){};
    virtual void draw() {std::cout << "base" << std::endl;};
};


class Circle : public Shape {
    void draw(){std::cout << "circle" << std::endl;}
};

class Square : public Shape{
    void draw(){std::cout << "square" << std::endl;}
};

class Triange : public Shape {
    void draw() {std::cout << "triangle" << std::endl;}
};

void fun(Shape &s){
    s.draw();
}

int main() {
    Circle c;
    Square sq;
    Triange t;
    Shape *s[3] = {&c, &sq, &t};
    for(int i=0; i<3; i++){
        s[i]->draw();
    }
    fun(c);

    C cc(2);
    B *b = &cc;
    b->f();

    Mouse m;
    Gerbil g;
    Hamster h;
    std::vector<Rodent*> r;
    r.push_back(&m);
    r.push_back(&g);
    r.push_back(&h);

    Rodent *rr = new Hamster();
    delete rr;

    for(int i=0; i<3; i++) {
        r[i]->RodentBase();
    }
    return 0;
}