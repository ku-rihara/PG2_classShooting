#include "player.h"

Player::Player() {

	for (int i = 0; i < playerBulletMax; i++) {
		bullet_[i] = new PlayerBullet();
	}

	Init();
	texture_.Handle = Novice::LoadTexture("white1x1.png");
}

Player::~Player() {

}

void Player::Init() {

	BaseObj::Init();
	//座標、サイズ
	worldPos_ = { 500,600 };
	scale_ = { 1,1 };
	size_ = { 32,32 };
	radius_ = { size_.x / 2,size_.y / 2 };
	localVertex_ = MakeLoalVertex(size_);
	hp_ = hpMax;
	//速度
	velocity_ = { 4,4 };


	isDeath_ = false;
	damageCurrentCollTime_ = 0;
}
//更新
void Player::Update(char* keys, char* preKeys) {

	if (preKeys) {

	}

	//プレイヤーの移動
	NoGravityMove(worldPos_, velocity_, keys);

	//弾を撃つ処理
	Shot(keys);
	
	//ダメージを受けた時の処理
	if (isDamage_ == true && damageCurrentCollTime_ <= 0) {
		hp_--;
		damageCurrentCollTime_ = damageCollTime_;
		isDamage_ = false;
	}

	//クールタイムをデクリメント
	if (damageCurrentCollTime_ >= 0) {
		damageCurrentCollTime_--;
	}

	if (damageCurrentCollTime_ < 0) {
		damageCurrentCollTime_ = 0;
	}

	//死亡処理
	if (hp_ <= 0) {
		isDeath_ = true;
	}

	for (int i = 0; i < playerBulletMax; i++) {
		bullet_[i]->RenderingPipeline();
	}

}
//描画
void Player::Draw() {

	for (int i = 0; i < playerBulletMax; i++) {
		if (bullet_[i]->GetIsShot() == true) {
			bullet_[i]->Draw();
		}
	}

	//プレイヤーの描画
	if (damageCurrentCollTime_ % 5 == 0&&isDeath_==false) {
		newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);
	}
}

//弾を撃つ関数
void Player::Shot(char*keys) {
	//プレイヤーの弾発射
	if (keys[DIK_SPACE]) {
		for (int i = 0; i < playerBulletMax; i++) {

			//撃ってない状態だったら
			if (bullet_[i]->GetIsShot() == false && shotCurrentCollTime_ <= 0) {

				bullet_[i]->SetIsShot(true);//フラグ立てる
				bullet_[i]->SetWorldPosX(worldPos_.x);
				bullet_[i]->SetWorldPosY(worldPos_.y);
				shotCurrentCollTime_ = bullet_[i]->GetCollTime();
				break;
			}
		}
	}
	//弾の移動処理
	for (int i = 0; i < playerBulletMax; i++) {

		if (bullet_[i]->GetIsShot() == true) {
			bullet_[i]->Update();
		}
		//画面外に出たらフラグを降ろす
		if (bullet_[i]->GetWorldPos().y <= -bullet_[i]->GetRadius().y) {
			bullet_[i]->SetIsShot(false);
		}
	}

	//クールタイムをデクリメントしていく
	if (shotCurrentCollTime_ > 0.0f) {
		shotCurrentCollTime_--;
	}

}

void Player::NoGravityMove(Vector2& pos, Vector2& speed, char* keys) {

	Vector2 normalizeVelocity;
	Vector2 velocity = {};
	//左移動
	if (keys[DIK_A]) {
		//左上
		if (keys[DIK_W]) {

			velocity.x = -0.7f;

			velocity.y = -0.7f;

		}
		//左下
		else if (keys[DIK_S]) {

			velocity.x = -0.7f;

			velocity.y = 0.7f;

		}
		else {
			velocity.x = -1;
			velocity.y = 0;
		}
	}
	else if (keys[DIK_D]) {

		if (keys[DIK_W]) {

			velocity.x = 0.7f;

			velocity.y = -0.7f;

		}
		else if (keys[DIK_S]) {

			velocity.x = 0.7f;

			velocity.y = 0.7f;

		}
		else {
			velocity.x = 1;
			velocity.y = 0;
		}
	}
	else if (keys[DIK_W]) {

		if (keys[DIK_A]) {

			velocity.x = -0.7f;

			velocity.y = -0.7f;

		}
		else if (keys[DIK_D]) {

			velocity.x = 0.7f;

			velocity.y = -0.7f;

		}
		else {

			velocity.y = -1;
			velocity.x = 0;

		}
	}

	else if (keys[DIK_S]) {

		if (keys[DIK_A]) {

			velocity.x = -0.7f;

			velocity.y = 0.7f;

		}
		else if (keys[DIK_D]) {

			velocity.x = 0.7f;

			velocity.y = 0.7f;

		}
		else {

			velocity.y = 1;
			velocity.x = 0;
		}
	}
	else {

		velocity.x = 0;
		velocity.y = 0;
	}

	if (velocity.x != 0 || velocity.y != 0) {
		normalizeVelocity = normalize(velocity);
	}
	else {
		normalizeVelocity.x = 0;
		normalizeVelocity.y = 0;
	}

	pos.x += normalizeVelocity.x * speed.x;
	pos.y += normalizeVelocity.y * speed.y;

	if (pos.x >= 900-radius_.x) {
		pos.x = 900 - radius_.x;
	}
	if (pos.x <=   radius_.x) {
		pos.x = radius_.x;
	}

	if (pos.y >= 720 - radius_.y) {
		pos.y = 720 - radius_.y;
	}
	if (pos.y <= radius_.y) {
		pos.y = radius_.y;
	}
}


void Player::RenderingPipeline() {
	BaseObj::RenderingPipeline();
}