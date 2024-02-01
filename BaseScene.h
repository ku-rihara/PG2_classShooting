#pragma once


class BaseScene{
protected:

static bool isChange_;


public:
	virtual void  Init() = 0;
	virtual void  Update(char* keys, char* preKeys) = 0;
	virtual void  Draw() = 0;

	bool GetIsChange()const { return isChange_; }
};

