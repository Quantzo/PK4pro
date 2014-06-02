#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Bomb.h"
#include "Object.h"
#include "Tool.h"
#include "Pickaxe.h"

class Player : public Object
{
public:
	Player();
	~Player();
	void changeDirection(int iDirIndex);
	void draw(int iXpos, int iYpos, sf::RenderWindow &window);
	void setToolIndex(int iToolIndex);
	int	getToolIndex();
	bool useTool(Object* oUsedOn);

private:
	bool bRight;
	bool bLeft;
	bool bUp;
	bool bDown;
	Tool* tCurrentTool;
	int iCurrentToolIndex;

};
#endif