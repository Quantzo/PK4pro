#ifndef PROFILE_HPP
#define PROFILE_HPP
#include <string>
class Profile
{
public:
	Profile();
	~Profile();

private:
	std::string sName;
	int iPoints;
	bool TechTree[4];
};


#endif