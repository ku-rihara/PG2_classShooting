#include "Enemy.h"

Enemy::Enemy(float posX, float posY) {
	Init(posX, posY);

	for (int i = 0; i < EnemyBulletMax; i++) {
		bullet_[i] = new EnemyBullet;
	}

	texture_.Handle = Novice::LoadTexture("white1x1.png");
}


Enemy::~Enemy() {

}

void Enemy::Init(float posX, float posY) {

	startPos_.x = posX;
	startPos_.y = posY;
	worldPos_ = startPos_;
	size_ = { 64,64 };
	radius_ = { size_.x / 2,size_.y / 2 };
	localVertex_ = MakeLoalVertex(size_);
	spone_.easingTime = 0;
	isDeath_ = false;
	spone_.isEasing = false;

	BaseObj::Init();

}

void Enemy::Spone() {
	//出現イージングフラグを立てる
	if (isDeath_ == false && spone_.isEasing == false) {
		spone_.isEasing = true;
	}
	//出現イージングフラグが立ったらスケールをイージング
	if (spone_.isEasing == true) {
		spone_.easingTime++;
		scale_.x = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);
		scale_.y = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);

		//イージングが終わったらシューティングモードに切り替わる
		if (spone_.easingTime >= sponeMaxFrame_) {
			spone_.easingTime = sponeMaxFrame_;

			attackMode_ = SHOT;
			isSponeEnd_ = true;
		}
	}
}

void Enemy::Update(Vector2 pos) {

	//アタックモードチェンジ
	if (isAttackModeChange_ == true) {

		//ショット➩突進
		if (attackMode_ == SHOT) {
			attackMode_ = ASSAULT;
			assaultCount_ = 0;
			assault_.easingTime = 0;
			assault_.easingCollTime = 0;
			isAttackModeChange_ = false;
		}
		//突進➩ショット
		else if (attackMode_ == ASSAULT) {
			attackMode_ = SHOT;
			isAttackModeChange_ = false;
		}
	}
	//弾を撃つ処理
	if (attackMode_ == SHOT) {
		Shot(pos);
	}
	//突進する処理
	else if (attackMode_ == ASSAULT) {
		Assault(pos);
	}

	//ダメージを受けたらの処理


	//レンダリングパイプライン
	RenderingPipeline();
}

void Enemy::Draw() {
	if (isDamage_ == false) {
		newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);
	}
	else if (isDamage_ == true) {
		newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, RED);
	}
}


void Enemy::Shot(Vector2 pos) {

	for (int i = 0; i < EnemyBulletMax; i++) {
		//プレイヤーをロックオン
		if (bullet_[i]->GetIsShot() == false && shotCurrentCollTime_ <= 0) {
			bullet_[i]->SetIsShot(true);
			bullet_[i]->SetWorldPosX(worldPos_.x);
			bullet_[i]->SetWorldPosY(worldPos_.y);
			bullet_[i]->SetDirection(normalize(worldPos_, pos));
			break;
		}
	}
	//弾の発射
	for (int i = 0; i < EnemyBulletMax; i++) {
		if (bullet_[i]->GetIsShot() == true) {
			bullet_[i]->Update();
		}
		//画面外に出たら撃ち終わったかのフラグを立てる
		if (bullet_[i]->GetWorldPos().y <= -bullet_[i]->GetRadius().y || bullet_[i]->GetWorldPos().y >= 720 + bullet_[i]->GetRadius().y ||
			bullet_[i]->GetWorldPos().x <= -bullet_[i]->GetRadius().x || bullet_[i]->GetWorldPos().x >= 1280 + bullet_[i]->GetRadius().x) {
			bullet_[i]->SetIsShotEnd(true);
		}
	}

	//全て弾が画面外に行ったら、合ったくもーどを切り替える
	for (int i = 0; i < EnemyBulletMax; i++) {
		if (bullet_[i]->GetIsShotEnd() == false) {
			isAttackModeChange_ = false;
			break;
		}
		else {
			isAttackModeChange_ = true;
		}
	}

	//クールタイムをデクリメントしていく
	if (shotCurrentCollTime_ > 0.0f) {
		shotCurrentCollTime_--;
	}
}

void Enemy::Assault(Vector2 pos) {

	if (assault_.isEasing == false) {
		savePos_ = worldPos_;
		assaultPos_ = pos;
		assault_.isEasing = true;
	}

	if (assaultCount_ < 5) {
		//突進イージング
		if (assault_.isEasing == true && assault_.easingCollTime <= 0) {
			assault_.easingTime++;
			worldPos_.x = easeInQuart(assault_.easingTime / assaultMaxFlame_, savePos_.x, assaultPos_.x);
			worldPos_.y = easeInQuart(assault_.easingTime / assaultMaxFlame_, savePos_.y, assaultPos_.y);

			//MAXフレームに到達したらフラグを降ろす
			if (assault_.easingTime >= assaultMaxFlame_) {
				assault_.easingTime = assaultMaxFlame_;
				assault_.isEasing = false;
				assault_.easingCollTime = 30;
				assaultCount_++;
			}
		}

	}
	else if(assaultCount_ == 5){
		//突進イージング
		if (assault_.isEasing == true && assault_.easingCollTime <= 0) {
			assault_.easingTime++;
			worldPos_.x = easeInQuart(assault_.easingTime / assaultMaxFlame_, savePos_.x, startPos_.x);
			worldPos_.y = easeInQuart(assault_.easingTime / assaultMaxFlame_, savePos_.y, startPos_.y);

			//MAXフレームに到達したらフラグを降ろす
			if (assault_.easingTime >= assaultMaxFlame_) {
				assault_.easingTime = assaultMaxFlame_;
				assault_.isEasing = false;
				isAttackModeChange_ = true;
				
			}
		}
	}

	//イージングクールタイムを減らす
	if (assault_.easingCollTime >= 0) {
		assault_.easingCollTime--;
	}
}


//レンダリングパイプライン
void Enemy::RenderingPipeline() {
	BaseObj::RenderingPipeline();
}