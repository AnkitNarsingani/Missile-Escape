#pragma once

#include "GameOverState.hpp"
#include "GameState.hpp"
#include "Game Engine/DEFINITIONS.hpp"

namespace UI
{
	GameOverState::GameOverState(GameDataRef data) : _data(data)
	{
		camera = new Camera(data);
		camera->Reset();
	}

	void GameOverState::Init()
	{
		this->_data->assets.LoadTexture("Game Over", GAMEOVER_SCENE_GAMEOVER_TEXT_FILEPATH);
		this->_data->assets.LoadTexture("Replay", GAMEOVER_SCENE_REPLAY_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Exit Button", MENU_SCENE_EXIT_BUTTON_FILEPATH);

		_GameOverText.setTexture(this->_data->assets.GetTexture("Game Over"));

		_GameOverText.scale(0.4f, 0.4f);

		_GameOverText.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 - _GameOverText.getGlobalBounds().width / 2, 
			SCREEN_HEIGHT / 2 - _GameOverText.getGlobalBounds().height / 2 / 0.5));

		_replayButton.setTexture(this->_data->assets.GetTexture("Replay"));

		_replayButton.setScale(0.45, 0.45);

		_replayButton.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 - _replayButton.getGlobalBounds().width / 2 * 2,
			SCREEN_HEIGHT / 2 - _replayButton.getGlobalBounds().height / 2 / 5));

		_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));

		_exitButton.setScale(0.85, 0.85);

		_exitButton.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 - _exitButton.getGlobalBounds().width / 2 / 100,
			SCREEN_HEIGHT / 2 - _exitButton.getGlobalBounds().height / 2 / 50));
		
	}

	void GameOverState::HandleInput()
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

	void GameOverState::Update(float dt)
	{
		if (this->_data->input.IsSpriteClicked(_exitButton, sf::Mouse::Left, this->_data->window))
		{
			this->_data->window.close();
			exit(0);
		}
		else if (this->_data->input.IsSpriteClicked(_replayButton, sf::Mouse::Left, this->_data->window))
			this->_data->machine.AddState(StateRef(new GameState(this->_data)));
	}

	void GameOverState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color(255, 255, 255));

		this->_data->window.draw(this->_GameOverText);
		this->_data->window.draw(this->_replayButton);
		this->_data->window.draw(this->_exitButton);

		this->_data->window.display();
	}
}