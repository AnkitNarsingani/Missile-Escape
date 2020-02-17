#pragma once

#include "Camera.hpp"
#include "SFML/Graphics.hpp"
#include "Game.hpp"

namespace GameEngine
{
	Camera::Camera(GameDataRef data) : _data(data)
	{
		_cameraView.reset(sf::FloatRect(0, 0, this->_data->window.getSize().x, this->_data->window.getSize().y));
	}

	void Camera::Move(float xOffset, float yOffset)
	{
		_cameraView.move(xOffset, yOffset);
		this->_data->window.setView(_cameraView);
	}

	void Camera::Follow(sf::Sprite player)
	{
		_cameraView.setCenter(player.getPosition());
		this->_data->window.setView(_cameraView);
	}
}