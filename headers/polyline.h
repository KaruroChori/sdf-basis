#pragma once
#include <iostream>
#include <vector>

typedef double number_t;

struct point_t{
    number_t x;
    number_t y;
};

struct polyline{
    public:
        friend std::ostream& operator<<(std::ostream&, const polyline&);
        friend std::istream& operator>>(std::istream&, polyline&);

        void push(const point_t&);
        size_t items() const;

        number_t operator()(const point_t&) const;
        
    private:
        bool cyclic = true;
        std::vector<point_t> points;
};