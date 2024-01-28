#pragma once

#include<Novice.h>

//class
#include"player.h"



class Scene{
public:

	//包含
	Player* player_;

	enum  {
		TITLE,
		PLAY,
		CLEAR,
	};

	static int SceneNo_;

public:

	Scene();

	void Init();
	void Update(char* keys,char* preKeys);
	void Draw();

};

