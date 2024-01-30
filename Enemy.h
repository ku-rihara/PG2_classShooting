#pragma once


#include "BaseObj.h"

class Enemy : public BaseObj{
private:

	enum MoveMode {
		SPONE,
		ATTACK,
	};

	enum AttackLevel {
		LEVEL1,
		LEVEL2,
		LEVEL3,
	};

	MoveMode moveMode_;
	AttackLevel attacklevel_;
	Easing spone_;
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

