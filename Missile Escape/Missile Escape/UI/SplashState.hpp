#pragma once

#include <SFML/Graphics.hpp>
#include "Game Engine/State.hpp"
#include "Game Engine/Game.hpp"
using namespace GameEngine;

namespace UI
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Init();

		// No pause() or resume() methods here as this
		// is a very simple example of a game state.

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite _background;
	};
}