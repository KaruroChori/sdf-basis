#pragma once
#include <iostream>
#include <vector>
#include <glm/vec2.hpp>

typedef double number_t;

/**
 * @brief The class implementing a boundary wire. 
 * @details Only closed cyclic ones are currently supported. Only segments are supported (but they could be easily extended).
 */
struct polyline{
    public:
        friend std::ostream& operator<<(std::ostream&, const polyline&);
        friend std::istream& operator>>(std::istream&, polyline&);

        void push(const glm::vec2&);
        size_t items() const;
        void reserve(size_t);

        ///Compute the SDF for the polyline. Positive is outside, negative is inside.
        number_t operator()(const glm::vec2&) const;

    private:
        bool cyclic = true;
        std::vector<glm::vec2> points;
};