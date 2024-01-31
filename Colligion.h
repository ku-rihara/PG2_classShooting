#pragma once

#include"player.h"
#include"PlayerBullet.h"
#include"Enemy.h"
#include"EnemyBullet.h"

class Colligion{

public:

	Colligion();

	void PlayerEnemyColligion(Player& player, Enemy& enemy);

	void BulletColligion(PlayerBullet& playerBullet, Enemy& enemy);

	void BulletColligion(EnemyBullet& enemyBullet, Player& player);
};

