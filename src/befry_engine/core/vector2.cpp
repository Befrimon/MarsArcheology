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


std::ostream& befry::operator<< (std::ostream& stream, const Vector2& fst)
{
    stream << "vec" << fst.X << "," << fst.Y;
    return stream;
}

befry::Vector2 befry::str_to_vector2(std::string_view str)
{
    if (str.substr(0, 3) != "vec") return Vector2{};
    std::string_view pos = str.substr(3, str.length());

    std::string_view raw_x = pos.substr(0, pos.find(','));
    std::string_view raw_y = pos.substr(pos.find(',')+1, pos.length());

    return Vector2{std::atoi(raw_x.data()), std::atoi(raw_y.data())};
}
