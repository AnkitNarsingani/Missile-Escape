#pragma once

#include <SFML/Graphics.hpp>
#include "Game Engine/State.hpp"
#include "Game Engine/Game.hpp"
using namespace GameEngine;

namespace UI
{
	class MenuState : public State
	{
	public:
		MenuState(GameDataRef data);

		void Init();


		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:

		void Spawn();
		void MoveClouds(float dt);


		float timer = 0;
		float timeToWait = 1.5;

		GameDataRef _data;

		sf::Sprite _titleImage;
		sf::Sprite _playButton;
		sf::Sprite _exitButton;
		sf::Sprite _cloud;

		std::vector<sf::Sprite> _cloudsInScene;
	};
}
