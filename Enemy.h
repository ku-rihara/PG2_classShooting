#pragma once


#include "BaseObj.h"
#include"EnemyBullet.h"

const int EnemyBulletMax = 10;

class Enemy : public BaseObj{
private:

	EnemyBullet* enemyBullet_[EnemyBulletMax];

	enum MoveMode {
		SPONE,
		ATTACK,
	};

	enum AttackMode {
		SHOT,
		ASSAULT,
	};

	MoveMode moveMode_;
	AttackMode attackMode_;
	Easing spone_;
	Easing Move_;
	const float sponeMaxFrame_ = 30.0f;

	bool isDeath_;
	int Hp_;
	
	GH texture_;

public:
	bool isDamage_;

	Enemy(float posX,float posY);
	~Enemy();

	void Init(float posX, float posY);
	void Update();
	void Draw();
	void RenderingPipeline()override;

	//setter
	void SetIsDeath(bool is) { this->isDeath_=is; }

	//getter
	bool GetIsDeath()const { return isDeath_; }

};

