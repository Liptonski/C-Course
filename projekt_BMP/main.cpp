#include "Rysownik.h"

//Poprawiona wersja tylko nie wiem czemu kolory nie dzialaja poprawnie

int main(int argc, char* argv[]){
    RysownikImplementacja r("test.txt");
    r.init();
    std::ofstream outfile("out.bmp", std::ofstream::binary);
    outfile << bmp;
    std::cout << "end." << std::endl;
    return 0;
}

