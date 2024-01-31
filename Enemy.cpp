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
	size_ = { 64,64 };
	radius_ = { size_.x/2,size_.y/2 };
	localVertex_ = MakeLoalVertex(size_);
	spone_.easingTime = 0;
	isDeath_ = false;
	spone_.isEasing = false;

	BaseObj::Init();

}

void Enemy::Spone() {
	if (isDeath_ == false && spone_.isEasing == false) {
		spone_.isEasing = true;
	}

	if (spone_.isEasing == true) {
		spone_.easingTime++;
		scale_.x = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);
		scale_.y = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);

		//イージングが終わったらアタックモードに切り替わる
		if (spone_.easingTime >= sponeMaxFrame_) {
			spone_.easingTime = sponeMaxFrame_;
			
			attackMode_ = SHOT;
			isSponeEnd_ = true;
		}
	}

}

void Enemy::Update(Vector2 pos) {
	
		if (attackMode_ == SHOT) {

			for (int i = 0; i < EnemyBulletMax; i++) {
				
				//プレイヤーをロックオン
				if (enemyBullet_[i]->GetIsShot() == false && shotCurrentCollTime_ <= 0) {
					enemyBullet_[i]->SetIsShot(true);
					enemyBullet_[i]->SetWorldPosX(worldPos_.x);
					enemyBullet_[i]->SetWorldPosY(worldPos_.y);
					enemyBullet_[i]->SetDirection(normalize(worldPos_, pos));
					break;
				}
			}

			for(int i=0;i< EnemyBulletMax;i++){
				if (enemyBullet_[i]->GetIsShot() == true) {
					enemyBullet_[i]->Update();
				}
			}

			//クールタイムをデクリメントしていく
			if (shotCurrentCollTime_ > 0.0f) {
				shotCurrentCollTime_--;   
			}
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