#include "GameMath/Vector2D.hpp"
#include <cmath>

namespace GameMath {

    Vector2D::Vector2D(float x, float y)
        : x(x), y(y)
    {}

    float Vector2D::Length() const
    {
        return std::sqrt((x*x)+(y*y));
    }

}