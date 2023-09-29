#pragma once
#ifndef VECTOR2D_H
#define VECTOR2D_H


struct Vector2D {

	float x = 0;
	float y = 0;
};

	inline Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
	{
		Vector2D result(lhs);
		result.x += rhs.x;
		result.y += rhs.y;

		return result;
	}

#endif // !VECTOR2D_H

