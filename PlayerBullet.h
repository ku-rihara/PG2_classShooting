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
	
	int GetCollTime()const { return collTime_; }
	bool GetIsShot()const { return isShot_; }

	//setter
	
	void SetIsShot(bool is) { this->isShot_ = is; }
};


