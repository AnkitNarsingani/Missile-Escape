#pragma once

#include "SFML/Graphics.hpp"
#include "Game Engine/Camera.hpp"
#include "Game Engine/Game.hpp"
using namespace GameEngine;

namespace UI
{
	class GameOverState : public State
	{
	public:
		GameOverState(GameDataRef data);

		void Init();


		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Camera* camera;

		sf::Sprite _GameOverText;
		sf::Sprite _replayButton;
		sf::Sprite _exitButton;
	};
}