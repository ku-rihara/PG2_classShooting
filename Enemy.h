#pragma once


#include "BaseObj.h"
#include"EnemyBullet.h"

const int EnemyBulletMax = 10;

class Enemy : public BaseObj{
private:

	//包含
	EnemyBullet* bullet_[EnemyBulletMax];

	//アタックモード
	enum AttackMode {
		SHOT,
		ASSAULT,
	};

	//定数
	const float sponeMaxFrame_ = 30.0f;
	const float assaultMaxFlame_ = 30.0f;
	const int hpMax_ = 50;
	const int lifeMax_ = 2;
	const int deathCollTimeMax_ = 60;

	//座標
	Vector2 startPos_;
	Vector2 savePos_;
	Vector2 assaultPos_;

	//スポーン
	bool isSponeEnd_;
	Easing spone_;


	//突進
	AttackMode attackMode_;
	Easing assault_;
	bool isAttackModeChange_;

	int assaultCount_;

	//弾
	int shotCurrentCollTime_;

	//死亡フラグ、体力
	bool isDeath_;
	int deathCollTime_;
	int hp_;
	int life_;
	
	//画像
	GH texture_;

public:
	bool isDamage_;

	Enemy();
	~Enemy();

	void Init();
	void Spone();
	void Update(Vector2 pos);
	void Shot(Vector2 pos);
	void Assault(Vector2 pos);
	void Draw();
	void RenderingPipeline()override;

	//setter
	void SetIsDeath(bool is) { this->isDeath_=is; }

	//getter
	bool GetIsDeath()const { return isDeath_; }
	bool GetIsSponeEnd()const { return isSponeEnd_; }

};

