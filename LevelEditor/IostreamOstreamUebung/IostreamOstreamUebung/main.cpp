#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string PersonName;
string Occupation;
string Location;
string References;

void CreatPerson();
void EditPerson();
void DisplayPerson();
void SavePerson();
void LoadPerson();

int main(int argc,char ** argv)
{
	char CHOICE[10];

	cout << "Personell Database" << endl;

	while(CHOICE[0] != 'q')
	{
		cout << "--------------------------------MainMenue------------------------------------" << endl;
		cout << "|(C)reate  person						" << endl;
		cout << "|(E)dit Information for Person         " << endl;
		cout << "|(D)isplay a Person					" << endl;
		cout << "|(S)ave a  Person						" << endl;
		cout << "|(L)oad a Person						" << endl;
		cout << "|(Q)uit								" << endl;
		cout << "--------------------------------MainMenue------------------------------------" << endl;

		cin >> CHOICE;


		switch(CHOICE[0])
		{
		case 'c' : CreatPerson(); break;
		case 'e' : EditPerson(); break;
		case 'd' : DisplayPerson();break;
		case 's' : SavePerson();break;
		case 'l' : LoadPerson();break;
		case 'q' : break;
		default: cout << "Invalid Entry" << endl;
		};
	}

		

	return 0;





}

void CreatPerson()
{

}
void EditPerson()
{
	system("CLS");
	cout << "\n\t-----------------------Edit Person---------------------" << endl;
	cout << "Name: " << endl;
	cin.ignore();
	getline(cin,PersonName);

	cout << "Occupation: " << endl;
	getline(cin,Occupation);

	cout << "Location: " << endl;
	getline(cin,Location);

	cout << "References: " << endl;
	getline(cin,References);

}
void DisplayPerson()
{
	system("CLS");
	cout << "\n\n\t-----------PERSON INFORMATION-------------------";
	cout << "Name: " << PersonName << endl;
	cout << "Occupation: " << Occupation << endl;
	cout << "Location: " << Location << endl;
	cout << "References: " << References << endl;
	cout << "\n\n\t-----------PERSON INFORMATION-------------------";


}
void SavePerson()
{
	try
	{
		ofstream DATAFILE;
		DATAFILE.open("DATA1.file",ios::out);

		DATAFILE << PersonName<< "\n";
		DATAFILE << Occupation << "\n";
		DATAFILE << Location << "\n";
		DATAFILE << References << "\n";

		DATAFILE.close();
		cout << "\n\tSuccess! DATA was saved";

	}
	catch(exception X)
	{
		cout << "n\tFile Error! Could not SAVE PERSON.";
	}
}
void LoadPerson()
{
	try
	{
		ifstream DATAFILE;
		DATAFILE.open("DATA1.FILE",ios::in);

		getline(DATAFILE,PersonName);
		getline(DATAFILE,Occupation);
		getline(DATAFILE,Location);
		getline(DATAFILE,References);

		DATAFILE.close();

		cout << "\n\tSuccesfully Loaded" << endl; 
	}
	catch(exception X)
	{
		cout << "\n\tFile Error" << endl;
	}

}