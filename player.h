#pragma once

#include"struct.h"

//class
#include"BaseObj.h"
#include"bullet.h"


class Player:public BaseObj{

private:
	//包含
	Bullet* bullet_[bulletMax];

	int shotCurrentCollTime_;
	bool isDeath_;

	//画像
	GH texture_;

public:
	
	Player();//コンストラクタ
	~Player();//デストラクタ

	void Init()override;
	void Update(char *keys,char *preKeys);
	void NoGravityMove(Vector2& pos, Vector2& speed,char* keys);
    void RenderingPipeline()override;
	void Draw();

};

