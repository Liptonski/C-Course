//
// Created by michal on 27.05.18.
//

#ifndef WAVE_OBJCLASS_H
#define WAVE_OBJCLASS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class point {
public:
    float x,y,z;
    point(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}
};

class face {
public:
    unsigned int index[3];
    face(unsigned int t1, unsigned int t2, unsigned int t3){
        index[0]=t1;
        index[1]=t2;
        index[2]=t3;
    }
};

class Object {
public:
    std::vector<point*> p;
    std::vector<face*> f;
    std::vector<std::string*> s;
    Object (){}
    virtual ~Object(){
        for(int i=0;i<p.size();i++)
            delete p[i];
        for(int i=0;i<f.size();i++)
            delete f[i];
        for(int i=0;i<s.size();i++)
            delete s[i];
    }
    void load(const char* filename){
        std::ifstream in(filename);
        if(!in.is_open()){
            std::string wyjatek = "nie ma takiego pliku";
            throw wyjatek;
        }
        char buf[256];
        while(!in.eof()){
            in.getline(buf, 256);
            s.push_back(new std::string(buf));
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]->c_str()[0]=='#') continue;
            else if (s[i]->c_str()[0]=='v'){
                float x, y, z;
                sscanf(s[i]->c_str(), "v %f %f %f", &x, &y, &z);
                p.push_back(new point(x,y,z));
            }
            else if (s[i]->c_str()[0]=='f'){
                unsigned  int xx, yy, zz;
                sscanf(s[i]->c_str(), "f %d %d %d", &xx, &yy, &zz);
                f.push_back(new face(xx,yy,zz));
            }
        }
    }
    void print(){
        for(int i=0; i<p.size(); i++){
            std::cout << p[i]->x<<" " << p[i]->y<< " " << p[i]->z << std::endl;
        }
    }
};

#endif //WAVE_OBJCLASS_H
