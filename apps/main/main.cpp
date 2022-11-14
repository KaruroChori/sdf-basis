#include <iostream>
#include <fstream>
#include <sketch.h>

int main(int argc, const char* argv[]){
    if(argc!=4){
        std::cerr<<"Wrong usage: "<<argv[0]<<" <filename> <x> <y>\n";
        return -1;
    }

    sketch sk;

    std::ifstream file(argv[1], std::ifstream::in);
    file>>sk;
    file.close();

    //std::cout<<sk;
    point_t pt = {std::stod(argv[2]),std::stod(argv[3])};

    return (sk(pt)>=0)?1:0;
}
