#pragma once

#include <SFML/Graphics.hpp>
#include "Game Engine/Game.hpp"
using namespace GameEngine;

namespace Game
{
	class HomingMissile
	{
	public:
		HomingMissile(GameDataRef _data, sf::Vector2f spawnPos);

		void ChaseTarget(float delta, sf::Sprite&);

		void Draw();

	private:

		sf::Sprite _missile;
		
		GameDataRef _data;

		sf::Vector2f _velocity;
		float _angularVelocity;
	};
}