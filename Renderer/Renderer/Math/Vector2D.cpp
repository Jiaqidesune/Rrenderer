#include "Vector2D.h"

namespace kawaii
{
    void Vector2D::normalize()
    {
        float length;
        float scalefactor;
        length = getLength();
        if (Equal(length, 1.0) || Equal(length, 0))
            return;
        scalefactor = 1.0f / length;
        x *= scalefactor;
        y *= scalefactor;
    }

    Vector2D Vector2D::getNormalized() const
    {
        Vector2D result(*this);
        result.normalize();
        return result;
    }

    std::ostream& operator<<(std::ostream& out, const Vector2D& v)
    {
        return out << v.x << ' ' << v.y;
    }
}