#include "SceneManager.h"

BaseScene* SceneManager::currentScene_ = NULL;

SceneManager::SceneManager() {
	BaseScene::SetIsChange(true);
	BaseScene::SetIsIncrement(true);
	scene_ = -1;
}

void SceneManager::Init() {
}

void SceneManager::CangeScene(int& scene) {

	//シーン切り替え処理
	if (BaseScene::GetIsChange()) {

		if (BaseScene::GetIsIncrement()) {
			scene++;
		}
		else if (BaseScene::GetIsDecrement()) {
			scene--;
		}

		if (scene > CLEAR) {
			scene = TITLE;
		}
		if (currentScene_ != NULL) {
			delete currentScene_;
		}


		switch (scene) {

		case TITLE:

			currentScene_ = new SceneTitle();

			break;

		case PLAY:

			currentScene_ = new ScenePlay();

			break;

		case CLEAR:
			currentScene_ = new SceneClear();
			break;

		}
		BaseScene::SetIsChange(false);
		BaseScene::SetIsIncrement(false);
		BaseScene::SetIsDecrement(false);
	}
}

void SceneManager::Update(char* keys, char* preKeys) {

	//各シーンの更新
	currentScene_->Update(keys, preKeys);

}

void SceneManager::Draw() {
	//各シーンの描画
	currentScene_->Draw();

}