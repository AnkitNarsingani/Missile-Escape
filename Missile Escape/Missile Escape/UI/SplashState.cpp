#pragma once

#include <sstream>
#include "UI/SplashState.hpp"
#include "UI/MenuState.hpp"
#include "Game Engine/DEFINITIONS.hpp"
#include <iostream>

namespace UI
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Init()
	{
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));

		_background.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (_background.getGlobalBounds().width / 2), 
			(SCREEN_HEIGHT / 2) - (_background.getGlobalBounds().height / 2)));
	}

	void SplashState::HandleInput()
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

	void SplashState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > 3)
		{
			// Switch To Main Menu
			this->_data->machine.AddState(StateRef(new MenuState(_data)));
		}
	}

	void SplashState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Black);

		this->_data->window.draw(this->_background);

		this->_data->window.display();
	}
}