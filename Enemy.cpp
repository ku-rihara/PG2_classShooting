#include "Enemy.h"

Enemy::Enemy() {
	Init();

	isResporn_ = false;
	life_ = lifeMax_;

	for (int i = 0; i < EnemyBulletMax; i++) {
		bullet_[i] = new EnemyBullet;
	}

	texture_.Handle = Novice::LoadTexture("./Resources/enemy.png");
}


Enemy::~Enemy() {

}

void Enemy::Init() {

	//座標
	startPos_.x = 500;
	startPos_.y = 100;
	worldPos_ = startPos_;

	//スポーン
	spone_.easingTime = 0;
	spone_.isEasing = false;

	//サイズ
	size_ = { 64,64 };
	scale_ = { 0,0 };
	radius_ = { size_.x / 2,size_.y / 2 };
	localVertex_ = MakeLoalVertex(size_);

	//フラグ
	isDeath_ = false;
	isDamage_ = false;
	isAttackModeChange_ = false;

	//ライフ
	hp_ = hpMax_;

	BaseObj::Init();
}


void Enemy::Update(Vector2 pos) {
	if (isResporn_ == false && life_ > 0) {
		//アタックモードチェンジ
		if (isAttackModeChange_ == true) {

			//ショット➩突進
			if (attackMode_ == SHOT) {
				attackMode_ = ASSAULT;
				AttackInit();
				isAttackModeChange_ = false;
			}
			//突進➩ショット
			else if (attackMode_ == ASSAULT) {
				attackMode_ = SHOT;
				AttackInit();
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

		//HPを減らす処理
		if (isDamage_ == true && damageCurrentCollTime_ == 0) {
			hp_--;
			damageCurrentCollTime_ = damageCollTime_;
			isDamage_ = false;
		}
		//HP0以下で死亡
		if (hp_ <= 0 && isDeath_ == false) {
			isDeath_ = true;
			life_--;
			deathCollTime_ = deathCollTimeMax_;
		}

		//クールタイムをデクリメント
		if (damageCurrentCollTime_ >= 0) {
			damageCurrentCollTime_--;
		}

		if (damageCurrentCollTime_ < 0) {
			damageCurrentCollTime_ = 0;
		}
	}

	//死亡時の処理
	if (isDeath_ == true) {
		deathCollTime_--;

		if (deathCollTime_ <= 0) {

			//リスポーン
			if (life_ > 0) {
				Init();
				isResporn_ = true;
			}
			//完全死亡
			else if (life_ == 0) {
				isLose_ = true;
			}
		}
	}

	Respone();

	for (int i = 0; i < EnemyBulletMax; i++) {
		bullet_[i]->RenderingPipeline();
	}
}

void Enemy::Draw() {

	if (isDeath_ == false) {
		//弾の描画
		for (int i = 0; i < EnemyBulletMax; i++) {
			if (bullet_[i]->GetIsShot() == true) {
				bullet_[i]->Draw();
			}
		}
		//敵の描画
		if (isDeath_ == false) {

			if (isDamage_ == true && damageCurrentCollTime_ <= 0) {
				newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, RED);
			}
			else {
				newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);
			}
		}
	}

}


void Enemy::AttackInit() {

	for (int i = 0; i < EnemyBulletMax; i++) {
		bullet_[i]->SetWorldPosX(worldPos_.x);
		bullet_[i]->SetWorldPosY(worldPos_.y);
		bullet_[i]->SetIsShot(false);
		shotCurrentCollTime_ = 0;
		bullet_[i]->SetIsShotEnd(false);
	}
	assaultCount_ = 0;
	assault_.easingTime = 0;
	assault_.easingCollTime = 0;
	savePos_ = startPos_;
	assaultPos_ = startPos_;
	assault_.isEasing = false;
}

void Enemy::Shot(Vector2 pos) {

	for (int i = 0; i < EnemyBulletMax; i++) {
		//プレイヤーをロックオン
		if (bullet_[i]->GetIsShot() == false && shotCurrentCollTime_ <= 0) {
			bullet_[i]->SetIsShot(true);
			bullet_[i]->SetWorldPosX(worldPos_.x);
			bullet_[i]->SetWorldPosY(worldPos_.y);
			bullet_[i]->SetDirection(normalize(pos, worldPos_));
			shotCurrentCollTime_ = bullet_[i]->GetCollTime();
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
			worldPos_.x = easeOutCirc(assault_.easingTime / assaultMaxFlame_, savePos_.x, assaultPos_.x);
			worldPos_.y = easeOutCirc(assault_.easingTime / assaultMaxFlame_, savePos_.y, assaultPos_.y);
			scale_.x = easeInOutBack(assault_.easingTime / assaultMaxFlame_, 1.5f, 1);
			scale_.y = easeInOutBack(assault_.easingTime / assaultMaxFlame_, 1.5f, 1);

			//MAXフレームに到達したらフラグを降ろす
			if (assault_.easingTime >= assaultMaxFlame_) {
				assault_.easingTime = assaultMaxFlame_;
				assault_.isEasing = false;
				assault_.easingCollTime = 30;
				assaultCount_++;
			}
		}

	}
	else if (assaultCount_ == 5) {
		//突進イージング
		if (assault_.isEasing == true && assault_.easingCollTime <= 0) {
			assault_.easingTime++;
			worldPos_.x = easeOutCirc(assault_.easingTime / assaultMaxFlame_, savePos_.x, startPos_.x);
			worldPos_.y = easeOutCirc(assault_.easingTime / assaultMaxFlame_, savePos_.y, startPos_.y);
			scale_.x = easeInOutBack(assault_.easingTime / assaultMaxFlame_, 1.5f, 1);
			scale_.y = easeInOutBack(assault_.easingTime / assaultMaxFlame_, 1.5f, 1);

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
		assault_.easingTime = 0;
	}
}

void Enemy::Spone() {
	//出現イージングフラグを立てる
	if (isDeath_ == false && spone_.isEasing == false && isSponeEnd_ == false) {
		spone_.isEasing = true;
	}
	//出現イージングフラグが立ったらスケールをイージング
	if (spone_.isEasing == true && isSponeEnd_ == false) {
		spone_.easingTime++;
		scale_.x = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);
		scale_.y = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);

		//イージングが終わったらシューティングモードに切り替わる
		if (spone_.easingTime >= sponeMaxFrame_) {
			spone_.easingTime = sponeMaxFrame_;

			/*attackMode_ = SHOT;*/
			isSponeEnd_ = true;

		}
	}
}

void Enemy::Respone() {
	//出現イージングフラグを立てる
	if (isDeath_ == false && spone_.isEasing == false && isResporn_ == true) {
		spone_.isEasing = true;
		AttackInit();
	}
	//出現イージングフラグが立ったらスケールをイージング
	if (spone_.isEasing == true && isResporn_ == true) {
		spone_.easingTime++;
		scale_.x = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);
		scale_.y = easeOutBack(spone_.easingTime / sponeMaxFrame_, 0, 1);

		//イージングが終わったらシューティングモードに切り替わる
		if (spone_.easingTime >= sponeMaxFrame_) {
			spone_.easingTime = sponeMaxFrame_;

			/*attackMode_ = SHOT;*/
			isResporn_ = false;
		}
	}
}

//レンダリングパイプライン
void Enemy::RenderingPipeline() {
	BaseObj::RenderingPipeline();
}