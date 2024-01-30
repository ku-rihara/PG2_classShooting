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
	int life_;
	bool isDeath_;

	//画像
	GH texture_;

public:

	bool isDamage_;
	
	Player();//コンストラクタ
	~Player();//デストラクタ

	void Init()override;
	void Update(char *keys,char *preKeys);
	void Draw();

	void NoGravityMove(Vector2& pos, Vector2& speed,char* keys);
    void RenderingPipeline()override;

	//getter
	int GetLife()const { return life_; }
	bool GetIsDamage()const { return isDamage_; }

	//setter
	void SetIsDamage(bool is) { this->isDamage_ = is; }
};

