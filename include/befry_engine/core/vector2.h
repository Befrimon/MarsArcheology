#pragma once

#include <ostream>

#ifndef VECTOR2_H
#define VECTOR2_H

namespace befry
{
    struct Vector2
    {
        int X;
        int Y;
    };

    /* Math operators */
    Vector2 operator+(const Vector2& fst, const Vector2& scn);
    Vector2 operator-(const Vector2& fst, const Vector2& scn);
    Vector2 operator-(const Vector2& fst);
    Vector2 operator*(const int& fst, const Vector2& scn);
    Vector2 operator*(const Vector2& fst, const int& scn);
    Vector2 operator*(const Vector2& fst, const Vector2& scn);
    Vector2 operator/(const Vector2& fst, const int& scn);
    Vector2 operator/(const Vector2& fst, const Vector2& scn);

    /* Assigment operators */
    Vector2& operator+=(Vector2& fst, const Vector2& scn);
    Vector2& operator-=(Vector2& fst, const Vector2& scn);
    Vector2& operator*=(Vector2& fst, const int& scn);
    Vector2& operator*=(Vector2& fst, const Vector2& scn);
    Vector2& operator/=(Vector2& fst, const int& scn);
    Vector2& operator/=(Vector2& fst, const Vector2& scn);

    /* Bool operators */
    bool operator==(const Vector2& fst, const Vector2& scn);
    bool operator<(const Vector2& fst, const Vector2& scn);
    bool operator>(const Vector2& fst, const Vector2& scn);
    bool operator<=(const Vector2& fst, const Vector2& scn);
    bool operator>=(const Vector2& fst, const Vector2& scn);

    std::ostream& operator<< (std::ostream& stream, const Vector2& fst);
    Vector2 str_to_vector2(std::string_view str);
}

#endif