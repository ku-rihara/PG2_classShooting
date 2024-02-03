#pragma once

//base
#include "BaseScene.h"

//obj
#include"player.h"
#include"Enemy.h"
#include"RenditionBox.h"
#include"OperateUI.h"

//colligion
#include"Colligion.h"

#include"BackGround.h"

class ScenePlay:public BaseScene{

private:

	Player* player_;
	Enemy* enemy_;
	RenditionBox* renditionBox_;
	Colligion* colligion_;
	BackGround* background_;
	OperateUI* operateUI_;

public:

	ScenePlay();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

};

