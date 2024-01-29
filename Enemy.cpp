#include "Enemy.h"

Enemy::Enemy(float posX, float posY) {
	Init(posX, posY);
}


Enemy::~Enemy() {

}

void Enemy::Init(float posX, float posY) {

	isDeath_ = false;
	BaseObj::Init();

}

void Enemy::Update() {

}

void Enemy::Draw() {

}

//レンダリングパイプライン
void Enemy::RenderingPipeline() {
	BaseObj::RenderingPipeline();
}