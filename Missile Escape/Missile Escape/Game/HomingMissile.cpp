#pragma once

#include <iostream>
#include "HomingMissile.hpp"
#include "UI/GameOverState.hpp"
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

	void HomingMissile::Update(float delta, sf::Sprite& target, std::vector<HomingMissile*>& homingMissiles)
	{
		ChaseTarget(delta, target);
		CheckCollisions(homingMissiles, target);
	}

	void HomingMissile::ChaseTarget(float delta, sf::Sprite& target)
	{
		sf::Vector2f desiredVelocity = target.getPosition() - _missile.getPosition();
		Mathematics::Normalize(desiredVelocity);
		desiredVelocity *= (float)MISSILE_SPEED;
		sf::Vector2f steer = desiredVelocity - _velocity;
		_velocity = Mathematics::ClampMagnitude(_velocity + steer * (float)50 * delta, 150);
		_missile.move(_velocity * delta);
		sf::Vector2f temp = _missile.getPosition() + _velocity * delta;

		LookAt(target);
	}

	void HomingMissile::LookAt(sf::Sprite target)
	{
		sf::Vector2f desiredVelocity = target.getPosition() - _missile.getPosition();
		float angle = (atan2(desiredVelocity.y, desiredVelocity.x) * 57.296f) - 270;
		_missile.setRotation(angle);
	}

	void HomingMissile::CheckCollisions(std::vector<HomingMissile*>& homingMissiles, sf::Sprite player)
	{
		if (_missile.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			this->_data->machine.AddState(StateRef(new UI::GameOverState(_data)));
		}
		else
		{
			for (size_t i = 0; i < homingMissiles.size(); i++)
			{
				if (!Compare(_missile.getPosition(), homingMissiles[i]->_missile.getPosition()))
				{
					if (_missile.getGlobalBounds().intersects(homingMissiles[i]->_missile.getGlobalBounds()))
					{
						homingMissiles[i]->Destroy(homingMissiles);
						Destroy(homingMissiles);
					}
				}
			}
		}
	}

	void HomingMissile::Destroy(std::vector<HomingMissile*>& homingMissiles)
	{
		for (size_t i = 0; i < homingMissiles.size(); i++)
		{
			if (Compare(_missile.getPosition(), homingMissiles[i]->_missile.getPosition()))
			{
				homingMissiles.erase(homingMissiles.begin() + i);
			}
		}
	}

	void HomingMissile::Draw()
	{
		this->_data->window.draw(_missile);
	}

	bool HomingMissile::Compare(sf::Vector2f a, sf::Vector2f b)
	{
		if (a.x == b.x && a.y == b.y)
			return true;
		else
			return false;
	}
}