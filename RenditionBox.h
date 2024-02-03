#pragma once
#include "BaseObj.h"
class RenditionBox : public BaseObj{

private:

	bool isScaleUpStart_;
	bool isScaleDownStart_;
	bool isScaleUpEnd_;
	bool isScaleDownEnd_;
	Easing scaling_;
	const float flameMax_=40;

	GH texture_;

public:

	RenditionBox();
	~RenditionBox();

	void ScalingInit();
	void ScaleUpInit();
	void ScaleDownInit();
	void ScaleUp();
	void ScaleDown();
	void RenderingPipeline()override;
	void Draw();

	//getter
	bool GetIsScaleUpEnd()const { return isScaleUpEnd_; }
	bool GetIsSaleDownEnd()const { return isScaleDownEnd_; }
};

