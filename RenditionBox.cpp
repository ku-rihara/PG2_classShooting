#include "RenditionBox.h"

RenditionBox::RenditionBox() {

	BaseObj::Init();
	isStart_ = false;
	isEnd_ = false;
	scaling_ = {};
	texture_.Handle = Novice::LoadTexture("white1x1.png");
}


void RenditionBox::ScalingInit() {
	BaseObj::Init();
	worldPos_ = { 1280 / 2,720 / 2 };
	scale_ = { 0,0 };
	size_ = { 48,48 };
	localVertex_ = MakeLoalVertex(size_);
	scaling_.easingTime = 0;
	scaling_.easingIncrement = 1;
	scaling_.easingCollTime = 0;
	isStart_ = true;
	isEnd_ = false;
}

void RenditionBox::ScalingUpdate() {

	if (isStart_ == false) {
		ScalingInit();

	}

	if (isStart_ == true&&isEnd_==false) {
		scaling_.easingTime += scaling_.easingIncrement;

		scale_.x = easeInQuart(scaling_.easingTime/ flameMax_, 0, 20);
		scale_.y = easeInQuart(scaling_.easingTime/ flameMax_,0, 20);
		theta_ += (1.0f / 10.0f) *float(M_PI);

		//折り返す
		if (scaling_.easingTime >= flameMax_&&scaling_.isReturn==false) {
			scaling_.easingCollTime++;
			if (scaling_.easingCollTime >= 30) {
				scaling_.easingCollTime = 0;
				scaling_.isReturn = true;
				scaling_.easingIncrement = -scaling_.easingIncrement;
			}
		}
		
		if (scaling_.easingTime < 0) {
			isEnd_ = true;
			scaling_.easingCollTime = 0;
			scale_ = { 0,0 };

		}
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