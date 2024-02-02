#pragma once


#include "BaseObj.h"
#include"EnemyBullet.h"

const int EnemyBulletMax = 10;

class Enemy : public BaseObj{
private:

	//包含
	EnemyBullet* bullet_[EnemyBulletMax];

	//アタックモード
	enum AttackMode {
		SHOT,
		ASSAULT,
	};

	//座標
	Vector2 startPos_;
	Vector2 savePos_;
	Vector2 assaultPos_;

	//スポーン
	bool isSponeEnd_;
	Easing spone_;
	const float sponeMaxFrame_ = 30.0f;

	//突進
	AttackMode attackMode_;
	Easing assault_;
	bool isAttackModeChange_;
	const float assaultMaxFlame_ = 30.0f;
	int assaultCount_;

	//弾
	int shotCurrentCollTime_;

	//死亡フラグ、体力
	bool isDeath_;
	int Hp_;
	int life_;
	
	//画像
	GH texture_;

public:
	bool isDamage_;

	Enemy(float posX,float posY);
	~Enemy();

	void Init(float posX, float posY);
	void Spone();
	void Update(Vector2 pos);
	void Shot(Vector2 pos);
	void Assault(Vector2 pos);
	void Draw();
	void RenderingPipeline()override;

	//setter
	void SetIsDeath(bool is) { this->isDeath_=is; }

	//getter
	bool GetIsDeath()const { return isDeath_; }
	bool GetIsSponeEnd()const { return isSponeEnd_; }

};

