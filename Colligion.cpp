#include "Colligion.h"

Colligion::Colligion() {

}

//プレイヤーと敵
void Colligion::PlayerEnemyColligion(Player& player, Enemy& enemy) {

	CircleColligion(player.GetWorldPos(), enemy.GetWorldPos(), player.GetRadius().x, enemy.GetRadius().x,player.isDamage_);

}
//プレイヤーの弾と敵
void Colligion::BulletColligion(PlayerBullet& playerBullet, Enemy& enemy){

	CircleColligion(playerBullet.GetWorldPos(), enemy.GetWorldPos(), playerBullet.GetRadius().x, enemy.GetRadius().x, enemy.isDamage_);
}

//敵の弾とプレイヤー
void Colligion::BulletColligion(EnemyBullet& enemyBullet, Player& player){

	CircleColligion(enemyBullet.GetWorldPos(), player.GetWorldPos(), enemyBullet.GetRadius().x, player.GetRadius().x, player.isDamage_);
}