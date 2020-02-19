#pragma once

#include "GameState.hpp"

namespace UI
{
	GameState::GameState(GameDataRef data) : _data(data)
	{

	}

	void GameState::Init()
	{
		plane = new Plane(_data);
		homingMissileSpawner = new HomingMissileSpawner(_data);
		cloudsSpawner = new CloudsSpawner(_data);
	}

	void GameState::HandleInput()
	{
		sf::Event event;

		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
		}
	}

	void GameState::Update(float dt)
	{
		plane->Move(dt);
		homingMissileSpawner->Update(dt, plane->GetSprite());
		cloudsSpawner->Update(dt, plane->GetSprite());
	}

	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color(153, 217, 234));
		cloudsSpawner->Draw();
		plane->Draw();
		homingMissileSpawner->Draw();	
		this->_data->window.display();
	}
}