
//class
#include "BaseObj.h"


BaseObj::BaseObj() {

	Init();
	camela_ = new Camela;
};

BaseObj::~BaseObj() {

}

void BaseObj::Init() {
	//頂点とマトリックス
	screenVertex_ = {};
	matrix_ = {};
	wvpVpMatrix_ = {};
	acceleration_ = {};
	theta_ = 0;
}

//レンダリングパイプライン
void BaseObj::RenderingPipeline() {

	camela_->MakeCamelaMatrix();
	matrix_ = MakeAffineMatrix(scale_, theta_, worldPos_);
	wvpVpMatrix_ = wvpVpMatrix(matrix_, camela_->GetViewMatrix(), camela_->GetOrthoMatrix(), camela_->GetViewportMatrix());
	screenVertex_ = Transform(localVertex_, wvpVpMatrix_);
}

