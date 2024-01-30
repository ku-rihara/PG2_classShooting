#pragma once
#include "BaseObj.h"
class RenditionBox : public BaseObj{

private:

	bool isStart_;
	float easingTime_;
	const float flameMax_=60;

public:

	RenditionBox();
	~RenditionBox();

	void ScalingInit();
	void ScalingUpdate();
	void RenderingPipeline()override;
	void Draw();

	GH texture_;

};

