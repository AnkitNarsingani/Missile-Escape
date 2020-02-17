#pragma once

#include <SFML/Graphics.hpp>
#include "Game Engine/State.hpp"
#include "Game Engine/Game.hpp"
#include "Game Engine/DEFINITIONS.hpp"
#include "Game/Plane.hpp"
#include "Game/HomingMissile.hpp"
#include <Game/HomingMissileSpawner.hpp>
#include <Game/CloudsSpawner.hpp>

using namespace GameEngine;
using namespace Game;

namespace UI
{
	class GameState : public State
	{
	public:
		GameState(GameDataRef data);

		void Init();


		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		Plane* plane;
		HomingMissileSpawner* homingMissileSpawner;
		CloudsSpawner* cloudsSpawner;
	};
}
