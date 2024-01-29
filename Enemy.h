#pragma once
#include "BaseObj.h"

class Enemy : public BaseObj{
private:

	bool isDeath_;


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

