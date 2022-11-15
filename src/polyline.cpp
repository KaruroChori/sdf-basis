#include <polyline.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp> 
#include <glm/common.hpp> 
#include <glm/geometric.hpp> 


using namespace glm;

std::ostream& operator<<(std::ostream& out, const polyline& sk){
    for(auto& i:sk.points){
        out<<i.x<<" "<<i.y<<"\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, polyline& sk){return in;}

void polyline::push(const glm::vec2& v){
    points.push_back(v);
}

size_t polyline::items() const{
    return points.size();
}

void polyline::reserve(size_t v){
    return points.reserve(v);
}

number_t polyline::operator()(const vec2& p) const{
    if(items()<3)throw "At least 3 points are needed";
    const auto& v = points;

    //This shader kernel has beend adapted from the excellent work of Inigo Quillez on SDF primitives
    //https://iquilezles.org/articles/

    float d = dot(p-v[0],p-v[0]);
    float s = 1.0;
    for( int i=0, j=items()-1; i<items(); j=i, i++ )
    {
        vec2 e = v[j] - v[i];
        vec2 w =    p - v[i];
        vec2 b = w - e*clamp( dot(w,e)/dot(e,e), 0.0f, 1.0f );
        d = min( d, dot(b,b) );
        bvec3 c = bvec3(p.y>=v[i].y,p.y<v[j].y,e.x*w.y>e.y*w.x);
        if( all(c) || all(bvec3{!c.x,!c.y,!c.z}) ) s*=-1.0;  
    }
    return s*sqrt(d);
}
