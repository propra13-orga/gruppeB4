#include "CollisibalObjectManager.h"
#include "LevelEditor.h"


void S_CollisibalObjectManager::set_Object(OBJECTTYPE CURRENTOBJECT,int x, int y)
{
	if (CURRENTOBJECT == Block100x100)
	{
		this->Blocklist.push_back(C_Block(x,y));
	}

}

void S_CollisibalObjectManager::show_Insertions()
{
	for(list<C_Block>::iterator myIter = this->Blocklist.begin();myIter != this->Blocklist.end();++myIter)
	{
		cout << "ein Objekt" << endl;
	}
}

void S_CollisibalObjectManager::render()
{
	for(list<C_Block>::iterator myIter = this->Blocklist.begin();myIter != this->Blocklist.end();++myIter)
	{
		myIter->render();
	}
}

void S_CollisibalObjectManager::forced_pushIntoBlockList()
{
	if(Workinglist.size() != 0)
	{
		Blocklist.push_back(C_Block(Workinglist.front().get_Position()->x,Workinglist.front().get_Position()->y));
		Workinglist.empty();
	}
	else
	{
		return;
	}
}

C_Block * S_CollisibalObjectManager::get_WorkingListsFirstMember()
{
	if(Workinglist.size() != 0)
	{
		return &Workinglist.front();
	}
	else
	{
		return NULL;
	}
}

void S_CollisibalObjectManager::find(int x, int y)
{
	if(this->Workinglist.size() == 0)
	{
		for(list<C_Block>::iterator myIter = Blocklist.begin();myIter != this->Blocklist.end();++myIter)
		{
			if(myIter->get_Position()->x <= x && myIter->get_Position()->x + 100 >= x && myIter->get_Position()->y <= y && myIter->get_Position()->y + 100 >= y)
			{
				Workinglist.push_back(C_Block(myIter->get_Position()->x,myIter->get_Position()->y));
				S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(myIter->get_Position()->x,myIter->get_Position()->y);
				Blocklist.erase(myIter);
				break;
			}
		}

	}
	else if(Workinglist.size() == 1)
	{
		for(list<C_Block>::iterator myIter = Blocklist.begin();myIter != this->Blocklist.end();++myIter)
		{
			if(myIter->get_Position()->x <= x && myIter->get_Position()->x + 100 >= x && myIter->get_Position()->y <= y && myIter->get_Position()->y + 100 >= y)
			{
				Workinglist.push_back(C_Block(myIter->get_Position()->x,myIter->get_Position()->y));
				Blocklist.push_back(C_Block(Workinglist.front().get_Position()->x,Workinglist.front().get_Position()->y));
				Workinglist.pop_front();
				S_LevelEditor::get_LevelEditor().get_MainEditorSource()->set_Position(myIter->get_Position()->x,myIter->get_Position()->y);
				Blocklist.erase(myIter);
				break;
			}
		}
	}

}