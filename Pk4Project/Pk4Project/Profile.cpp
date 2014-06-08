#include "Profile.h"
Profile::Profile()
{
	this->iPoints = 0;
	this->TechTree[0] = true;
	this->TechTree[1] = false;
	this->TechTree[2] = false;
	this->TechTree[3] = false;
}

void Profile::setName(std::string sName)
{
	this->sName = sName;
}
std::string Profile::getName()
{
	return this->sName;
}

void Profile::setPoints(int iPoints)
{
	this->iPoints = iPoints;
}
int Profile::getPoints()
{
	return this->iPoints;
}

void Profile::setTechTree(std::string kilof, std::string superKilof, std::string bomba, std::string dynamit)
{
	if (kilof.compare("true"))
	{
		this->TechTree[0] = true;
	}
	else
	{
		this->TechTree[0] = false;
	}
	if (superKilof.compare("true"))
	{
		this->TechTree[1] = true;
	}
	else
	{
		this->TechTree[1] = false;
	}
	if (bomba.compare("true"))
	{
		this->TechTree[2] = true;
	}
	else
	{
		this->TechTree[2] = false;
	}
	if (dynamit.compare("true"))
	{
		this->TechTree[3] = true;
	}
	else
	{
		this->TechTree[3] = false;
	}
}

Profile::~Profile()
{
}
