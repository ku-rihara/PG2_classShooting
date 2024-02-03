#pragma once

#include"BaseScene.h"

class  SceneClear :public BaseScene {





public:

	SceneClear();

	void Init()override;
	void Update(char* keys, char* preKeys)override;
	void Draw()override;

};
