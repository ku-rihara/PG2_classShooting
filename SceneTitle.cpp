#include "SceneTitle.h"


SceneTitle::SceneTitle() {
	Init();

	renditionBox_ = new RenditionBox();

}

void SceneTitle::Init() {
	isScreenTransitions_ = false;
}

void SceneTitle::Update(char* keys, char* preKeys) {
	////背景動かす
	//background1_ += 1;
	//background2_ += 1;
	//if (background1_ == 720) {
	//	background1_ = 0;
	//	background2_ = -720;
	//}

	//スペースキーでシーンチェンジ
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isScreenTransitions_ == false) {
		isScreenTransitions_ = true;
	}

	if (isScreenTransitions_ == true) {
		renditionBox_->ScalingUpdate();
		if (renditionBox_->GetIsReturn() == true) {
			BaseScene::isChange_ = true;
		}
	}
}

void SceneTitle::Draw() {

	renditionBox_->Draw();
}

