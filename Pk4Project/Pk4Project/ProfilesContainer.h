#ifndef PROFILES_CONTAINER_HPP
#define PROFILES_CONTAINER_HPP
#include <string>
#include <vector>
#include "Profile.h"
class ProfilesContainer
{
public:
	ProfilesContainer(std::string Path);
	~ProfilesContainer();
	void Save();
	void Load();
private:
	std::string sPath;
	std::vector<char> XMLcopy;
	std::vector<Profile> pProfiles;

};



#endif