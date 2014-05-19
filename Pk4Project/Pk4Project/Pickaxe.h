#ifndef PICKAXE_HPP
#define PICKAXE_HPP
#include "Tool.h"
#include "Clay.h"
class Pickaxe : public Tool 
{
public:
	Pickaxe();
	~Pickaxe();
	bool use(Object* oUsedOn);
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);
private:

};

Pickaxe::Pickaxe()
{
}
bool Pickaxe::use(Object* oUsedOn)
{
	if (dynamic_cast<Clay*>(oUsedOn))
	{
		//animation
		return true;
	}
	return false;
}

void Pickaxe::draw(int iXpos, int iYpos, sf::RenderWindow &window)
{

}

Pickaxe::~Pickaxe()
{
}
#endif