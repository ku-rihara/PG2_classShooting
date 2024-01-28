#pragma once

#include"struct.h"

//class
#include"BaseObj.h"


class Player:public BaseObj{

private:

	bool isDeath_;

	GH texture_;

public:

	Player();

	void Init()override;
	void Update(char *keys,char *preKeys);
	void NoGravityMove(Vector2& pos, Vector2& speed,char* keys);
    void RenderingPipeline()override;
	void Draw();

};

