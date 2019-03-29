#include <iostream>
#include "Draw.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    try {
        RysownikImplementacja r("test.obj");
        r.O.load(r.filename);
        r.O.print();
        r.init(100,"XY");
    }
    catch(std::string wyjatek){
        std::cerr << wyjatek << std::endl;
    }
    std::ofstream outfile("out.bmp", std::ofstream::binary);
    outfile << bmp;
    std::cout << "end." << std::endl;

    return 0;
}