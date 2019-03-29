//
// Created by michal on 25.04.18.
//

#ifndef PROJEKT_BMP_INTERPRETER_H
#define PROJEKT_BMP_INTERPRETER_H

#include <string>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <vector>
struct line{
    float x1,y1,x2,y2;
    unsigned char r,g,b;
    line(float a,float b,float c,float d, unsigned char e,unsigned char f, unsigned char G) :
            x1(a), y1(b), x2(c), y2(d), r(e), g(f), b(G) {};
};

struct circle{
    float x,y,R, a1,a2;
    unsigned char r,g,b;
    bool F;
    circle(float a,float b,float c,float d, float e,  bool t, unsigned char f,unsigned char G, unsigned char h) :
            x(a), y(b), R(c), a1(d), a2(e),F(t), r(f), g(G), b(h) {};
};

class Interpreter {
    std::vector<std::string*> data;
public:
    std::vector<line*> lines;
    std::vector<circle*> circles;
    Interpreter (const char* filename) {
        std::ifstream in(filename);
        if(!in.is_open()){
            std::cout << "Nie ma takiego pliku" << std::endl;
            return;
        }
        char buf[256];
        while(!in.eof()){
            in.getline(buf, 256);
            data.push_back(new std::string(buf));
        }
        for(int i=0; i<data.size(); i++){
            if(data[i]->c_str()[0]=='#'){
                continue;
            }
            else if (data[i]->c_str()[0]=='L'){
                float x1,x2,y1,y2;
                unsigned char r,g,b;
                sscanf(data[i]->c_str(), "L %f %f %f %f %c %c %c", &x1, &y1, &x2, &y2, &r, &g, &b);
                lines.push_back(new line(x1,y1,x2,y2,r,g,b));
            }
            else if (data[i]->c_str()[0]=='C'){
                float x,y,R;
                unsigned char r,g,b;
                sscanf(data[i]->c_str(), "C %f %f %f %c %c %c", &x, &y, &R, &r, &g, &b);
                circles.push_back(new circle(x,y,R,0.0,360.0,false,r,g,b));
            }
            else if (data[i]->c_str()[0]=='D'){
                float x,y,R;
                unsigned char r,g,b;
                sscanf(data[i]->c_str(), "D %f %f %f %c %c %c", &x, &y, &R, &r, &g, &b);
                circles.push_back(new circle(x,y,R,0.0,360.0,true,r,g,b));
            }
            else if (data[i]->c_str()[0]=='A'){
                float x,y,R, a1, a2;
                unsigned char r,g,b;
                sscanf(data[i]->c_str(), "A %f %f %f %f %f %c %c %c", &x, &y, &R, &a1, &a2, &r, &g, &b);
                circles.push_back(new circle(x,y,R,a1,a2,false,r,g,b));
            }
            else if (data[i]->c_str()[0]=='S'){
                float x,y,R, a1, a2;
                unsigned char r,g,b;
                sscanf(data[i]->c_str(), "S %f %f %f %f %f %c %c %c", &x, &y, &R, &a1, &a2, &r, &g, &b);
                circles.push_back(new circle(x,y,R,a1,a2,true,r,g,b));
            }
        }
    }
    ~Interpreter() {
        for(int i=0;i<lines.size();i++)
            delete lines[i];
        for(int i=0;i<circles.size();i++)
            delete circles[i];
        for(int i=0;i<data.size();i++)
            delete data[i];
    }
};


#endif //PROJEKT_BMP_INTERPRETER_H
