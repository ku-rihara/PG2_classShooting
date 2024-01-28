#include "player.h"

Player::Player() {

	Init();
	texture_.Handle = Novice::LoadTexture("white1x1.png");
}

void Player::Init() {
	
	BaseObj::Init();

	scale_ = {1,1};
	size_ = {32,32};
	velocity_={ 4,4 };

	localVertex_ = MakeLoalVertex(size_);
}

void Player::Update(char* keys, char* preKeys) {

	if (preKeys[DIK_F]) {

	}
	//移動とカメラ変換
	NoGravityMove(worldPos_, velocity_, keys);
	RenderingPipeline();
}
void Player::Draw() {
	
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

