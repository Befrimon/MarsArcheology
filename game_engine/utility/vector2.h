#pragma once

#ifndef VECTOR2_H
#define VECTOR2_H

namespace befry
{
    struct Vector2
    {
        int X;
        int Y;
    };

    inline Vector2 operator+(const Vector2& fst, const Vector2& scn)
    {
        return Vector2{fst.X + scn.X, fst.Y + scn.Y};
    }
    inline Vector2 operator-(const Vector2& fst, const Vector2& scn)
    {
        return Vector2{fst.X - scn.X, fst.Y - scn.Y};
    }
    inline Vector2 operator-(const Vector2& fst)
    {
        return Vector2{-1 * fst.X, -1 * fst.Y};
    }
    inline Vector2 operator*(const int& fst, const Vector2& scn)
    {
        return Vector2{fst * scn.X, fst * scn.Y};
    }
    inline Vector2 operator*(const Vector2& fst, const int& scn)
    {
        return Vector2{fst.X * scn, fst.Y * scn};
    }
    inline Vector2 operator*(const Vector2& fst, const Vector2& scn)
    {
        return Vector2{fst.X * scn.X, fst.Y * scn.Y};
    }
    inline Vector2 operator/(const Vector2& fst, const int& scn)
    {
        return Vector2{fst.X / scn, fst.Y / scn};
    }
    inline Vector2 operator/(const Vector2& fst, const Vector2& scn)
    {
        return Vector2{fst.X / scn.X, fst.Y / scn.Y};
    }
    inline bool operator<(const Vector2& fst, const Vector2& scn)
    {
        return fst.X < scn.X && fst.Y < scn.Y;
    }
    inline bool operator>(const Vector2& fst, const Vector2& scn)
    {
        return fst.X > scn.X && fst.Y > scn.Y;
    }
}

#endif