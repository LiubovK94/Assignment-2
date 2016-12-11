#include <iostream>
#include <sstream>
#include <string>
#include "DateTime.h"
#include "BugFix.h"
#include "Meeting.h"
#include "Project.h"
#include "Task.h"
#include "TimeAllocation.h"
#include "WorkDone.h"
#include "tinyxml2.h"

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

void createObjects(std::vector <Project *>); 

int main()
{
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError eResult = xmlDoc.LoadFile("Dat.xml");
	XMLCheckResult(eResult);
	tinyxml2::XMLNode * pRoot = xmlDoc.FirstChild();
	if (pRoot == nullptr) return tinyxml2::XML_ERROR_FILE_READ_ERROR;
	
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


	std::vector<Project *> projects;


	tinyxml2::XMLElement * pElement = pRoot->FirstChildElement("project");

	while (pElement != nullptr)
	{
		pNameProj = pElement->FirstChildElement("name");
		if (pNameProj == nullptr) { const char* projName = "Name of the project does not exist"; }
		const char* projName = pNameProj->GetText();

		pDescProj = pElement->FirstChildElement("description");
		if (pDescProj == nullptr) { const char* projDesc = "Description of the project does not exist"; }
		const char* projDesc = pDescProj->GetText();

		pStartProj = pElement->FirstChildElement("start");
		if (pStartProj == nullptr)  { const char* projStart = "Start date of the project does not exist"; }
		const char* projStart = pStartProj->GetText();

		pDeadlineProj = pElement->FirstChildElement("deadline");
		if (pDeadlineProj == nullptr) { const char* projDeadline = "Deadline of the project does not exist"; }
		const char* projDeadline = pDeadlineProj->GetText();

		Project * pr = new Project(projName, projDesc, projStart, projDeadline);
		projects.push_back(pr);

		pTask = pElement->FirstChildElement("task");
		while (pTask != nullptr){
			pTaskName = pTask->FirstChildElement("taskName");
			if (pTaskName == nullptr) { const char* taskName = "Name of the task does not exist"; }
			const char* taskName = pTaskName->GetText();

			pTaskDesc = pTask->FirstChildElement("taskDescription");
			if (pTaskDesc == nullptr) { const char* taskDesc = "Desc of the task does not exist"; }
			const char* taskDesc = pTaskDesc->GetText();

			pTaskStart = pTask->FirstChildElement("taskStart");
			if (pTaskStart == nullptr) { const char* taskStart = "Start of the task does not exist"; }
			const char* taskStart = pTaskStart->GetText();

			pTaskDeadline = pTask->FirstChildElement("taskDeadline");
			if (pTaskDeadline == nullptr) { const char* taskEnd = "End of the task does not exist"; }
			const char* taskEnd = pTaskDeadline->GetText();

			Task * tsk = new Task(taskName, taskDesc, taskStart, taskEnd);
			pr->addTask(tsk);

			pTimeAlloc = pTask->FirstChildElement("timealloc");

			while(pTimeAlloc != nullptr){

				pType = pTimeAlloc->FirstChildElement("type");

				if (pType == nullptr) { const char* type = "no type specified"; }
				const char* type = pType->GetText();

				if (type == (std::string("Work Done")))
				{

					pTAStart = pTimeAlloc->FirstChildElement("tstart");
					if (pTAStart == nullptr) { const char* taStart = "no taStrat"; }
					const char* taStart = pTAStart->GetText();


					pTAEnd = pTimeAlloc->FirstChildElement("tend");
					if (pTAEnd == nullptr) { const char* taEnd = "no taend"; }
					const char* taEnd = pTAEnd->GetText();

					pTADescription = pTimeAlloc->FirstChildElement("tdescription");
					if (pTADescription == nullptr) { const char* taDesc = "no tadescription"; }
					const char* taDesc = pTADescription->GetText();

					tsk->addTA(std::move(std::unique_ptr<TimeAllocation>(new WorkDone(taStart, taEnd, taDesc))));
				}

				else if (type == (std::string("Bug Fix")))
				{
					pTAStart = pTimeAlloc->FirstChildElement("tstart");
					if (pTAStart == nullptr) { const char* taStart = "no taStrat"; }
					const char* taStart = pTAStart->GetText();


					pTAEnd = pTimeAlloc->FirstChildElement("tend");
					if (pTAEnd == nullptr) { const char* taEnd = "no taend"; }
					const char* taEnd = pTAEnd->GetText();

					pTADescription = pTimeAlloc->FirstChildElement("tdescription");
					if (pTADescription == nullptr) { const char* taDesc = "no tadescription"; }
					const char* taDesc = pTADescription->GetText();

					pTAId = pTimeAlloc->FirstChildElement("id");
					if (pTAId == nullptr) { const char* taId = "no id"; }
					const char* taId = pTAId->GetText();

					tsk->addTA(std::move(std::unique_ptr<TimeAllocation>(new BugFix(taStart, taEnd, taDesc, taId))));
				}

				else if (type == (std::string("Meeting")))
				{
					pTAStart = pTimeAlloc->FirstChildElement("tstart");
					if (pTAStart == nullptr) { const char* taStart = "no taStrat"; }
					const char* taStart = pTAStart->GetText();


					pTAEnd = pTimeAlloc->FirstChildElement("tend");
					if (pTAEnd == nullptr) { const char* taEnd = "no taend"; }
					const char* taEnd = pTAEnd->GetText();

					pTADescription = pTimeAlloc->FirstChildElement("tdescription");
					if (pTADescription == nullptr) { const char* taDesc = "no tadescription"; }
					const char* taDesc = pTADescription->GetText();

					std::unique_ptr<Meeting> m(new Meeting(taStart, taEnd, taDesc));

					pTAAttendee = pTimeAlloc->FirstChildElement("attendee");
					while (pTAAttendee != nullptr)
					{
						const char* taAt = pTAAttendee->GetText();
						m->addAttendee(taAt);
						pTAAttendee = pTAAttendee->NextSiblingElement("attendee");
					}

					tsk->addTA(std::move(m));
				}
				pTimeAlloc = pTimeAlloc->NextSiblingElement("timealloc");
			}

			pTask = pTask->NextSiblingElement("task");
		}


	 pElement = pElement->NextSiblingElement("project");

	}



	for (auto it = projects.begin(); it != projects.end(); ++it)
	{
		(*it)->show();
	}




	std::cin.get();

}

void createObjects(std::vector <Project *> v)
{


}