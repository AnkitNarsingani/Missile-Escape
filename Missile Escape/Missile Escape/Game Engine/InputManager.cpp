#pragma once

#include "InputManager.hpp"

namespace GameEngine
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{
			sf::IntRect playButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

			if (playButtonRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}

		return false;
	}

	sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window)
	{
		return sf::Mouse::getPosition(window);
	}

	float InputManager::GetAxis(std::string axis)
	{
		if (axis._Equal("Horizontal"))
		{
			if (GetKey(sf::Keyboard::A))
				return -1;
			else if (GetKey(sf::Keyboard::D))
				return 1;
		}
		else if (axis._Equal("Vertical"))
		{
			if (GetKey(sf::Keyboard::W))
				return -1;
			else if (GetKey(sf::Keyboard::S))
				return 1;
		}

		return 0.0f;
	}

	bool InputManager::GetKey(sf::Keyboard::Key key)
	{
		if (sf::Keyboard::isKeyPressed(key))
			return true;
		else
			return false;
	}

	bool InputManager::GetKeyDown(sf::Keyboard::Key, sf::Event)
	{
		return false;
	}

	bool InputManager::GetKeyUp(sf::Keyboard::Key, sf::Event)
	{
		return false;
	}
}