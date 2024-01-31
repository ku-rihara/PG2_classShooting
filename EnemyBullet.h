#pragma once

#include"BaseObj.h"


class EnemyBullet:public BaseObj {
private:

	//クールタイム、撃ったかのフラグ
	const int collTime_ = 5;
	bool isShot_;

	//画像
	GH texture_;

public:

	EnemyBullet();
	~EnemyBullet();
	void Init();
	void Update(float posX,float posY);
	void RenderingPipeline()override;
	void Draw();

};

