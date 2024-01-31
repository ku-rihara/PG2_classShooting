#pragma once


#include "BaseObj.h"
#include"EnemyBullet.h"

const int EnemyBulletMax = 10;

class Enemy : public BaseObj{
private:

	EnemyBullet* enemyBullet_[EnemyBulletMax];

	enum AttackMode {
		SHOT,
		ASSAULT,
	};

	bool isSponeEnd_;
	Easing spone_;
	const float sponeMaxFrame_ = 30.0f;

	AttackMode attackMode_;
	Easing Move_;
	int shotCurrentCollTime_;

	bool isDeath_;
	int Hp_;
	
	GH texture_;

public:
	bool isDamage_;

	Enemy(float posX,float posY);
	~Enemy();

	void Init(float posX, float posY);
	void Spone();
	void Update(Vector2 pos);
	void Draw();
	void RenderingPipeline()override;

	//setter
	void SetIsDeath(bool is) { this->isDeath_=is; }

	//getter
	bool GetIsDeath()const { return isDeath_; }
	bool GetIsSponeEnd()const { return isSponeEnd_; }

};

