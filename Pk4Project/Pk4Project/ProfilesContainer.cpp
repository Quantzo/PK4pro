#include "ProfilesContainer.h"
#include "rapidxml.hpp"
#include <iostream>
#include <fstream>
#include <vector>



ProfilesContainer::ProfilesContainer(std::string Path)
{
	std::string input_xml;
	std::string line;
	std::ifstream XMLfile(Path);
	
	this->sPath = Path;

	while (getline(XMLfile, line))
			input_xml += line;
	
	std::vector<char> xml_copy(input_xml.begin(), input_xml.end());
	xml_copy.push_back('\0');
	this->XMLcopy = xml_copy;


}


void ProfilesContainer::Load()
{
	int count=4;

	rapidxml::xml_document<> xmlDoc;
	try
	{
		xmlDoc.parse<0>(&this->XMLcopy[0]);
	}
	catch (rapidxml::parse_error p) 
	{
		p.what();
	}
	rapidxml::xml_node<> * root = xmlDoc.first_node();
	std::cout << root->first_attribute()->value(); //path to file


	root = xmlDoc.first_node()->first_node();
	count = std::stoi(root->first_attribute()->value()); //profiles count


	root = xmlDoc.first_node()->first_node()->first_node();
	for (int i = 0; i < count; i++)
	{
		Profile tmp;
		tmp.setName(root->first_node()->value());
		tmp.setTechTree(root->first_node()->next_sibling()->first_attribute()->value(), root->first_node()->next_sibling()->first_attribute()->next_attribute()->value(), root->first_node()->next_sibling()->first_attribute()->next_attribute()->next_attribute()->value(), root->first_node()->next_sibling()->first_attribute()->next_attribute()->next_attribute()->next_attribute()->value());
		tmp.setPoints(std::stoi(root->first_node()->next_sibling()->next_sibling()->value()));
		this->pProfiles.push_back(tmp);
		root = root->next_sibling();
	}
	
}



ProfilesContainer::~ProfilesContainer()
{
}
