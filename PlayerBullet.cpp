#include "PlayerBullet.h"


PlayerBullet::PlayerBullet() {

	Init();
	size_ = { 10,10 };
	scale_ = { 1,1 };
	radius_ = { size_.x / 2,size_.y / 2 };
	localVertex_ = MakeLoalVertex(size_);
	velocity_ = { 0,12 };

	texture_.Handle = Novice::LoadTexture("white1x1.png");
}

PlayerBullet::~PlayerBullet() {

}

void PlayerBullet::Init() {

	BaseObj::Init();

	isShot_ = false;
}

void PlayerBullet::Update() {

	worldPos_.y -= velocity_.y;
}

void PlayerBullet::RenderingPipeline() {

	BaseObj::RenderingPipeline();
}

void PlayerBullet::Draw() {

	newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);

}