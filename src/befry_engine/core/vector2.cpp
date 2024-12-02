#include "core/vector2.h"


befry::Vector2 befry::operator+(const Vector2& fst, const Vector2& scn)
{
    return Vector2{fst.X + scn.X, fst.Y + scn.Y};
}

befry::Vector2 befry::operator-(const Vector2& fst, const Vector2& scn)
{
    return Vector2{fst.X - scn.X, fst.Y - scn.Y};
}

befry::Vector2 befry::operator-(const Vector2& fst)
{
    return Vector2{-1 * fst.X, -1 * fst.Y};
}

befry::Vector2 befry::operator*(const int& fst, const Vector2& scn)
{
    return Vector2{fst * scn.X, fst * scn.Y};
}

befry::Vector2 befry::operator*(const Vector2& fst, const int& scn)
{
    return Vector2{fst.X * scn, fst.Y * scn};
}

befry::Vector2 befry::operator*(const Vector2& fst, const Vector2& scn)
{
    return Vector2{fst.X * scn.X, fst.Y * scn.Y};
}

befry::Vector2 befry::operator/(const Vector2& fst, const int& scn)
{
    return Vector2{fst.X / scn, fst.Y / scn};
}

befry::Vector2 befry::operator/(const Vector2& fst, const Vector2& scn)
{
    return Vector2{fst.X / scn.X, fst.Y / scn.Y};
}

bool befry::operator==(const Vector2& fst, const Vector2& scn)
{
    return fst.X == scn.X && fst.Y == scn.Y;
}

bool befry::operator<(const Vector2& fst, const Vector2& scn)
{
    return fst.X < scn.X || fst.Y < scn.Y;
}

bool befry::operator>(const Vector2& fst, const Vector2& scn)
{
    return fst.X > scn.X || fst.Y > scn.Y;
}

bool befry::operator<=(const Vector2& fst, const Vector2& scn)
{
    return fst.X < scn.X && fst.Y < scn.Y;
}

bool befry::operator>=(const Vector2& fst, const Vector2& scn)
{
    return fst.X > scn.X && fst.Y > scn.Y;
}