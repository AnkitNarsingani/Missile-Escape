#pragma once

#include <time.h>
#include "HomingMissile.hpp"
#include "Game Engine/DEFINITIONS.hpp"
#include "HomingMissileSpawner.hpp"
#include "Plane.hpp"

namespace Game
{
	HomingMissileSpawner::HomingMissileSpawner(GameDataRef data) : _data(data)
	{
		srand(time(0));
	}

	void HomingMissileSpawner::Update(float dt, sf::Sprite& player)
	{
		if (timer > timeToWait && _missilesInScene.size() < 2)
		{
			Spawn(player.getPosition());
			timer = 0;
		}

		timer += dt;

		for (size_t i = 0; i < _missilesInScene.size(); i++)
		{
			_missilesInScene[i]->ChaseTarget(dt, player);
		}
	}

	void HomingMissileSpawner::Spawn(sf::Vector2f centerCoordinates)
	{
		_missilesInScene.push_back(new HomingMissile(_data, GetRandomSpawnPoint(centerCoordinates)));
	}

	sf::Vector2f HomingMissileSpawner::GetRandomSpawnPoint(sf::Vector2f centerCoordinates)
	{
		float xOffset = rand() % 170 + SCREEN_WIDTH / 2, yOffset = rand() % 170 + SCREEN_HEIGHT / 2;

		if (rand() % 2)	xOffset = -xOffset;
		
		if (rand() % 2)	yOffset = -yOffset;

		return sf::Vector2f(centerCoordinates.x + xOffset, centerCoordinates.y + yOffset);
	}

	void HomingMissileSpawner::Draw()
	{
		for (size_t i = 0; i < _missilesInScene.size(); i++)
		{
			_missilesInScene[i]->Draw();
		}
	}
}