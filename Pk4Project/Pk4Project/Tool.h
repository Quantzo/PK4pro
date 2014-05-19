#ifndef TOOL_HPP
#define TOOL_HPP
#include "Object.h"
class Tool : public Object
{
public:
	Tool();
	~Tool();
	virtual bool use(Object* oUsedOn);
	void setRange(int iRange);
	int getRange();
	

private:
	int iRange;
};


bool Tool::use(Object* oUsedOn)
{
	return false;
}

void Tool::setRange(int iRange)
{
	this->iRange = iRange;
}

int Tool::getRange()
{
	return this->iRange;
}
Tool::Tool()
{
}

Tool::~Tool()
{
}

#endif