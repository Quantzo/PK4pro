#ifndef PROFILE_HPP
#define PROFILE_HPP
#include <string>
class Profile
{
public:
	Profile();
	void setName(std::string sName);
	void setPoints(int iPoints);
	void setTechTree(std::string kilof, std::string superKilof, std::string bomba, std::string dynamit);
	~Profile();

private:
	std::string sName;
	int iPoints;
	bool TechTree[4];
};


#endif