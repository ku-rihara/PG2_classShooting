#pragma once


#include "BaseObj.h"

class Enemy : public BaseObj{
private:

	enum MoveMode {
		SPONE,
		ATTACK,
	};

	bool isDeath_;
	MoveMode moveMode_;
	Easing spone_;
	const float sponeMaxFrame_=30.0f;


public:

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

