#include <iostream>
#include <fstream>
#include <cassert>

#include <sketch.h>

//To ensure boundary points are inside.
//Just to make sure this code is passing tests without dealing with floating point issues.
const double epsilon = 1e-3;

int main(int argc, const char* argv[]){

    sketch sk;

    std::ifstream file("../../../docs/in-0.data", std::ifstream::in);
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

    glm::vec2 pt = {0,0};

    assert(sk({0,0})>0);
    assert(!sk({2100,19640})>0);
    assert(sk({1000,100000})>0);
    assert(!sk({4320,11705})>0);
}
