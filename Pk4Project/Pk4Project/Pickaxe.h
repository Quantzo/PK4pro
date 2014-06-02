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


#endif