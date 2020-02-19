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
		void Draw();

	private:
		
		void Spawn(sf::Vector2f centerCoordinates);
		sf::Vector2f GetRandomSpawnPoint(sf::Vector2f centerCoordinates);

		GameDataRef _data;

		float timer = 0;
		float timeToWait = 1.5;

		sf::Sprite _cloud;

		std::vector<sf::Sprite> _cloudsInScene;
	};
}