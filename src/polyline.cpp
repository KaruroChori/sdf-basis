#include <polyline.h>

std::ostream& operator<<(std::ostream& out, const polyline& sk){
    for(auto& i:sk.points){
        out<<i.x<<" "<<i.y<<"\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, polyline& sk){return in;}

void polyline::push(const point_t& v){
    points.push_back(v);
}

size_t polyline::items() const{
    return points.size();
}

number_t polyline::operator()(const point_t&) const{
    if(items()<3)throw "Missing at least 3 points";
    const auto& v = points;

    number_t d = dot(p-v[0],p-v[0]);
    number_t s = 1.0;
    for( int i=0, j=items()-1; i<items(); j=i, i++ )
    {
        vec2 e = v[j] - v[i];
        vec2 w =    p - v[i];
        vec2 b = w - e*clamp( dot(w,e)/dot(e,e), 0.0, 1.0 );
        d = min( d, dot(b,b) );
        bvec3 c = bvec3(p.y>=v[i].y,p.y<v[j].y,e.x*w.y>e.y*w.x);
        if( all(c) || all(not(c)) ) s*=-1.0;  
    }
    return s*sqrt(d);
}
