#pragma once

#include <SFML/Graphics.hpp>
#include "Game Engine/Game.hpp"

namespace GameEngine
{
	class Camera
	{
	public:
		Camera(GameDataRef _data);

		void Move(float xOffset, float yOffset);
		void Follow(sf::Sprite player);
		void Reset();

	private:
		GameDataRef _data;
		sf::View _cameraView;
	};
}