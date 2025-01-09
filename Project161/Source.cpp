#include<iostream>
#include<fstream>
#include<string>
#include"Header.h"
#include<cstring>
using namespace std;


//************//
//        MAIN FUNCTION           //
//                                //
//************//

int main()
{
	system("Color E4");
	cout << endl;
	cout <<"\t\t"<< "                       *******************************************" << endl;
	cout << "\t\t" << "                       *             WELCOME TO                  *" << endl;
	cout << "\t\t" << "                       *         CricBuzz Application            *" << endl;
	cout << "\t\t" << "                       *******************************************" << endl;

	//-----------------------------------------------------------------------------------------//

	team obj;
	match obj1;
	string user_name, pasword;
	cout << "Enter a User Name For Admin Login : ";
	cin >> user_name;
	cout << "Enter a Password : ";
	cin >> pasword;

	//------------------------------------------------------------------------------------------//
	int  choice;
	if (user_name == obj.Admin_user_name && pasword == obj.password)
	{
		do {


			cout << "\t\t" << " ----------------------------------------------\n";
			cout << "\t\t" << " | Press 1 For Add Players                     |" << endl;
			cout << "\t\t" << " | Press 2 For Remove Players                  |" << endl;
			cout << "\t\t" << " | Press 3 For Search Players                  |" << endl;
			cout << "\t\t" << " | Press 4 For Update Players                  |" << endl;
			cout << "\t\t" << " | Press 5 For Display Matched                 |" << endl;
			cout << "\t\t" << " | Press 6 For Update Caption                  |" << endl;
			cout << "\t\t" << " | Press 7 For Update Coach                    |" << endl;
			cout << "\t\t" << " | Press 8 For Display Team                    |" << endl;
			cout << "\t\t" << " | Press 9 For Scehdule Match                  |" << endl;
			cout << "\t\t" << " | Press 10 For Conduct Match                  |" << endl;
			cout << "\t\t" << " | Press 11 For Update Team Ranking            |" << endl;
			cout << "\t\t" << " | Press 12 For Display Upcoming Match         |" << endl;
			cout << "\t\t" << " | Press 13 For Display Recent Matches         |" << endl;
			cout << "\t\t" << " | Press 14 For Update World Record            |" << endl;
			cout << "\t\t" << " | Press 15 For Display Update World Record    |" << endl;
			cout << "\t\t" << " | Press 00 For Exit                           |" << endl;
			cout << "\t\t" << " -----------------------------------------------\n " << endl;


			cout << "Enter a Choice is:";
			cin >> choice;
			while (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Enter Again:";
				cin >> choice;
			}

			if (choice == 1)
			{
				obj.add_player();
				system("cls");
				obj.displaye_data();
			}

			else if (choice == 2)
			{
				system("cls");
				obj.removal_player();
			}

			else if (choice == 3)
			{
				system("cls");
				obj.search_player();
			}

			else if (choice == 4)
			{
				system("cls");
				obj.update_player();
			}

			else if (choice == 5)
			{
				system("cls");
				obj1.display_Matches();
			}

			else if (choice == 6)
			{
				system("cls");
				obj1.Update_Captain();
			}

			else if (choice == 7)
			{
				system("cls");
				obj1.Update_Coach();
			}

			else if (choice == 8)
			{
				system("cls");
				obj1.Display_Teams();
			}
			else if (choice == 9) {
				system("cls");
				obj1.scheduleMatch();
			}
			else if (choice == 10) {
				system("cls");
				obj1.conductMatch();
			}
			else if (choice == 11) {
				system("cls");
				obj1.updateTeamRanking();
			}
			else if (choice == 12) {
				system("cls");
				obj1.displayUpcomingMatches();
			}
			else if (choice == 13) {
				system("cls");
				obj1.displayRecentMatches();
			}
			else if (choice == 14) {
				system("cls");
				obj1.updateWorldRecords();
			}
			else if (choice == 15) {
				system("cls");
				obj1.Displayupdateworldrecord();
			}
			else {
				cout << "Invalid Input:" << endl;
			}
		} while (choice != 00);

		system("cls");

	}
	else
	{
		cout << "The User Name and passward are incorrect " << endl;
	}
	cout << "\t\t-------------------------------------------\n";
	cout << "\t\t|Thank You For Using Cric Buzz Application |" << endl;
	cout << "\t\t-------------------------------------------\n";
	for (int i = 0; i < 7; ++i)
	{
		delete [] A;
		delete[] A1;
		delete[] Arr;
		delete[] Arr1;
		delete[] Arr2;
		delete[] Arr3;
		delete[] Arr4;
		delete[] Arr5;
	}

	system("pause");
	return 0;
}