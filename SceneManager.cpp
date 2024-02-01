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



void SceneManager::Update(char*keys,char*preKyes) {
	currentScene_->Update(keys,preKyes);

}

void SceneManager::Draw() {
	currentScene_->Draw();

}