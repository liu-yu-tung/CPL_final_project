#ifndef VECTOR2D_H_INCLUDED
#define VECTOR2D_H_INCLUDED

class Vector2D
{
public:
    float X, Y;

    Vector2D(float x = 0, float y = 0): X(x), Y(y) {}

    Vector2D operator+(const Vector2D & v2)
    {
        return Vector2D(X + v2.X, Y + v2.Y);
    }

    Vector2D operator-(const Vector2D & v2)
    {
        return Vector2D(X - v2.X, Y - v2.Y);
    }

    Vector2D operator*(const float n)
    {
        return Vector2D(X * n, Y * n);
    }
};

#endif // VECTOR2D_H_INCLUDED
