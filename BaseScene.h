#pragma once


class BaseScene{
protected:

static bool isChange_;

public:


	virtual void  Init() = 0;
	virtual void  Update(char* keys, char* preKeys) = 0;
	virtual void  Draw() = 0;

	static  bool GetIsChange() { return isChange_; }
	static 	void SetIsChange( bool is) { isChange_ = is; }
};

