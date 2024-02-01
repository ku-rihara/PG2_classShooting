#pragma once

#include<Novice.h>

//class
#include"BaseScene.h"
#include"SceneTitle.h"
#include"ScenePlay.h"
#include"SceneClear.h"


class SceneManager{
private:

	//包含
	static BaseScene* currentScene_;

public:

	enum  SCENE {
		TITLE,
		PLAY,
		CLEAR,
	};

	SceneManager();

	static void CangeScene(SCENE scene);
	static void Init();
	static void Update(char*keys,char*prekeys);
	static void Draw();

};

