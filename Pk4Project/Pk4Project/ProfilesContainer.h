#ifndef PROFILES_CONTAINER_HPP
#define PROFILES_CONTAINER_HPP
#include <string>
#include <vector>
#include "Profile.h"
class ProfilesContainer
{
public:
	ProfilesContainer();
	~ProfilesContainer();
	void Save();
	void Load(std::string Path);
	Profile* getProfile(int iNumber);
	void removeProfile(int iNumber);
	void addProfile(Profile pProfile);
	int getSize();
private:
	std::string sPath;
	std::vector<char> XMLcopy;
	std::vector<Profile> pProfiles;

};



#endif