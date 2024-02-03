#pragma once

#include"player.h"
#include"PlayerBullet.h"
#include"Enemy.h"
#include"EnemyBullet.h"

class Colligion{

public:

	Colligion();

	static void PlayerEnemyColligion(Player& player, Enemy& enemy);

	static	void BulletColligion(PlayerBullet& playerBullet, Enemy& enemy);

	static	void BulletColligion(EnemyBullet& enemyBullet, Player& player);



};

