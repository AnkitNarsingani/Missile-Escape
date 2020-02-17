#pragma once

#include <SFML/Graphics.hpp>
#include "Game Engine/Camera.hpp"
#include "Game Engine/Game.hpp"
using namespace GameEngine;

namespace Game
{
	class Plane
	{
	public:

		Plane(GameDataRef data);

		void Draw();

		void Move(float dealt);
		
		sf::Sprite& GetSprite();

	private:

		float MoveHorizontal(float delta);

		void LookRotate(float delta);	

		GameDataRef _data;

		sf::Sprite _planeSprite;
		sf::Sprite _cloud;

		Camera *camera;
	};
}