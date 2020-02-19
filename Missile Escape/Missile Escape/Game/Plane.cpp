#pragma once

#include <iostream>
#include <cmath>
#include "Plane.hpp"
#include "Game Engine/DEFINITIONS.hpp"

namespace Game
{
	Plane::Plane(GameDataRef data) : _data(data)
	{
		camera = new Camera(data);

		this->_data->assets.LoadTexture("Plane", GAME_SCENE_PLANE_FILEPATH);
		_planeSprite.setTexture(this->_data->assets.GetTexture("Plane"));

		_planeSprite.setScale(sf::Vector2f(0.1f, 0.1f));
		_planeSprite.setOrigin(sf::Vector2f(_planeSprite.getTexture()->getSize().x * 0.5f,
			_planeSprite.getTexture()->getSize().y * 0.5f));

		_planeSprite.setPosition(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
	}

	void Plane::Move(float delta)
	{
		_planeSprite.move(std::sin(_planeSprite.getRotation() * 0.01745f) * 5, 
			std::cos(_planeSprite.getRotation() * 0.01745f) * -5);
		LookRotate(delta);
		camera->Follow(_planeSprite);
	}

	float Plane::MoveHorizontal(float delta)
	{
		return this->_data->input.GetAxis("Horizontal") * 70 * delta;
	}

	void Plane::LookRotate(float delta)
	{
		_planeSprite.rotate(MoveHorizontal(delta));
	}

	sf::Sprite& Plane::GetSprite()
	{
		return _planeSprite;
	}

	void Plane::Draw()
	{
		this->_data->window.draw(_planeSprite);
	}
}

