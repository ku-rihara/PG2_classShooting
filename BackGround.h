#pragma once
#include<Novice.h>

#include"struct.h"

class BackGround{

private:
	
	int background1_;
	int background2_;
	
	GH texture_;
public:

	BackGround();
	void Init();
	void Update();
	void Draw();

};

