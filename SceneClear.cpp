#include "SceneClear.h"

#include<Novice.h>

SceneClear::SceneClear() {
	Init();
	renditionBox_ = new RenditionBox();
	clear_.Handle = Novice::LoadTexture("./Resources/clear.png");
	space_.Handle= Novice::LoadTexture("./Resources/space_white.png");
}

void SceneClear::Init() {
	isBackTitle_ = false;
}

void SceneClear::Update(char* keys, char* preKeys) {

	renditionBox_->ScaleDown();//演出ブロックの更新
	//スペースキーでシーンチェンジ
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isBackTitle_ == false) {
		isBackTitle_ = true;
	}
	//タイトルに戻る
	if (isBackTitle_ == true) {
		renditionBox_->ScaleUp();
		if (renditionBox_->GetIsScaleUpEnd() == true) {

			BaseScene::isChange_ = true;
			BaseScene::isIncrement_ = true;
		}
	}
}

void SceneClear::Draw() {

	Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
	Novice::DrawSprite(152, 10, clear_.Handle, 1, 1, 0, WHITE);
	Novice::DrawSprite(320, 420, space_.Handle, 1, 1, 0, WHITE);
	renditionBox_->Draw();
}

