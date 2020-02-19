#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game Engine/Game.hpp"
using namespace GameEngine;

namespace Game
{
	class HomingMissile
	{
	public:
		HomingMissile(GameDataRef _data, sf::Vector2f spawnPos);

		void Update(float delta, sf::Sprite&, std::vector<HomingMissile*>& homingMissiles);

		void Draw();

	private:

		void ChaseTarget(float delta, sf::Sprite&);

		void LookAt(sf::Sprite target);

		void CheckCollisions(std::vector<HomingMissile*>& homingMissiles, sf::Sprite player);

		bool Compare(sf::Vector2f a, sf::Vector2f b);

		void Destroy(std::vector<HomingMissile*>& homingMissiles);

		sf::Sprite _missile;
		
		GameDataRef _data;

		sf::Vector2f _velocity;
		float _angularVelocity;
	};
}