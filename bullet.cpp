#include "bullet.h"


Bullet::Bullet() {

	Init();
	size_ = { 10,10 };
	scale_ = { 1,1 };
	radius_ = { size_.x / 2,size_.y / 2 };
	localVertex_ = MakeLoalVertex(size_);
	velocity_ = { 0,6 };

	texture_.Handle = Novice::LoadTexture("white1x1.png");
}

Bullet::~Bullet() {

}

void Bullet::Init() {

	BaseObj::Init();

	isShot_ = false;
}

void Bullet::Update() {

	worldPos_.y -= velocity_.y;
}

void Bullet::RenderingPipeline() {

	BaseObj::RenderingPipeline();
}

void Bullet::Draw() {

	newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);

}