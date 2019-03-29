//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_DZIEWIATE_H
#define ROBOCZY_DZIEWIATE_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class StringVector : public std::vector<void*> {

public:
    void push_back(string* s){
        vector<void*>::push_back(s);
    }
    string* operator [] (size_type n){
        return (string*) vector<void*>::operator[](n);
    };
};

class ten {
    long i;
public:
    ten(long ii):i(ii){};
    ~ten(){};
};

class Asteroid : public vector {
};

#endif //ROBOCZY_DZIEWIATE_H
