//Master branch test

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "DateTime.h"
#include "BugFix.h"
#include "Meeting.h"
#include "Project.h"
#include "Extra.h"
#include "Task.h"
#include "TimeAllocation.h"
#include "WorkDone.h"
#include "tinyxml2.h"
#include <cstdlib>

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) { std::cout<<"This file does not exist!"<<std::endl; std::cout<<"Press any key"<<std::endl; std::cin.get(); }
#endif

void createObjects(tinyxml2::XMLDocument &, std::vector <Project *> &);
void menu(std::vector<Project *>&);
void loadNewFile(std::vector<Project *>&);
void loadAsc(std::vector<Project *> &);
void loadDesc(std::vector<Project *> &);

int main(/*int argc, char **argv*/) //command line input
{
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError eResult = xmlDoc.LoadFile("Data.xml");
	XMLCheckResult(eResult);
	//tinyxml2::XMLError eResult = xmlDoc.LoadFile(argv[1]); //command line input
	//XMLCheckResult(eResult);

	std::vector<Project *> projects;
	createObjects(xmlDoc, projects);

	for (auto it : projects)
	{
		std::cout << (*it);
	}


	menu(projects);


	std::cin.get();

}

void createObjects(tinyxml2::XMLDocument &xmlDoc, std::vector <Project *> &projects) //load data from xml file
{

	tinyxml2::XMLElement * pNameProj;
	tinyxml2::XMLElement * pDescProj;
	tinyxml2::XMLElement * pStartProj;
	tinyxml2::XMLElement * pDeadlineProj;
	tinyxml2::XMLElement * pTask;
	tinyxml2::XMLElement * pTaskName;
	tinyxml2::XMLElement * pTaskDesc;
	tinyxml2::XMLElement * pTaskStart;
	tinyxml2::XMLElement * pTaskDeadline;
	tinyxml2::XMLElement * pTimeAlloc;
	tinyxml2::XMLElement * pType;
	tinyxml2::XMLElement * pTAStart;
	tinyxml2::XMLElement * pTAEnd;
	tinyxml2::XMLElement * pTADescription;
	tinyxml2::XMLElement * pTAId;
	tinyxml2::XMLElement * pTAAttendee;

	std::string projName; std::string projDesc; std::string projStart; std::string projDeadline;
	std::string taskName; std::string taskDesc; std::string taskStart; std::string taskEnd;
	std::string type; std::string taStart; std::string taEnd; std::string taDesc; std::string taId; std::string taAt;

	tinyxml2::XMLNode * pRoot = xmlDoc.FirstChild();

	if (pRoot != nullptr) {
		tinyxml2::XMLElement * pElement = pRoot->FirstChildElement("project");

		while (pElement != nullptr)
		{

			pNameProj = pElement->FirstChildElement("name");
			if (pNameProj == nullptr) { projName = "Name of this project was not specified"; }
			else { projName = pNameProj->GetText(); }

			pDescProj = pElement->FirstChildElement("description");
			if (pDescProj == nullptr) { projDesc = "Description of this project was not specified"; }
			{projDesc = pDescProj->GetText(); }

			pStartProj = pElement->FirstChildElement("start");
			if (pStartProj == nullptr)  { projStart = "00/00/00 00:00"; }
			{ projStart = pStartProj->GetText(); }

			pDeadlineProj = pElement->FirstChildElement("deadline");
			if (pDeadlineProj == nullptr) { projDeadline = "00/00/00 00:00"; }
			{ projDeadline = pDeadlineProj->GetText(); }

			Project * pr = new Project(projName, projDesc, projStart, projDeadline);
			projects.push_back(pr);

			pTask = pElement->FirstChildElement("task");
			while (pTask != nullptr){
				pTaskName = pTask->FirstChildElement("taskName");
				if (pTaskName == nullptr) { taskName = "Name of this task was not specified"; }
				{ taskName = pTaskName->GetText(); }

				pTaskDesc = pTask->FirstChildElement("taskDescription");
				if (pTaskDesc == nullptr) { taskDesc = "Desc of this task was not specified"; }
				{ taskDesc = pTaskDesc->GetText(); }

				pTaskStart = pTask->FirstChildElement("taskStart");
				if (pTaskStart == nullptr) { taskStart = "00/00/00 00:00"; }
				{ taskStart = pTaskStart->GetText(); }

				pTaskDeadline = pTask->FirstChildElement("taskDeadline");
				if (pTaskDeadline == nullptr) { taskEnd = "00/00/00 00:00"; }
				{ taskEnd = pTaskDeadline->GetText(); }

				Task * tsk = new Task(taskName, taskDesc, taskStart, taskEnd);
				pr->addTask(tsk);

				pTimeAlloc = pTask->FirstChildElement("timealloc");

				while (pTimeAlloc != nullptr){

					pType = pTimeAlloc->FirstChildElement("type");

					if (pType != nullptr) {

						type = pType->GetText();

						if (type == (std::string("Work Done")))
						{

							pTAStart = pTimeAlloc->FirstChildElement("tstart");
							if (pTAStart == nullptr) { taStart = "00/00/00 00:00"; }
							else{ taStart = pTAStart->GetText(); }


							pTAEnd = pTimeAlloc->FirstChildElement("tend");
							if (pTAEnd == nullptr) { taEnd = "00/00/00 00:00"; }
							else{ taEnd = pTAEnd->GetText(); }

							pTADescription = pTimeAlloc->FirstChildElement("tdescription");
							if (pTADescription == nullptr) { taDesc = "Description of this task was not specified"; }
							else{ taDesc = pTADescription->GetText(); }

							tsk->addTA(std::move(std::unique_ptr<TimeAllocation>(new WorkDone(taStart, taEnd, taDesc))));
						}

						else if (type == (std::string("Bug Fix")))
						{
							pTAStart = pTimeAlloc->FirstChildElement("tstart");
							if (pTAStart == nullptr) { taStart = "00/00/00 00:00"; }
							else{ taStart = pTAStart->GetText(); }


							pTAEnd = pTimeAlloc->FirstChildElement("tend");
							if (pTAEnd == nullptr) { taEnd = "00/00/00 00:00"; }
							else{ taEnd = pTAEnd->GetText(); }

							pTADescription = pTimeAlloc->FirstChildElement("tdescription");
							if (pTADescription == nullptr) { taDesc = "Description of this task was not specified"; }
							else{ taDesc = pTADescription->GetText(); }

							pTAId = pTimeAlloc->FirstChildElement("id");
							if (pTAId == nullptr) { taId = "Bug ID of this task was not specified"; }
							else{ taId = pTAId->GetText(); }

							tsk->addTA(std::move(std::unique_ptr<TimeAllocation>(new BugFix(taStart, taEnd, taDesc, taId))));
						}

						else if (type == (std::string("Meeting")))
						{
							pTAStart = pTimeAlloc->FirstChildElement("tstart");
							if (pTAStart == nullptr) { taStart = "00/00/00 00:00"; }
							else{ taStart = pTAStart->GetText(); }


							pTAEnd = pTimeAlloc->FirstChildElement("tend");
							if (pTAEnd == nullptr) { taEnd = "00/00/00 00:00"; }
							else{ taEnd = pTAEnd->GetText(); }

							pTADescription = pTimeAlloc->FirstChildElement("tdescription");
							if (pTADescription == nullptr) { taDesc = "Description of this task was not specified"; }
							else{ taDesc = pTADescription->GetText(); }

							std::unique_ptr<Meeting> m(new Meeting(taStart, taEnd, taDesc));

							pTAAttendee = pTimeAlloc->FirstChildElement("attendee");
							while (pTAAttendee != nullptr)
							{
								taAt = pTAAttendee->GetText();
								m->addAttendee(taAt);
								pTAAttendee = pTAAttendee->NextSiblingElement("attendee");
							}

							tsk->addTA(std::move(m));
						}
						else if (type == (std::string("Extra Feature")))
						{
							pTAStart = pTimeAlloc->FirstChildElement("tstart");
							if (pTAStart == nullptr) { taStart = "00/00/00 00:00"; }
							else{ taStart = pTAStart->GetText(); }


							pTAEnd = pTimeAlloc->FirstChildElement("tend");
							if (pTAEnd == nullptr) { taEnd = "00/00/00 00:00"; }
							else{ taEnd = pTAEnd->GetText(); }

							pTADescription = pTimeAlloc->FirstChildElement("tdescription");
							if (pTADescription == nullptr) { taDesc = "Description of this task was not specified"; }
							else{ taDesc = pTADescription->GetText(); }

							std::unique_ptr<Extra> m(new Extra(taStart, taEnd, taDesc));

							pTAAttendee = pTimeAlloc->FirstChildElement("programmer");
							while (pTAAttendee != nullptr)
							{
								taAt = pTAAttendee->GetText();
								m->addProgrammer(taAt);
								pTAAttendee = pTAAttendee->NextSiblingElement("programmer");
							}

							tsk->addTA(std::move(m));
						}
						pTimeAlloc = pTimeAlloc->NextSiblingElement("timealloc");
					}
				}

				pTask = pTask->NextSiblingElement("task");
			}


			pElement = pElement->NextSiblingElement("project");

		}
	}
}

void menu(std::vector<Project *> &p) // function for loading menu
{
	char opt; 

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "  Menu:" << std::endl;
	std::cout << "  - Enter '1' if you want to load different file" << std::endl;
	std::cout << "  - Enter '2' if you want to view Time Allocations in ascending order" << std::endl;
	std::cout << "  - Enter '3' if you want to view Time Allocations in descsending order" << std::endl;
	std::cout << "  - Enter '4' if you want to exit" << std::endl;
	std::cin >> opt;

	switch (opt)
	{
	case '1': loadNewFile(p); break;
	case '2': loadAsc(p); break;
	case '3': loadDesc(p); break;
	case '4': exit(0); break;
	default: {std::cout << "Please choose one of the existing options" << std::endl; menu(p); };
	}

}

void loadNewFile(std::vector<Project *> &p) //load file at runtime
{
	p.clear();

	std::string s;
	std::cout << "   Please enter filename: ";
	std::cin >> s;
	const char * str = s.c_str();

	tinyxml2::XMLDocument xmlDoc_;
	tinyxml2::XMLError eResult = xmlDoc_.LoadFile(str);
	XMLCheckResult(eResult);

	
	createObjects(xmlDoc_, p);

	for (auto it : p)
	{
		std::cout << (*it);
	}


	menu(p);


}

void loadAsc(std::vector<Project *> &p) // load file with time allocations in ascending order
{
	for (auto it : p)
	{
		(*it).loadAsc();
	}

	menu(p);
}
void loadDesc(std::vector<Project *> &p) // load file with time allocations in descending order
{
	for (auto it : p)
	{
		(*it).loadDesc();
	}

	menu(p);
}