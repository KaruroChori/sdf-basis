#include <sketch.h>
#include <iterator>
#include <string>
#include <regex>

std::ostream& operator<<(std::ostream& out, const sketch& sk){
    out<<"OUTLINE "<<sk.outline.items()<<"\n";
    out<<sk.outline;
    for(auto& i:sk.cuts){
        out<<"CUT "<<i.items()<<"\n";
        out<<i;
    }
    return out;
}

std::istream& operator>>(std::istream& in, sketch& sk){
    static const std::regex rgx_outline(R"(\s*OUTLINE\s+(\d+)\s*)");
    static const std::regex rgx_cut(R"(\s*CUT\s+(\d+)\s*)");
    static const std::regex rgx_point(R"(\s*(-?\d*\.?\d*)\s+(-?\d*\.?\d*)s*)");
    
    bool is_outline = false;
    bool is_cut = false;
    bool has_outline = false;

    for(;;){
        std::string line;
        std::getline(in,line);
        if(line.empty())break;
        else{
            //std::cout<<line<<std::endl;

            {
                std::smatch sm;
                std::regex_match(line,sm,rgx_outline);
                if(sm.size()!=0){
                    if(has_outline){
                        throw "Wrong syntax. Only one outline can be defined.";
                    }
                    //std::cout<<"New outline\n";

                    is_outline = true;
                    is_cut = false;
                    has_outline = true;
                    continue;
                }
            }

            {
                std::smatch sm;
                std::regex_match(line,sm,rgx_cut);
                if(sm.size()!=0){
                    //std::cout<<"New cut\n";
                    sk.cuts.push_back({});

                    is_outline = false;
                    is_cut = true;
                    continue;
                }
            }

            if(!is_outline && !is_cut){
                throw "Wrong syntax. Point outside environment.";
            }

            {
                std::smatch sm;
                std::regex_match(line,sm,rgx_point);
                if(sm.size()!=0){
                    point_t pt = {std::stod(sm[1]),std::stod(sm[2])};
                    if(is_outline){
                        sk.outline.push(pt);
                        //std::cout<<"In outline:\t"<<sm[1]<<","<<sm[2]<<"\n";
                    }
                    else if(is_cut){
                        sk.cuts.back().push(pt);
                        //std::cout<<"In cut:\t"<<sm[1]<<","<<sm[2]<<"\n";
                    }
                    continue;
                }
            }
        }
    }

    return in;
}

number_t sketch::operator()(const point_t&) const{
    return -1;
}
