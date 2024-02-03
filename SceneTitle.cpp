#include "SceneTitle.h"


SceneTitle::SceneTitle() {

	Init();
	renditionBox_ = new RenditionBox();
	backGround_ = new BackGround();
}

void SceneTitle::Init() {
	isScreenTransitions_ = false;
}

void SceneTitle::Update(char* keys, char* preKeys) {

	//背景動かす
	backGround_->Update();

		renditionBox_->ScaleDown();
	

	//スペースキーでシーンチェンジ
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isScreenTransitions_ == false) {
		isScreenTransitions_ = true;
	}

	if (isScreenTransitions_ == true) {
		renditionBox_->ScaleUp();
		if (renditionBox_->GetIsScaleUpEnd() == true) {
		
			BaseScene::isChange_ = true;
			BaseScene::isIncrement_ = true;
		}
	}
}

void SceneTitle::Draw() {
	backGround_->Draw();
	renditionBox_->Draw();
}

