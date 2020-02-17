#pragma once

#include "SFML\Graphics.hpp"

namespace GameEngine
{
	class InputManager
	{
	public:
		InputManager() {}
		~InputManager() {}

		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

		sf::Vector2i GetMousePosition(sf::RenderWindow &window);

		float GetAxis(std::string);

		bool GetKey(sf::Keyboard::Key);

		bool GetKeyDown(sf::Keyboard::Key, sf::Event);

		bool GetKeyUp(sf::Keyboard::Key, sf::Event);
	};
}