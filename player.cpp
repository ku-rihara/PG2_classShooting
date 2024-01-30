#include "player.h"

Player::Player() {

	for (int i = 0; i < bulletMax; i++) {
		bullet_[i] = new Bullet();
	}

	Init();
	texture_.Handle = Novice::LoadTexture("white1x1.png");
}

Player::~Player() {

}

void Player::Init() {

	BaseObj::Init();

	scale_ = { 1,1 };
	size_ = { 32,32 };
	radius_ = { size_.x / 2,size_.y / 2 };
	velocity_ = { 4,4 };
	isDeath_ = false;

	localVertex_ = MakeLoalVertex(size_);
}

void Player::Update(char* keys, char* preKeys) {

	if (preKeys) {

	}

	//プレイヤーの移動
	NoGravityMove(worldPos_, velocity_, keys);

	//プレイヤーの弾発射
	if (keys[DIK_SPACE]) {
		for (int i = 0; i < bulletMax; i++) {

			//撃ってない状態だったら
			if (bullet_[i]->GetIsShot() == false&&shotCurrentCollTime_<=0) {

				bullet_[i]->SetIsShot(true);//フラグ立てる
				bullet_[i]->SetWorldPosX(worldPos_.x);
				bullet_[i]->SetWorldPosY(worldPos_.y);
				shotCurrentCollTime_=bullet_[i]->GetCollTime();
				break;
			}
		}
	}
	//弾の移動処理
	for (int i = 0; i < bulletMax; i++) {

		if (bullet_[i]->GetIsShot() == true) {
			bullet_[i]->Update();
		}

		if (bullet_[i]->GetWorldPos().y <= -bullet_[i]->GetRadius().y) {
			bullet_[i]->SetIsShot(false);
		}
	}

	//クールタイムをデクリメントしていく
	if (shotCurrentCollTime_ > 0.0f) {
		shotCurrentCollTime_--;
	}

	//レンダリングパイプライン
	RenderingPipeline();

	for (int i = 0; i < bulletMax; i++) {
		bullet_[i]->RenderingPipeline();
	}

}
void Player::Draw() {

	for (int i = 0; i < bulletMax; i++) {
		bullet_[i]->Draw();
	
	}
	newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);


}

void Player::RenderingPipeline() {
	BaseObj::RenderingPipeline();
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
}

