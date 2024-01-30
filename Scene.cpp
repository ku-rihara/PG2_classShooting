#include "Scene.h"

Scene::Scene() {

	player_ = new Player();
	enemy_ = new Enemy(500,100);
	renditionBox_ = new RenditionBox();

	Init();
	backGround.Handle = Novice::LoadTexture("white1x1.png");
}

void Scene::Init() {
	sceneNo_ = TITLE;
	isChange_ = false;
	player_->Init();
	enemy_->Init(500,100);
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
			renditionBox_->ScalingUpdate();
			if (renditionBox_->GetIsReturn() == true) {
				sceneNo_ = PLAY;
			}
		}

		break;

		//ゲームプレイ中の処理
	case PLAY:
		renditionBox_->ScalingUpdate();
		player_->Update(keys,preKeys);
		enemy_->Update();

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
		renditionBox_->Draw();
		break;

	case PLAY:

		Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);

		player_->Draw();
		renditionBox_->Draw();
		break;

	case CLEAR:

		break;

	}
}