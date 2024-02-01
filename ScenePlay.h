#pragma once

//base
#include "BaseScene.h"

//obj
#include"player.h"
#include"Enemy.h"
#include"RenditionBox.h"

class ScenePlay:public BaseScene{

private:

	Player* player_;
	Enemy* enemy_;
	RenditionBox* renditionBox_;

public:

	ScenePlay();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

};

