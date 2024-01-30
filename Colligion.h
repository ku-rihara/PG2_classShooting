#pragma once

#include"player.h"
#include"bullet.h"
#include"Enemy.h"

class Colligion{

public:

	Colligion();

	void PlayerEnemyColligion(Player& player, Enemy& enemy);

	void BulletEnemyColligion(Bullet& bullet, Enemy& enemy);
};

