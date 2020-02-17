#pragma once

#include <SFML/Graphics.hpp>
#include "Game.hpp"

namespace GameEngine
{
	class Mathematics
	{
	public:
		inline static float Sqrt(const float x);
		static void Normalize(sf::Vector2f& vector);
		inline static float Magnitude(const sf::Vector2f vector);
		static sf::Vector3f CrossProduct(const sf::Vector3f vectorA, const sf::Vector3f vectorB);
		static sf::Vector2f ClampMagnitude(const sf::Vector2f vector, const float maxLength);
	};
}