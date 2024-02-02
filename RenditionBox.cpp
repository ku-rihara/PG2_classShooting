#include "RenditionBox.h"

RenditionBox::RenditionBox() {

	BaseObj::Init();
	isStart_ = false;
	isEnd_ = false;
	scaling_ = {};
	texture_.Handle = Novice::LoadTexture("white1x1.png");
}

RenditionBox::~RenditionBox() {

}


void RenditionBox::ScalingInit() {
	BaseObj::Init();
	worldPos_ = { 1280 / 2,720 / 2 };
	scale_ = { 0,0 };
	size_ = { 48,48 };
	localVertex_ = MakeLoalVertex(size_);
	scaling_.easingTime = 0;
	scaling_.easingCollTime = 0;
	isStart_ = true;
	scaling_.isReturn = false;
	isEnd_ = false;
}

void RenditionBox::ScaleUp() {

	if (isStart_ == false) {
		ScalingInit();

	}

	if (isStart_ == true) {
		scaling_.easingTime ++;

		scale_.x = easeInQuart(scaling_.easingTime/ flameMax_, 0, 20);
		scale_.y = easeInQuart(scaling_.easingTime/ flameMax_,0, 20);
		theta_ += (1.0f / 10.0f) *float(M_PI);

		//折り返しフラグを立てる
		if (scaling_.easingTime >= flameMax_&&scaling_.isReturn==false) {
			scaling_.easingCollTime++;
			if (scaling_.easingCollTime >= 30) {
				scaling_.easingCollTime = 0;
				scaling_.isReturn = true;
				isStart_ = false;
				
			}
		}
	}

	RenderingPipeline();
}

void RenditionBox::ScaleDown() {

	if (isStart_ == false&& isEnd_ == false) {
		ScalingInit();
		scaling_.easingTime = flameMax_;
	}

	//始まった
	if (isStart_ == true) {
		scaling_.easingTime--;

		scale_.x = easeInQuart(scaling_.easingTime / flameMax_, 0, 20);
		scale_.y = easeInQuart(scaling_.easingTime / flameMax_,0, 20);
		theta_ += (1.0f / 10.0f) * float(M_PI);

		//イージングを止める
		if (scaling_.easingTime <= 0) {
			isStart_ = false;
			scaling_.easingTime = 0;
			isEnd_ = true;
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
	Novice::ScreenPrintf(0, 20, "%f", scale_.x);
}