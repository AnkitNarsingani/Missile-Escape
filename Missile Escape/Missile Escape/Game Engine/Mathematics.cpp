#pragma once

#include "Matematics.hpp"
#include <cmath>

namespace GameEngine
{
	inline float Mathematics::Sqrt(const float x)
	{
		return sqrt(x);
	}

	void Mathematics::Normalize(sf::Vector2f& vector)
	{
		float mag = Magnitude(vector);
		vector.x /= mag;
		vector.y /= mag;
	}

	inline float Mathematics::Magnitude(const sf::Vector2f vector)
	{
		return Sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	sf::Vector3f Mathematics::CrossProduct(const sf::Vector3f vectorA, const sf::Vector3f vectorB)
	{
		sf::Vector3f cross;
		cross.x = vectorA.y * vectorB.z - vectorA.z * vectorB.y;
		cross.y = vectorA.x * vectorB.z - vectorA.z * vectorB.x;
		cross.z = vectorA.x * vectorB.y - vectorA.y * vectorB.x;

		return cross;
	}

	sf::Vector2f Mathematics::ClampMagnitude(const sf::Vector2f vector, const float maxLength)
	{
		sf::Vector2f resultantVector(vector);

		if (Magnitude(resultantVector) > maxLength)
		{
			resultantVector.x /= maxLength;
			resultantVector.y /= maxLength;
		}

		return resultantVector;
	}
}