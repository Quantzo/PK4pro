#ifndef XMLFILEEXCEPTION
#define XMLFILEEXCEPTION
#include <exception>
#include <string>
#include <sstream>


class XMLfileException : public std::exception
{
public:
	XMLfileException(std::string path) :exception()
	{
		std::ostringstream oss;
		oss << "Could not locate file" << path << ".";
		this->message = oss.str();
	};
	virtual ~XMLfileException() throw ()
	{
		this->message = "";
	};
	virtual const char* what() const throw()
	{
		return this->message.c_str();
	}

private:
	std::string message;
};
#endif // !XMLFileEXception
