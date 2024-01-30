#include "Scene.h"

Scene::Scene() {

	player_ = new Player;

	Init();
	backGround.Handle = Novice::LoadTexture("white1x1.png");
}

void Scene::Init() {
	sceneNo_ = TITLE;
	isChange_ = false;
	player_->Init();
}

void Scene::Update(char*keys,char*preKeys) {

	switch (sceneNo_) {

		//タイトルの処理
	case TITLE:
		//スペースキーでシーンチェンジ
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0&&isChange_==false) {
			isChange_ = true;
		}

		if (isChange_ == true) {

		}

		break;

		//ゲームプレイ中の処理
	case PLAY:
		player_->Update(keys,preKeys);

		break;

		//クリア画面の処理
	case CLEAR:

		break;

	}
}

void Scene::Draw() {


	switch (sceneNo_) {

	case TITLE:
		Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);

		break;

	case PLAY:

		Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);

		player_->Draw();

		break;

	case CLEAR:

		break;

	}
}