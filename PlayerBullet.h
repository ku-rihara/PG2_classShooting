#pragma once

#include"struct.h"

//class
#include"BaseObj.h"

const int bulletMax = 30;

class PlayerBullet:public BaseObj {
private:

	//クールタイム、撃ったかのフラグ
	const int collTime_=5;
	bool isShot_;
	
	//画像
	GH texture_;
	
public:

	//コンストラクタ、デストラクタ
	PlayerBullet();
	~PlayerBullet();

	//Function
	void Init()override;
	void Update();
	void Draw();
	void RenderingPipeline()override;



	//getter
	Vector2 GetWorldPos()const { return worldPos_; }
	Vector2 GetRadius()const { return radius_; }
	int GetCollTime()const { return collTime_; }
	bool GetIsShot()const { return isShot_; }

	//setter
	void SetWorldPosX(float pos) { this->worldPos_.x = pos; }
	void SetWorldPosY(float pos) { this->worldPos_.y = pos; }
	void SetIsShot(bool is) { this->isShot_ = is; }
};


