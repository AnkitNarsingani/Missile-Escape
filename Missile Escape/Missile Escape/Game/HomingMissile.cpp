#pragma once

#include <iostream>
#include "HomingMissile.hpp"
#include "Game Engine/Matematics.hpp"
#include "Game Engine/DEFINITIONS.hpp"

namespace Game
{
	HomingMissile::HomingMissile(GameDataRef data, sf::Vector2f spawnPos) : _data(data)
	{
		this->_data->assets.LoadTexture("Missile", GAME_SCENE_MISSILE_FILEPATH);
		_missile.setTexture(this->_data->assets.GetTexture("Missile"));

		_missile.setOrigin(sf::Vector2f(_missile.getTexture()->getSize().x * 0.5f,
			_missile.getTexture()->getSize().y * 0.5f));

		_missile.setScale(sf::Vector2f(0.1f, 0.1f));

		_missile.setPosition(spawnPos);
	}

	void HomingMissile::ChaseTarget(float delta, sf::Sprite& _target)
	{
		sf::Vector2f desiredVelocity = _target.getPosition() - _missile.getPosition();
		Mathematics::Normalize(desiredVelocity);
		desiredVelocity *= (float)MISSILE_SPEED;
		sf::Vector2f steer = desiredVelocity - _velocity;
		_velocity = Mathematics::ClampMagnitude(_velocity + steer * (float)50 * delta, 150);
		_missile.move(_velocity * delta);
		float angle = atan2(desiredVelocity.y, desiredVelocity.x) * 57.296f;
		_missile.setRotation(angle);
		sf::Vector2f temp = _missile.getPosition() + _velocity * delta;
	}

	void HomingMissile::Draw()
	{
		this->_data->window.draw(_missile);
	}
}