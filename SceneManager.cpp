#include "SceneManager.h"

BaseScene* SceneManager::currentScene_ = NULL;

SceneManager::SceneManager() {



}

void SceneManager::Init() {

}

void SceneManager::CangeScene(SCENE scene) {

	if (currentScene_ != NULL) {
		delete currentScene_;
	}

	switch (scene) {

	case SCENE::TITLE:
		currentScene_ = new SceneTitle();
		break;

	case SCENE::PLAY:
		currentScene_ = new ScenePlay();
		break;

	case SCENE::CLEAR:
		currentScene_ = new SceneClear();
		break;

	default:
		break;
	}
}

void SceneManager::Update(char*keys,char*preKeys) {

	switch (scene) {

	case TITLE://タイトルの処理-----------------------------------------------------------------

		//背景動かす
		background1_ += 1;
		background2_ += 1;
		if (background1_ == 720) {
			background1_ = 0;
			background2_ = -720;
		}

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
		
	case PLAY://ゲームプレイ中の処理-------------------------------------------------------------
		//背景動かす
		
		break;

		//クリア画面の処理
	case CLEAR:

		break;

	}
}

void SceneManager::Draw() {


	switch (sceneNo_) {

	case TITLE:
		Novice::DrawSprite(0, background1_, backGround.Handle, 1, 1, 0, WHITE);
		Novice::DrawSprite(0, background2_, backGround.Handle, 1, 1, 0, WHITE);
		renditionBox_->Draw();
		break;

	case PLAY:

		Novice::DrawSprite(0, background1_, backGround.Handle, 1, 1, 0, WHITE);
		Novice::DrawSprite(0, background2_, backGround.Handle, 1, 1, 0, WHITE);

		player_->Draw();
		enemy_->Draw();
		renditionBox_->Draw();
		break;

	case CLEAR:

		break;

	}

	
}

void SceneManager::Update(char*keys,char*preKyes) {
	currentScene_->Update(keys,preKyes);

}

void SceneManager::Draw() {
	currentScene_->Draw();

}