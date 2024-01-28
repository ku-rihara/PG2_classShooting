#pragma once

#include"struct.h"
//class
#include"Camela.h"

class BaseObj{
public:
	//座標
	Vector2 worldPos_;

	//Parameter
	Vector2 velocity_;
	Vector2 acceleration_;
	Vector2 scale_;
	Vector2 size_;
	float theta_;

	//頂点とマトリックス
	Vertex vertexPos_;
	Vertex screenVertex_;
	Vertex localVertex_;
	Matrix3x3 matrix_;
	Matrix3x3 wvpVpMatrix_;
public:

	//コンストラクタ
	BaseObj();

	virtual void RenderingPipeline(Camela&camela);
	

};

