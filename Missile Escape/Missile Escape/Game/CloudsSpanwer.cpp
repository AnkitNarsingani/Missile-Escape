#pragma once

#include "CloudsSpawner.hpp"
#include "Game Engine/DEFINITIONS.hpp"

using namespace GameEngine;

namespace Game
{
	CloudsSpawner::CloudsSpawner(GameDataRef data) : _data(data)
	{
		this->_data->assets.LoadTexture("Cloud", GAME_SCENE_CLOUD_FILEPATH);
	}

	void CloudsSpawner::Update(float dt, sf::Sprite& player)
	{
		if (timer > timeToWait)
		{
			Spawn(player.getPosition());
			timer = 0;
		}

		timer += dt;
	}

	void CloudsSpawner::Spawn(sf::Vector2f centerCoordinates)
	{
		_cloud.setTexture(this->_data->assets.GetTexture("Cloud"));
		_cloud.setOrigin(sf::Vector2f(_cloud.getTexture()->getSize().x * 0.5f,
			_cloud.getTexture()->getSize().y * 0.5f));

		_cloud.setScale(sf::Vector2f(0.07f, 0.07f));
		_cloud.setPosition(GetRandomSpawnPoint(centerCoordinates));

		_cloudsInScene.push_back(_cloud);
	}

	sf::Vector2f CloudsSpawner::GetRandomSpawnPoint(sf::Vector2f centerCoordinates)
	{
		float xOffset = rand() % 170 + SCREEN_WIDTH / 2, yOffset = rand() % 170 + SCREEN_HEIGHT / 2;

		if (rand() % 2)	xOffset = -xOffset;

		if (rand() % 2)	yOffset = -yOffset;

		return sf::Vector2f(centerCoordinates.x + xOffset, centerCoordinates.y + yOffset);
	}

	void CloudsSpawner::Draw()
	{
		for (size_t i = 0; i < _cloudsInScene.size(); i++)
		{
			this->_data->window.draw(_cloudsInScene[i]);
		}
	}
}