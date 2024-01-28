﻿#pragma once
#include<Novice.h>

#include"struct.h"

//Function
#include"Matrix3x3.h"
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
	float theta_;

	//頂点とマトリックス
	Vertex screenVertex_;
	Vertex localVertex_;
	Matrix3x3 matrix_;
	Matrix3x3 wvpVpMatrix_;
public:

	//コンストラクタ
	BaseObj();

	virtual void Init();
	virtual void RenderingPipeline();
	
	Vector2 GetWorldPos()const { return worldPos_; }


};

