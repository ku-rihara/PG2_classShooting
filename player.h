#pragma once

#include"struct.h"

//class
#include"BaseObj.h"
#include"PlayerBullet.h"


class Player:public BaseObj{

private:
	//包含
	PlayerBullet* bullet_[playerBulletMax];

	//定数
	const int damageCollTime_ = 20;
	const int hpMax = 10;

	bool isDamage_;

	int shotCurrentCollTime_;
	int damageCurrentCollTime_;
	int hp_;

	bool isDeath_;

	//画像
	GH texture_;

public:
	
	Player();//コンストラクタ
	~Player();//デストラクタ

	void Init()override;
	void Update(char *keys,char *preKeys);
	void Shot(char* keys);
	void Draw();

	void NoGravityMove(Vector2& pos, Vector2& speed,char* keys);
    void RenderingPipeline()override;

	//getter
	int GetHp()const { return hp_; }
	bool GetIsDamage()const { return isDamage_; }
	bool GetIsDeath()const { return isDeath_; }
	PlayerBullet* GetBullet(int i)const { return bullet_[i]; }

	//setter
	void SetIsDamage(bool is) { this->isDamage_ = is; }
};

