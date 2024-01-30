#pragma once

#include<Novice.h>

//class
#include"player.h"
#include"Enemy.h"


class Scene{
public:

	//包含
	Player* player_;
	Enemy* enemy_;

	enum  {
		TITLE,
		PLAY,
		CLEAR,
	};

	static int sceneNo_;
	bool isChange_;

	GH backGround;

public:

	Scene();

	void Init();
	void Update(char* keys,char* preKeys);
	void Draw();

};

