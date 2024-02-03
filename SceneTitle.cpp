#include "SceneTitle.h"


SceneTitle::SceneTitle() {

	Init();
	renditionBox_ = new RenditionBox();
	backGround_ = new BackGround();

	title_.Handle = Novice::LoadTexture("./Resources/title.png");
	space_.Handle = Novice::LoadTexture("./Resources/space.png");
}

void SceneTitle::Init() {
	isGameStart_ = false;
}

void SceneTitle::Update(char* keys, char* preKeys) {

	//背景動かす
	backGround_->Update();
	renditionBox_->ScaleDown();


	//スペースキーでシーンチェンジ
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isGameStart_ == false) {
		isGameStart_ = true;
	}

	if (isGameStart_ == true) {
		renditionBox_->ScaleUp();
		if (renditionBox_->GetIsScaleUpEnd() == true) {

			BaseScene::isChange_ = true;
			BaseScene::isIncrement_ = true;
		}
	}
}

void SceneTitle::Draw() {
	backGround_->Draw();
	Novice::DrawSprite(192, 32, title_.Handle, 1, 1, 0, WHITE);
	Novice::DrawSprite(320, 420, space_.Handle, 1, 1, 0, WHITE);

	renditionBox_->Draw();
}

