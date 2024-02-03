#include "Enemy.h"

Enemy::Enemy() {
	Init();

	isResporn_ = false;

	for (int i = 0; i < EnemyBulletMax; i++) {
		bullet_[i] = new EnemyBullet;
	}

	texture_.Handle = Novice::LoadTexture("white1x1.png");
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
	life_ = lifeMax_;

	BaseObj::Init();
}


void Enemy::Update(Vector2 pos) {

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
	if (isDamage_ == true) {
		hp_--;
		isDamage_ = false;
	}
	//HP0以下で死亡
	if (hp_ <= 0&&isDeath_==false) {
		isDeath_ = true;
		life_--;
		deathCollTime_ = deathCollTimeMax_;
	}

	//死亡時の処理
	if (isDeath_ == true) {	
		deathCollTime_--;

		if (deathCollTime_ <= 0) {

			if (life_ > 0) {
				Init();
				isResporn_ = true;
			}
		}
	}

	Respone();

	for (int i = 0; i < EnemyBulletMax; i++) {
		bullet_[i]->RenderingPipeline();
	}
}

void Enemy::Draw() {

	for (int i = 0; i < EnemyBulletMax; i++) {
		if (bullet_[i]->GetIsShot() == true) {
			bullet_[i]->Draw();
		}
	}

	if (isDeath_ == false) {
		if (isDamage_ == false) {
			newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);
		}
		else if (isDamage_ == true) {
			newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, RED);
		}
	}

	for (int i = 0; i < EnemyBulletMax; i++) {
		Novice::ScreenPrintf(0, 100+i * 20, "%d", bullet_[i]->GetIsShotEnd()); 
	}
	Novice::ScreenPrintf(0, 600, "%d", isAttackModeChange_);
	Novice::ScreenPrintf(0, 620, "%d", attackMode_);
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

	//全て弾が画面外に行ったら
	/*if (bullet_[9]->GetIsShotEnd() == true) {
			isAttackModeChange_ = true;

		}*/
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
			worldPos_.x = easeOutCirc(assault_.easingTime / assaultMaxFlame_, savePos_.x, startPos_.x);
			worldPos_.y = easeOutCirc(assault_.easingTime / assaultMaxFlame_, savePos_.y, startPos_.y);

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
	if (spone_.isEasing == true) {
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
	}
	//出現イージングフラグが立ったらスケールをイージング
	if (spone_.isEasing == true) {
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