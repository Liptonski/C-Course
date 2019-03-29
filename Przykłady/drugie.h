//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_DRUGIE_H
#define ROBOCZY_DRUGIE_H

#include <iostream>

class A{
public:
    A() {};
};

class B{
public:
    B() {};
};

class C : public A{
public:
    B b;
};

class first{
public:
    first(){ std::cout << "1 Constructor\n"; };
    ~first(){ std::cout << "1 Destructor\n"; };
};

class second : first{
public:
    second(){ std::cout << "2 Constructor\n"; };
    ~second(){ std::cout << "2 Destructor\n"; };
};

class third : second{
public:
    third(){ std::cout << "3 Constructor\n"; };
    ~third(){ std::cout << "3 Destructor\n"; };
};

#endif //ROBOCZY_DRUGIE_H
