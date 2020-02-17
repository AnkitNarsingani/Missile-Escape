#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game Engine/Game.hpp"
using namespace GameEngine;

namespace Game
{
	class CloudsSpawner
	{
	public:
		CloudsSpawner(GameDataRef data);
		void Update(float dt, sf::Sprite& player);

	private:
		void Draw();
		void Spawn(sf::Vector2f centerCoordinates);
		sf::Vector2f GetRandomSpawnPoint(sf::Vector2f centerCoordinates);

		GameDataRef _data;

		float timer = 0;
		float timeToWait = 2;

		sf::Sprite _cloud;

		std::vector<sf::Sprite> _cloudsInScene;
	};
}