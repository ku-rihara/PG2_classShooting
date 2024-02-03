#include "Colligion.h"

Colligion::Colligion() {

}

//プレイヤーと敵
void Colligion::PlayerEnemyColligion(Player& player, Enemy& enemy) {

	//プレイヤーのダメージ
	player.SetIsDamage(CircleColligion(player.GetWorldPos(), enemy.GetWorldPos(), player.GetRadius().x, enemy.GetRadius().x));

}
//プレイヤーの弾と敵
void Colligion::BulletColligion(PlayerBullet& playerBullet, Enemy& enemy){

	//敵のダメージ
	playerBullet.SetEnemyDisntance(Distance(enemy.GetWorldPos(), playerBullet.GetWorldPos()));
	if (playerBullet.GetEnemyDistance() <= playerBullet.GetRadius().x + enemy.GetRadius().x) {
		playerBullet.SetIsShot(false);
		enemy.SetIsDamage(true);
	}
}

//敵の弾とプレイヤー
void Colligion::BulletColligion(EnemyBullet& enemyBullet, Player& player){

	
	//プレイヤーと当たった弾を消す
	enemyBullet.SetPlayerDistance(Distance(player.GetWorldPos(), enemyBullet.GetWorldPos()));
	if (enemyBullet.GetPlayerDistance() <= enemyBullet.GetRadius().x + player.GetRadius().x) {
		enemyBullet.SetIsShotEnd(true);
		player.SetIsDamage(true);
	}
}

