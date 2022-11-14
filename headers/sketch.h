#pragma once

#include <iostream>
#include <vector>
#include <sdf-2d.h>
#include <polyline.h>

class sketch{
    public:
        friend std::ostream& operator<<(std::ostream&, const sketch&);
        friend std::istream& operator>>(std::istream&, sketch&);

        number_t operator()(const point_t&) const;
    private:
        polyline outline;
        std::vector<polyline> cuts;
};