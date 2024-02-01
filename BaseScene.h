#pragma once


class BaseScene{


public:
	virtual void  Init() = 0;
	virtual void  Update(char* keys, char* preKeys) = 0;
	virtual void  Draw() = 0;
};

