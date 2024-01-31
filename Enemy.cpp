#include "Enemy.h"

Enemy::Enemy(float posX, float posY) {
	Init(posX, posY);

	for (int i = 0; i < EnemyBulletMax; i++) {
		enemyBullet_[i] = new EnemyBullet;
	}

	texture_.Handle = Novice::LoadTexture("white1x1.png");
}


Enemy::~Enemy() {

}

void Enemy::Init(float posX, float posY) {

	worldPos_.x = posX;
	worldPos_.y = posY;
	spone_.easingTime = 0;
	moveMode_ = SPONE;
	isDeath_ = false;
	spone_.isEasing = false;

	BaseObj::Init();

}

void Enemy::Update() {

	if (isDeath_ == false&&spone_.isEasing==false) {
		spone_.isEasing = true;
	}
	//
	if (spone_.isEasing == true&& moveMode_ == SPONE) {
		spone_.easingTime++;
		scale_.x = easeOutBack(spone_.easingTime/sponeMaxFrame_, 0, 1);
		scale_.y = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);
	
		//イージングが終わったらアタックモードに切り替わる
		if (spone_.easingTime >= sponeMaxFrame_) {
			spone_.easingTime = sponeMaxFrame_;
			moveMode_ = ATTACK;
		}
	}
	//アタックモード
	if (moveMode_ == ATTACK) {
		
		if()


	}

	//レンダリングパイプライン
	RenderingPipeline();

}

void Enemy::Draw() {
	if (isDamage_ == false) {
		newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);
	}
	else if (isDamage_ == false) {
		newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, RED);
	}
}

//レンダリングパイプライン
void Enemy::RenderingPipeline() {
	BaseObj::RenderingPipeline();
}