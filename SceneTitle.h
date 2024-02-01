#pragma once

//base
#include "BaseScene.h"

//obj
#include"RenditionBox.h"

class SceneTitle :public BaseScene {

private:

	RenditionBox* renditionBox_;
	bool isScreenTransitions_;

public:

	SceneTitle();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

};

