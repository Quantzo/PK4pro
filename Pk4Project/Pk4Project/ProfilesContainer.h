#ifndef PROFILES_CONTAINER_HPP
#define PROFILES_CONTAINER_HPP
#include <string>
class ProfilesContainer
{
public:
	ProfilesContainer(std::string Path);
	~ProfilesContainer();
	void Save();
private:
	std::string sPath;

};



#endif