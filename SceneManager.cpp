#include "SceneManager.h"

BaseScene* SceneManager::currentScene_ = NULL;

SceneManager::SceneManager() {
	BaseScene::SetIsChange(true);
	scene_ = -1;
}

void SceneManager::Init() {
}

void SceneManager::CangeScene(int& scene) {

	//シーン切り替え処理
	if (BaseScene::GetIsChange()) {
		scene++;
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
	}
}

void SceneManager::Update(char* keys, char* preKeys) {

	currentScene_->Update(keys, preKeys);

}

void SceneManager::Draw() {

	currentScene_->Draw();

}