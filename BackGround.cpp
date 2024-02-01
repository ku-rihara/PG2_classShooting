#include "BackGround.h"

BackGround::BackGround() {
	Init();
	texture_.Handle = Novice::LoadTexture("./Resources/backGround.png");
}

void BackGround::Init() {
	background1_ = 0;
	background2_ = -720;
}

void BackGround::Update() {
	background1_ += 1;
	background2_ += 1;
	if (background1_ == 720) {
		background1_ = 0;
		background2_ = -720;
	}
}

void BackGround::Draw() {
	Novice::DrawSprite(0, background1_, texture_.Handle, 1.43f, 1, 0, WHITE);
	Novice::DrawSprite(0, background2_, texture_.Handle, 1.43f, 1, 0, WHITE);
}