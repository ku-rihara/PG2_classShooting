#include "RenditionBox.h"

RenditionBox::RenditionBox() {
	
	BaseObj::Init();
	ScalingInit();
	scaling_ = {};
	isScaleUpEnd_ = false;
	isScaleDownEnd_ = false;
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
	isScaleUpStart_ = false;
	isScaleDownStart_ = false;
	
}

void RenditionBox::ScaleUpInit() {
	ScalingInit();
	isScaleUpStart_ = true;
	isScaleDownStart_ = false;
}

void RenditionBox::ScaleDownInit() {
	ScalingInit();
	isScaleUpStart_ = false;
	isScaleDownStart_ = true;
}

void RenditionBox::ScaleUp() {

	if (isScaleUpStart_ == false && isScaleUpEnd_ == false) {
		ScaleUpInit();
		isScaleDownStart_ = false;
		isScaleUpStart_ = true;

	}

	if (isScaleUpStart_ == true) {
		scaling_.easingTime ++;
		scale_.x = easeInQuart(scaling_.easingTime/ flameMax_, 0, 20);
		scale_.y = easeInQuart(scaling_.easingTime/ flameMax_,0, 20);
		theta_ += (1.0f / 10.0f) *float(M_PI);

		//折り返しフラグを立てる
		if (scaling_.easingTime >= flameMax_) {
			scaling_.easingCollTime++;
			if (scaling_.easingCollTime >= 30) {
				scaling_.easingCollTime = 0;
				isScaleUpStart_ = false;
				isScaleUpEnd_ = true;
				
			}
		}
	}

	RenderingPipeline();
}

void RenditionBox::ScaleDown() {

	if (isScaleDownStart_ == false&& isScaleDownEnd_ == false&& isScaleUpStart_ ==false ) {
		ScaleDownInit();
		scaling_.easingTime = flameMax_;
	}

	//始まった
	if (isScaleDownStart_ == true) {
		scaling_.easingTime--;

		scale_.x = easeInQuart(scaling_.easingTime / flameMax_, 0, 20);
		scale_.y = easeInQuart(scaling_.easingTime / flameMax_,0, 20);
		theta_ += (1.0f / 10.0f) * float(M_PI);

		//イージングを止める
		if (scaling_.easingTime <= 0) {
			isScaleDownStart_ = false;
			isScaleDownEnd_ = true;
			scaling_.easingTime = 0;
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