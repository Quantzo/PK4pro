#ifndef OBJECT_HPP
#define OBJECT_HPP
class Object
{
public:
	Object();
	virtual ~Object();
	virtual void draw();
private:

};

Object::Object()
{
}

void Object::draw()
{
}

Object::~Object()
{
}
#endif