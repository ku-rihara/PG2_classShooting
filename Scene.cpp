#include "Scene.h"

Scene::Scene() {

	player_ = new Player;

	Init();
}

void Scene::Init() {
	SceneNo_ = 0;
	player_->Init();
}

void Scene::Update(char*keys,char*preKeys) {

	if (keys[DIK_E] && preKeys[DIK_E] == 0) {
		SceneNo_++;
	}

	switch (SceneNo_) {

		//タイトルの処理
	case TITLE:

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


	switch (SceneNo_) {

	case TITLE:

		break;

	case PLAY:

		player_->Draw();

		break;

	case CLEAR:

		break;

	}
}