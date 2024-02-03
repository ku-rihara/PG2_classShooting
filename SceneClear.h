#pragma once

#include"struct.h"

//class
#include"BaseScene.h"
#include"RenditionBox.h"

class  SceneClear :public BaseScene {

private:
	RenditionBox* renditionBox_;
	bool isBackTitle_;

	GH clear_;
	GH space_;
public:

	SceneClear();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

};
