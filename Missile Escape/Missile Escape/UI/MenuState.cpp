#pragma once

#include "MenuState.hpp"
#include "GameState.hpp"
#include "Game Engine/DEFINITIONS.hpp"

namespace UI
{
	MenuState::MenuState(GameDataRef data) : _data(data)
	{

	}

	void MenuState::Init()
	{
		this->_data->assets.LoadTexture("Title", MENU_SCENE_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MENU_SCENE_PLAY_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Exit Button", MENU_SCENE_EXIT_BUTTON_FILEPATH);

		_titleImage.setTexture(this->_data->assets.GetTexture("Title"));
		_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		_exitButton.setTexture(this->_data->assets.GetTexture("Exit Button"));


		_titleImage.setPosition(sf::Vector2f(SCREEN_WIDTH / 2 - _titleImage.getGlobalBounds().width / 2,
			(_titleImage.getGlobalBounds().height / 2) * 0.1f));

		_playButton.setPosition(sf::Vector2f((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2) * -1.5f));

		_exitButton.setPosition(sf::Vector2f((SCREEN_WIDTH)-(_exitButton.getGlobalBounds().width / 2), 0));
		_exitButton.setScale(sf::Vector2f(0.5, 0.5));
	}

	void MenuState::HandleInput()
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

	void MenuState::Update(float dt)
	{
		if (this->_data->input.IsSpriteClicked(_exitButton, sf::Mouse::Left, this->_data->window))
			this->_data->window.close();

		if (this->_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, this->_data->window))
			this->_data->machine.AddState(StateRef(new GameState(_data)));
	}

	void MenuState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color(153, 217, 234));

		this->_data->window.draw(this->_titleImage);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_exitButton);

		this->_data->window.display();
	}
}