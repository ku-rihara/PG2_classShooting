#pragma once

#include"BaseObj.h"


class EnemyBullet:public BaseObj {
private:

	//クールタイム、撃ったかのフラグ
	const int collTime_ = 30;
	bool isShot_;
	bool isShotEnd_;
	Vector2 direction_;

	float playerDistance_;

	//画像
	GH texture_;

public:

	EnemyBullet();
	~EnemyBullet();
	void Init();
	void Update();
	void RenderingPipeline()override;
	void Draw();

	//getter
	Vector2 GetWorldPos()const { return worldPos_; }
	Vector2 GetRadius()const { return radius_; }
	float GetPlayerDistance()const { return playerDistance_; }
	int GetCollTime()const { return collTime_; }
	bool GetIsShotEnd()const { return isShotEnd_; }
	bool GetIsShot()const { return isShot_; }

	//setter
	void SetWorldPosX(float pos) { this->worldPos_.x = pos; }
	void SetWorldPosY(float pos) { this->worldPos_.y = pos; }
	void SetIsShotEnd(bool is) { this->isShotEnd_ = is; }
	void SetIsShot(bool is) { this->isShot_ = is; }
	void SetPlayerDistance(float distance) { this->playerDistance_=distance; }
	void SetDirection(Vector2 direction) { this->direction_ = direction; }
};

