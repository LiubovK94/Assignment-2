#include <iostream>
#include <sstream>
#include <string>
#include "tinyxml2.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

int main()
{
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError eResult = xmlDoc.LoadFile("Data.xml");
    XMLCheckResult(eResult);
	tinyxml2::XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr) return tinyxml2::XML_ERROR_FILE_READ_ERROR;

	tinyxml2::XMLElement * pElement = pRoot->FirstChildElement("project");
	if (pElement == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	tinyxml2::XMLElement * pNameProj = pElement->FirstChildElement("name");
	if (pNameProj == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	tinyxml2::XMLElement * pDescProj = pElement->FirstChildElement("description");
	if (pDescProj == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	tinyxml2::XMLElement * pStartProj = pElement->FirstChildElement("start");
	if (pStartProj == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;

	tinyxml2::XMLElement * pDeadlineProj = pElement->FirstChildElement("deadline");
	if (pDeadlineProj == nullptr) return tinyxml2::XML_ERROR_PARSING_ELEMENT;
	
	const char* projName = pNameProj->GetText();
	const char* projDesc = pDescProj->GetText();
	const char* projStart = pStartProj->GetText();
	const char* projDeadline = pDeadlineProj->GetText();

	std::cout << projName << std::endl;
	std::cout << projDesc << std::endl;
	std::cout << projStart << std::endl;
	std::cout << projDeadline << std::endl;

	std::cin.get();


	
	
}