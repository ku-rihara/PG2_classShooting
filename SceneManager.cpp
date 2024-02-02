#include "SceneManager.h"

BaseScene* SceneManager::currentScene_ = NULL;

SceneManager::SceneManager() {
	
	scene_ = TITLE;
}

void SceneManager::Init() {
}

void SceneManager::CangeScene(int &scene) {

	

	if (BaseScene::GetIsChange() == true) {
		scene++;
		if (currentScene_ != NULL) {
			delete currentScene_;
		}
		BaseScene::SetIsChange(false);
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
	
}

void SceneManager::Update(char*keys,char*preKeys) {
	
		currentScene_->Update(keys, preKeys);
	

}

void SceneManager::Draw() {
	
		currentScene_->Draw();

}