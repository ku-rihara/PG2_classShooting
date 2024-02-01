#include "SceneManager.h"

BaseScene* SceneManager::currentScene_ = NULL;

SceneManager::SceneManager() {
	scene_=TITLE;
}

void SceneManager::Init() {

}

void SceneManager::CangeScene(int &scene) {

	/*if (currentScene_ != NULL) {
		delete currentScene_;
	}*/

	if (BaseScene::GetIsChange() == true) {
		scene++;
		BaseScene::SetIsChange(false);
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



void SceneManager::Update(char*keys,char*preKyes) {
	currentScene_->Update(keys,preKyes);

}

void SceneManager::Draw() {
	currentScene_->Draw();

}