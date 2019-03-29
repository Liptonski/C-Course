//
// Created by michal on 26.04.18.
//

#ifndef ROBOCZY3_JEDENASTE_H
#define ROBOCZY3_JEDENASTE_H

#include <vector>
#include<iostream>

class Aircraft {
public:
    Aircraft(){}
    virtual ~Aircraft(){}
    virtual void fly(){}
};

class Airbus : public Aircraft {
public:
    Airbus(){}
    virtual ~Airbus(){}
};

class Tower {
public:
    std::vector<Aircraft*> planes;
    /*for(int i=0; i<planes.size(); i++){

    }*/
};

#endif //ROBOCZY3_JEDENASTE_H
