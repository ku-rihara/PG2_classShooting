#include<Novice.h>

//Function
#include"Matrix3x3.h"
//class
#include "BaseObj.h"


BaseObj::BaseObj() {
	
	worldPos_ = {};

	//Parameter
	 velocity_ = {};
	 acceleration_ = {};
	 scale_ = {};
	 size_ = {};
	 theta_=0;

	//頂点とマトリックス
	 vertexPos_ = {};
	 screenVertex_ = {};
	 localVertex_ = {};
	 matrix_ = {};
	 wvpVpMatrix_ = {};
};

void BaseObj::RenderingPipeline(Camela& camela) {

	camela.MakeCamelaMatrix();
	matrix_ = MakeAffineMatrix(scale_, theta_, worldPos_);
	wvpVpMatrix_=wvpVpMatrix(matrix_, camela.GetViewMatrix(), camela.GetOrthoMatrix(), camela.GetViewportMatrix());
	screenVertex_ = Transform(localVertex_, wvpVpMatrix_);
}

