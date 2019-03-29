//
// Created by michal on 26.04.18.
//

#ifndef ROBOCZY3_SZOSTE_H
#define ROBOCZY3_SZOSTE_H

#include <iostream>
#include <vector>

class Rodent {
public:
    Rodent(){}
    virtual ~Rodent(){std::cout << "rodent dcor" << std::endl;}
    virtual void RodentBase()=0;
};

class Mouse : public Rodent{
public:
    Mouse(){}
    virtual ~Mouse(){std::cout << "mouse dcor" << std::endl;}
    void RodentBase() {std::cout << "mouse fun" << std::endl;}
};

class Gerbil : public Mouse{
public:
    Gerbil(){}
    virtual ~Gerbil(){std::cout << "gerbil dcor" << std::endl;}
    void RodentBase(){std::cout << "gerbil fun" << std::endl;}
};

class Hamster : public Gerbil{
public:
    Hamster(){}
    virtual ~Hamster(){std::cout << "hamster dcor" << std::endl;}
    void RodentBase(){std::cout << "hamster fun" << std::endl;}
};

class BlueHamster : public Hamster{
    BlueHamster(){}
    ~BlueHamster(){}
    void RodentBase(){std::cout << "blue fun" << std::endl;}
};



#endif //ROBOCZY3_SZOSTE_H
