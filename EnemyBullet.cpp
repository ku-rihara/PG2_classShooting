#include "EnemyBullet.h"


EnemyBullet::EnemyBullet() {

	Init();
	size_ = { 32,32 };
	scale_ = { 1,1 };
	radius_ = { size_.x / 2,size_.y / 2 };
	localVertex_ = MakeLoalVertex(size_);
	velocity_ = { 6,6 };

	texture_.Handle = Novice::LoadTexture("white1x1.png");
}

EnemyBullet::~EnemyBullet() {

}

void EnemyBullet::Init() {

	BaseObj::Init();
	isShot_ = false;
}

void EnemyBullet::Update() {

	worldPos_.x += direction_.x*velocity_.x;
	worldPos_.y += direction_.y*velocity_.y;
}

void EnemyBullet::RenderingPipeline() {

	BaseObj::RenderingPipeline();
}

void EnemyBullet::Draw() {

	newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);

}