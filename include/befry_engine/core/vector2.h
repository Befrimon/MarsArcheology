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

    Vector2 operator+(const Vector2& fst, const Vector2& scn);
    Vector2 operator-(const Vector2& fst, const Vector2& scn);
    Vector2 operator-(const Vector2& fst);
    Vector2 operator*(const int& fst, const Vector2& scn);
    Vector2 operator*(const Vector2& fst, const int& scn);
    Vector2 operator*(const Vector2& fst, const Vector2& scn);
    Vector2 operator/(const Vector2& fst, const int& scn);
    Vector2 operator/(const Vector2& fst, const Vector2& scn);
    bool operator==(const Vector2& fst, const Vector2& scn);
    bool operator<(const Vector2& fst, const Vector2& scn);
    bool operator>(const Vector2& fst, const Vector2& scn);
    bool operator<=(const Vector2& fst, const Vector2& scn);
    bool operator>=(const Vector2& fst, const Vector2& scn);
}

#endif