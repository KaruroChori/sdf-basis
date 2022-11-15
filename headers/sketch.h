#pragma once

#include <iostream>
#include <vector>
#include <polyline.h>
#include <glm/vec2.hpp>

/**
 * @brief The class to implement sketches.
 * @details Sketches are boundary shapes. In this implementation there is one single outline and multiple cuts performed in it.
 */
class sketch{
    public:
        friend std::ostream& operator<<(std::ostream&, const sketch&);
        friend std::istream& operator>>(std::istream&, sketch&);

        number_t operator()(const glm::vec2&) const;
    private:
        polyline outline;
        std::vector<polyline> cuts;
};