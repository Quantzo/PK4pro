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


#endif