#ifndef PROFILE_HPP
#define PROFILE_HPP
#include <string>
class Profile
{
public:
	Profile();
	void setName(std::string sName);
	std::string getName();
	void setPoints(int iPoints);
	int getPoints();
	void setTechTree(std::string kilof, std::string superKilof, std::string bomba, std::string dynamit);
	bool* getTechTree();
	~Profile();

private:
	std::string sName;
	int iPoints;
	bool TechTree[4];
};


#endif