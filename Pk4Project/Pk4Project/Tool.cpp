#include "Tool.h"
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
