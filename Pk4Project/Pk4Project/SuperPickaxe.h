#ifndef SUPERPICKAXE_HPP
#define SUPERPICKAXE_HPP
#include "Tool.h"
#include "Granite.h"
#include "Clay.h"
class SuperPickaxe : public Tool
{
public:
	SuperPickaxe(){};
	~SuperPickaxe(){};
	bool use(Object* oUsedOn);
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);
private:
};



#endif