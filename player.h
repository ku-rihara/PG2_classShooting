#pragma once

#include"struct.h"

//class
#include"BaseObj.h"
#include"Camela.h"

class Player:public BaseObj{

private:

	bool isDeath_;

public:

	Player();

	void Init();
	void Update(Camela& camela);
    void RenderingPipeline(Camela& camela)override;
	void Draw();

};

