#pragma once
#include<Novice.h>
#define _USE_MATH_DEFINES
#include"math.h"


#include"struct.h"

//Function
#include"Matrix3x3.h"
#include"Easing.h"
#include"Function.h"

//class
#include"Camela.h"

class BaseObj{
protected:

	//包含
	Camela* camela_;
	//座標
	Vector2 worldPos_;

	//Parameter
	Vector2 velocity_;
	Vector2 acceleration_;
	Vector2 scale_;
	Vector2 size_;
	Vector2 radius_;
	float theta_;

	//頂点とマトリックス
	Vertex screenVertex_;
	Vertex localVertex_;
	Matrix3x3 matrix_;
	Matrix3x3 wvpVpMatrix_;

public:

	BaseObj();//コンストラクタ
	~BaseObj();//デストラクタ

	virtual void Init();
	virtual void RenderingPipeline();
	
	Vector2 GetWorldPos()const { return worldPos_; }
	Vector2 GetRadius()const { return radius_; }

};

