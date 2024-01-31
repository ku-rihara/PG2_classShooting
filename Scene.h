#pragma once

#include<Novice.h>

//class
#include"player.h"
#include"Enemy.h"
#include"RenditionBox.h"


class Scene{
public:

	//包含
	Player* player_;
	Enemy* enemy_;
	RenditionBox *renditionBox_;

	enum  {
		TITLE,
		PLAY,
		CLEAR,
	};

	static int sceneNo_;
	bool isChange_;

	int background1_;
	int background2_;
	

	//画像
	GH backGround;

public:

	Scene();

	void Init();
	void Update(char* keys,char* preKeys);
	void Draw();

};

