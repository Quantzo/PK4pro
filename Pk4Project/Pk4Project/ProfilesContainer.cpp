#include "ProfilesContainer.h"
#include "rapidxml.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "XMLfileException.h"
#include "rapidxml_print.hpp"


ProfilesContainer::ProfilesContainer()
{
}


void ProfilesContainer::Load(std::string Path)
{
	std::string input_xml;
	std::string line;
	

	
	this->sPath = Path;
	try
	{
		std::ifstream XMLfile(Path);
		while (getline(XMLfile, line))
			input_xml += line;

	}
	catch (XMLfileException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::vector<char> xml_copy(input_xml.begin(), input_xml.end());
	xml_copy.push_back('\0');
	this->XMLcopy = xml_copy;
	int count;

	rapidxml::xml_document<> xmlDoc;
	try
	{
		xmlDoc.parse<0>(&this->XMLcopy[0]);
	}
	catch (rapidxml::parse_error &e) 
	{
		std::cerr << e.what() << std::endl;
	}
	rapidxml::xml_node<> * root = xmlDoc.first_node();
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

void ProfilesContainer::Save()
{
	char buffer[255];
	char buffer2[255];
	rapidxml::xml_document<> xmlDoc;
	rapidxml::xml_node<>* decl = xmlDoc.allocate_node(rapidxml::node_declaration);
	decl->append_attribute(xmlDoc.allocate_attribute("version", "1.0"));
	xmlDoc.append_node(decl);

	rapidxml::xml_node<>* root = xmlDoc.allocate_node(rapidxml::node_element, "Tree");
	root->append_attribute(xmlDoc.allocate_attribute("path", this->sPath.c_str()));
	xmlDoc.append_node(root);
	
	rapidxml::xml_node<>* child = xmlDoc.allocate_node(rapidxml::node_element, "Profiles");
	_itoa(this->pProfiles.size(), buffer2,10);

	child->append_attribute(xmlDoc.allocate_attribute("count", buffer2));
	
	for (int i = 0; i < this->pProfiles.size();i++)
	{
		rapidxml::xml_node<>* Profile = xmlDoc.allocate_node(rapidxml::node_element, "Profile");
		rapidxml::xml_node<>* Name = xmlDoc.allocate_node(rapidxml::node_element, "Name");
		char* name = xmlDoc.allocate_string(this->pProfiles[i].getName().c_str());
		Name->value(name);
		rapidxml::xml_node<>* Techtree = xmlDoc.allocate_node(rapidxml::node_element, "Techtree");
		if (this->pProfiles[i].getTechTree()[0])
		{
			Techtree->append_attribute(xmlDoc.allocate_attribute("kilof", "true"));
		}
		else
		{
			Techtree->append_attribute(xmlDoc.allocate_attribute("kilof", "false"));
		}
		
		if (this->pProfiles[i].getTechTree()[1])
		{
			Techtree->append_attribute(xmlDoc.allocate_attribute("superkilof", "true"));
		}
		else
		{
			Techtree->append_attribute(xmlDoc.allocate_attribute("superkilof", "false"));
		}
		if (this->pProfiles[i].getTechTree()[2])
		{
			Techtree->append_attribute(xmlDoc.allocate_attribute("bomba", "true"));
		}
		else
		{
			Techtree->append_attribute(xmlDoc.allocate_attribute("bomba", "false"));
		}
		if (this->pProfiles[i].getTechTree()[3])
		{
			Techtree->append_attribute(xmlDoc.allocate_attribute("dynamit", "true"));
		}
		else
		{
			Techtree->append_attribute(xmlDoc.allocate_attribute("dynamit", "false"));
		}
		rapidxml::xml_node<>* Points = xmlDoc.allocate_node(rapidxml::node_element, "Points");
		_itoa(this->pProfiles[i].getPoints(), buffer, 10);
		char* points = xmlDoc.allocate_string(buffer);
		Points->value(points);
		Profile->append_node(Name);
		Profile->append_node(Techtree);
		Profile->append_node(Points);
		child->append_node(Profile);
	}
	root->append_node(child);
	std::ofstream file_stored("save.xml");
	file_stored << xmlDoc;
	file_stored.close();
	xmlDoc.clear();
}

int ProfilesContainer::getSize()
{
	return this->pProfiles.size();
}
Profile* ProfilesContainer::getProfile(int iNumber)
{
	return &(this->pProfiles[iNumber]);
}
void ProfilesContainer::removeProfile(int iNumber)
{
	this->pProfiles.erase(this->pProfiles.begin()+iNumber);
}
void ProfilesContainer::addProfile(Profile pProfile)
{
	this->pProfiles.push_back(pProfile);
}

ProfilesContainer::~ProfilesContainer()
{
}
