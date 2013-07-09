#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

struct Vector2d
{
	int x;
	int y;
	Vector2d(int x, int y){this->x = x; this->y = y;}
	Vector2d(){}
};

class Object
{
private:
	Vector2d * Position;

public:
	Object(int x, int y){Position = new Vector2d(x,y);}
	~Object(){delete Position;}
	Object(const Object & o){Position = new Vector2d;Position->x = o.Position->x;Position->y = o.Position->y;}
	Object & operator=(const Object & that){Position->x = that.Position->x;Position->y = that.Position->y; }
	void set_Position(int x, int y){Position->x = x;Position->y = y;}
	const Vector2d *  get_Position(){return Position;}
};

void save_ListMembersInOutputFile(list<Object> & tempList);
void load_ListMembersFromOutputFile(list<Object> & tempList);
void showListInsertions(list<Object> & tempList);
void put_int(list<Object> & tempList);


int main(int argc, char ** argv)
{
	list<Object> ObjectList;

	load_ListMembersFromOutputFile(ObjectList);
	//load_ListMembersFromOutputFile(&ObjectList);
	showListInsertions(ObjectList);
	save_ListMembersInOutputFile(ObjectList);

	system("PAUSE");

	return 0;
}

void save_ListMembersInOutputFile(list<Object> & tempList)
{
	try
	{
	ofstream DATAFILE;

	DATAFILE.open("ListMembers.save",ios::out);

	int temporaryVariable;

	for(list<Object>::iterator myIter = tempList.begin();myIter != tempList.end();++myIter)
	{
		temporaryVariable = myIter->get_Position()->x;
		DATAFILE << temporaryVariable << "\n";
		temporaryVariable = myIter->get_Position()->y;
		DATAFILE << temporaryVariable << "\n";
	}

	DATAFILE.close();
	}
	catch(exception X)
	{
		cout << "Fehler beim Speichern" << endl;
	}

		

}

void load_ListMembersFromOutputFile(list<Object> & tempList)
{
	try
	{
		 string s_temporaryX;
		 string s_temporaryY;
		 int temporaryX;
		 int temporaryY;
		
		ifstream DATAFILE;
		DATAFILE.open("ListMembers.save",ios::in);

		do
		{
			getline(DATAFILE,s_temporaryX);
			stringstream convert(s_temporaryX);
			if(!(convert >> temporaryX))
			{
				temporaryX = 0;
			}
			getline(DATAFILE,s_temporaryY);
			temporaryY = atoi(s_temporaryY.c_str());
			tempList.push_back(Object(temporaryX,temporaryY));
		
			
		}while(DATAFILE.eof() != true);

		tempList.pop_back();
	}
	catch(exception X)
	{
		cout << "Fehler beim Laden" << endl;

	}


}

void showListInsertions(list<Object> & tempList)
{
	for(list<Object>::iterator myIter = tempList.begin();myIter != tempList.end();++myIter)
	{
		cout << "X:   " << myIter->get_Position()->x << endl;
		cout << "Y:   " << myIter->get_Position()->y << endl;
	}
}

void put_int(list<Object> & tempList)
{
	tempList.push_back(Object(3,5));
}
