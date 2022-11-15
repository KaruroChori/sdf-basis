#include <iostream>
#include <fstream>
#include <sketch.h>

//To ensure boundary points are inside.
//Just to make sure this code is passing tests without dealing with floating point issues.
const double epsilon = 1e-3;

int main(int argc, const char* argv[]){
    if(argc!=4){
        std::cerr<<"Wrong usage: "<<argv[0]<<" <filename> <x> <y>\n";
        return -1;
    }
    
    sketch sk;

    std::ifstream file(argv[1], std::ifstream::in);
    if(!file.is_open()){
        std::cerr<<"This file cannot be open\n";
        return -2;
    }

    try{
        file>>sk;
    }
    catch(const char * str){
        std::cerr<<str;
        return -3;
    }

    file.close();

    glm::vec2 pt = {std::stod(argv[2]),std::stod(argv[3])};

    std::cout<<"Point "<<pt.x<<","<<pt.y<<" is "<<((sk(pt)-epsilon>=0)?"OUTSIDE":"INSIDE")<<" the shape\n";

    //Rasterization for test.
    /*for(int i=0;i<200;i++){
        for(int j=0;j<200;j++){
            std::cout<<(sk({j*150,i*150})>0);
        }
        std::cout<<"\n";
    }*/
    return (sk(pt)>0)?0:1;
}
