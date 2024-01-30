#include "RenditionBox.h"

RenditionBox::RenditionBox() {

	BaseObj::Init();
	isStart_ = false;
	texture_.Handle = Novice::LoadTexture("white1x1.png");
}
RenditionBox::~RenditionBox() {

}

void RenditionBox::ScalingInit() {
	BaseObj::Init();
	worldPos_ = { 1280 / 2,720 / 2 };
	size_ = { 48,48 };
	localVertex_ = MakeLoalVertex(size_);
	isStart_ = false;
}

void RenditionBox::ScalingUpdate() {

	if (isStart_ == false) {
		ScalingInit();
		isStart_ = true;
	}

	if (isStart_ == true) {
		easingTime_++;
		scale_.x = easeInQuart(easingTime_, 0, 20);
		scale_.y = easeInQuart(easingTime_, 0, 20);
	}

	RenderingPipeline();
}

//レンダリングパイプライン
void RenditionBox::RenderingPipeline() {
	BaseObj::RenderingPipeline();
}

void RenditionBox::Draw() {

	newDrawQuad(screenVertex_, 0, 0, size_.x, size_.y, texture_.Handle, WHITE);
}