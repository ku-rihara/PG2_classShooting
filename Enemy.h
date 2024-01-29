#pragma once
#include "BaseObj.h"

class Enemy : public BaseObj{
private:

	bool isDeath_;


public:

	Enemy();
	~Enemy();

	void Init()override;
	void Update();
	void RenderingPipeline()override;
	void Draw();

};

