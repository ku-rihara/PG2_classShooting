#pragma once
#include "BaseObj.h"
class RenditionBox : public BaseObj{

private:

	bool isStart_;
	bool isEnd_;
	Easing scaling_;
	const float flameMax_=40;

	GH texture_;

public:

	RenditionBox();
	~RenditionBox();

	void ScalingInit();
	void ScaleUp();
	void ScaleDown();
	void RenderingPipeline()override;
	void Draw();

	//getter
	bool GetIsReturn()const { return scaling_.isReturn; }
	bool GetIsEnd()const { return isEnd_; }
};

