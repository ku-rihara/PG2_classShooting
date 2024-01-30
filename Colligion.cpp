#include "Colligion.h"

Colligion::Colligion() {

}


void Colligion::PlayerEnemyColligion(Player& player, Enemy& enemy) {

	CircleColligion(player.GetWorldPos(), enemy.GetWorldPos(), player.GetRadius().x, enemy.GetRadius().x,player.isDamage_);

}

void Colligion::BulletEnemyColligion(Bullet& bullet, Enemy& enemy){

	CircleColligion(bullet.GetWorldPos(), enemy.GetWorldPos(), bullet.GetRadius().x, enemy.GetRadius().x, enemy.isDamage_);
}