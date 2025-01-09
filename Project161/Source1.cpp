#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include"Header.h"
using namespace std;
string* A, *A1, *A2, *A3, *A4, *A5, *A6, *A7, *A8, *A9, *A10, *A11, *A12, *A13, *A14, *A15, *A16, *A17, *A18, *A19;
string* Arr, *Arr1, *Arr2, *Arr3, *Arr4, *Arr5;
fstream outfile;
fstream my_file, my_file1, my_file2, my_file3, my_file4, my_file5, my_file6;
fstream my_file7, my_file8, my_file9, my_file10, my_file11, my_file12, my_file13, my_file14, my_file15;
fstream my_file16, my_file17, my_file18, my_file19, my_file20, my_file21, my_file22, my_file23, my_file24, my_file25, my_file26, my_file27, my_file28;


//*************//
//           DEFAULT                   //
//         CONSTRUCTOR                 //
//                                     //
//*************//

player::player()
{

	for (int i = 0; i < size; ++i)
	{
		name[i] = "0";
		shirt_no[i] = 0;
		average = 0;
		total_runs = 0;
		matches_played = 0;
		total_wickets = 0;
	}
}

/*player::~player()
{
	for (int i = 0; i < size; ++i)
	{
		delete[] name;
		delete[] shirt_no;
		delete[] average;
		delete[] total_runs;
		delete[] matches_played;
		delete[] total_wickets;
	}

}*/

match::match() {

}
team::~team()
{
	for (int i = 0; i < team_count * 3; ++i) {
		delete[] Icc_ranking;
	}
}

//*************//
//                                     //
//           UPDATE_TEAM               //
//             RANKING                 //
//                                     //
//*************//


void match::updateTeamRanking()
{
	string Team_nam;
	cout << "Enter a Team Name Which Ranking You Want to Update:";
	cin >> Team_nam;
	string search_nam;
	int x, j = 0, v = 0;
	my_file.open("Team_Name.txt", ios::in);
	while (my_file >> search_nam)
	{
		if (search_nam == Team_nam)
		{
			x = v;
		}
		++v;
	}
	my_file.close();
	{
		search_nam = "0";
		v = 0, j = 0;
		my_file2.open("Icc_Ranking_team.txt", ios::in);
		while (my_file2 >> search_nam)
		{
			++v;
		}
		my_file2.close();
		A13 = new string[v];
		my_file2.open("Icc_Ranking_team.txt", ios::in);
		while (my_file2 >> A13[j])
		{
			++j;
		}
		my_file2.close();
		if (x == 0)
		{
			cout << "Enter New ODI Ranking of Team:";
			cin >> A13[(x * 2) + 0];
			cout << "Enter New T20 Ranking of Team:";
			cin >> A13[(x * 2) + 1];
			cout << "Enter New Test Ranking of Team:";
			cin >> A13[(x * 2) + 2];
		}
		else if (x == 1)
		{
			cout << "Enter New ODI Ranking of Team:";
			cin >> A13[(x * 2) + 1];
			cout << "Enter New T20 Ranking of Team:";
			cin >> A13[(x * 2) + 2];
			cout << "Enter New Test Ranking of Team:";
			cin >> A13[(x * 2) + 3];
		}
		else if (x >= 2)
		{
			int o = x * 3;
			cout << "Enter New ODI Ranking of Team:";
			cin >> A13[o + 0];
			cout << "Enter New T20 Ranking of Team:";
			cin >> A13[o + 1];
			cout << "Enter New Test Ranking of Team:";
			cin >> A13[o + 2];
		}
		my_file2.open("Icc_Ranking_team.txt", ios::out);
		for (int i = 0; i < j; ++i)
		{
			my_file2 << A13[i] << endl;
		}
		my_file2.close();
	}
}


//*************//
//                                     //
//           Update World Record      //
//                                     //
//                                     //
//*************//


void match::updateWorldRecords() {
	string tem, nam1;
	int x, j = 0, v = 0;
	int ch;
	cout << "Enter a 1 For Already Existing Player Record Update:";
	cin >> ch;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter Again:";
		cin >> ch;
	}
	if (ch == 1) {
		char c;
		cout << "Enter a R For Runs Update S Four Sixes F four Fours Update and W For Wickets Update:";
		cin >> c;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Enter Again:";
			cin >> c;
		}
		if (c == 'R') {
			cout << "Enter a Player Name:";
			cin >> nam1;
			my_file23.open("Most_Runs.txt", ios::in);
			while (my_file23 >> tem) {
				if (nam1 == tem) {
					x = v;
				}
				++v;
			}
			my_file23.close();
			A15 = new string[v];
			my_file23.open("Most_Runs.txt", ios::in);
			while (my_file23 >> A15[j]) {
				++j;
			}
			my_file23.close();
			cout << "Enter a Player New Score:";
			cin >> A15[x + 1];
			my_file23.open("Most_Runs.txt", ios::out);
			for (int i = 0; i < j; ++i) {
				my_file23 << A15[i] << endl;
			}
			my_file23.close();
		}
		else if (c == 'S') {
			v = 0, j = 0, x = 0;
			cout << "Enter a Player Name:";
			cin >> nam1;
			my_file24.open("Most_Sixes.txt", ios::in);
			while (my_file24 >> tem) {
				if (tem == nam1) {
					x = v;
				}
				++v;
			}
			my_file24.close();
			A16 = new string[v];
			my_file24.open("Most_Sixes.txt", ios::in);
			while (my_file24 >> A16[j]) {
				++j;
			}
			my_file24.close();
			cout << "Enter a New Record of Sixes:";
			cin >> A16[x + 1];
			my_file24.open("Most_Sixes.txt", ios::out);
			for (int i = 0; i < j; ++i) {
				my_file24 << A16[i] << endl;
			}
			my_file24.close();
		}
		else if (c == 'F') {
			v = 0, j = 0, x = 0;
			cout << "Enter a Player Name:";
			cin >> nam1;
			my_file25.open("Most_Fours.txt", ios::in);
			while (my_file25 >> tem) {
				if (tem == nam1) {
					x = v;
				}
				++v;
			}
			my_file25.close();
			A17 = new string[v];
			my_file25.open("Most_Fours.txt", ios::in);
			while (my_file25 >> A17[j]) {
				++j;
			}
			my_file25.close();
			cout << "Enter a New Record of Fours:";
			cin >> A17[x + 1];
			my_file25.open("Most_Fours.txt", ios::out);
			for (int i = 0; i < j; ++i) {
				my_file25 << A17[i] << endl;
			}
			my_file25.close();
		}
		else if (c == 'W') {
			v = 0, j = 0, x = 0;
			cout << "Enter a Player Name:";
			cin >> nam1;
			my_file26.open("Most_Wickets.txt", ios::in);
			while (my_file26 >> tem) {
				if (tem == nam1) {
					x = v;
				}
				++v;
			}
			my_file26.close();
			A18 = new string[v];
			my_file26.open("Most_Wickets.txt", ios::in);
			while (my_file26 >> A18[j]) {
				++j;
			}
			my_file26.close();
			cout << "Enter a New Record of Sixes:";
			cin >> A18[x + 1];
			my_file26.open("Most_Wickets.txt", ios::out);
			for (int i = 0; i < j; ++i) {
				my_file26 << A18[i] << endl;
			}
			my_file26.close();
		}
		else {
			cout << "Invalid Input..!" << endl;
		}
	}
	else {
		cout << "Invalid Input..!" << endl;
	}
}


//*************//
//                                     //
//           DISPLAY World Record     //
//                                     //
//                                     //
//*************//



void match::Displayupdateworldrecord() {
	string tem;
	int j = 0, v = 0;
	my_file23.open("Most_Runs.txt", ios::in);
	while (my_file23 >> tem) {
		++v;
	}
	my_file23.close();
	A15 = new string[v];
	my_file23.open("Most_Runs.txt", ios::in);
	while (my_file23 >> A15[j]) {
		++j;
	}
	my_file23.close();
	cout << "\t\t Most Runs\n" << endl;
	for (int i = 0; i < j; ++i) {
		if (i % 2 == 0) {
			cout << "Player " << i + 1 << " Name:" << A15[i] << endl;
		}
		else {
			cout << "Runs:" << A15[i] << endl;
		}
	}
	v = 0, j = 0;
	my_file24.open("Most_Sixes.txt", ios::in);
	while (my_file24 >> tem) {
		++v;
	}
	my_file24.close();
	A16 = new string[v];
	my_file24.open("Most_Sixes.txt", ios::in);
	while (my_file24 >> A16[j]) {
		++j;
	}
	my_file24.close();
	cout << endl;
	cout << "\t\t Most Sixes\n" << endl;
	for (int i = 0; i < j; ++i) {
		if (i % 2 == 0) {
			cout << "Player " << i + 1 << " Name:" << A16[i] << endl;
		}
		else {
			cout << "Sixes:" << A16[i] << endl;
		}
	}
	v = 0, j = 0;
	my_file25.open("Most_Fours.txt", ios::in);
	while (my_file25 >> tem) {
		++v;
	}
	my_file25.close();
	A17 = new string[v];
	my_file25.open("Most_Fours.txt", ios::in);
	while (my_file25 >> A17[j]) {
		++j;
	}
	my_file25.close();
	cout << endl;
	cout << "\t\t Most Fours\n" << endl;
	for (int i = 0; i < j; ++i) {
		if (i % 2 == 0) {
			cout << "Player " << i + 1 << " Name:" << A17[i] << endl;
		}
		else {
			cout << "Fours:" << A17[i] << endl;
		}
	}
	j = 0, v = 0;
	my_file26.open("Most_Wickets.txt", ios::in);
	while (my_file26 >> tem) {
		++v;
	}
	my_file26.close();
	A18 = new string[v];
	my_file26.open("Most_Wickets.txt", ios::in);
	while (my_file26 >> A18[j]) {
		++j;
	}
	my_file26.close();
	cout << endl;
	cout << "\t\t Most Wickets\n" << endl;
	for (int i = 0; i < j; ++i) {
		if (i % 2 == 0) {
			cout << "Player " << i + 1 << " Name:" << A18[i] << endl;
		}
		else {
			cout << "Wickets:" << A18[i] << endl;
		}
	}
}




//*************//
//                                     //
//           DISPLAY_RECENT            //
//               MATCHES               //
//                                     //
//*************//

void match::displayRecentMatches()
{
	my_file13.open("Scedule_Match_team1.txt", ios::in);
	my_file14.open("Scedule_Match_team2.txt", ios::in);
	my_file15.open("Scedule_Match_venue.txt", ios::in);
	my_file16.open("Scedule_Match_date.txt", ios::in);
	my_file17.open("Scedule_Match_type.txt", ios::in);

	string tempo;
	int x = 0, j = 0;
	while (my_file13 >> tempo)
	{
		++x;
	}
	my_file13.close();
	my_file13.open("Scedule_Match_team1.txt", ios::in);
	A4 = new string[x];
	while (!my_file13.eof())
	{
		my_file13 >> A4[j];
		++j;
	}
	my_file13.close();
	tempo = "0";
	x = 0, j = 0;
	while (my_file14 >> tempo)
	{
		++x;
	}
	my_file14.close();
	A5 = new string[x];
	my_file14.open("Scedule_Match_team2.txt", ios::in);
	while (!my_file14.eof())
	{
		my_file14 >> A5[j];
		++j;
	}
	my_file14.close();


	tempo = "0";
	x = 0, j = 0;
	while (my_file15 >> tempo)
	{
		++x;
	}
	my_file15.close();
	A6 = new string[x];
	my_file15.open("Scedule_Match_venue.txt", ios::in);
	while (!my_file15.eof())
	{
		my_file15 >> A6[j];
		++j;
	}
	my_file15.close();


	tempo = "0";
	x = 0, j = 0;
	while (my_file16 >> tempo)
	{
		++x;
	}
	my_file16.close();
	A3 = new string[x];
	my_file16.open("Scedule_Match_date.txt", ios::in);
	while (!my_file16.eof())
	{
		my_file16 >> A3[j];
		++j;
	}
	my_file16.close();


	tempo = "0";
	x = 0, j = 0;
	while (my_file17 >> tempo)
	{
		++x;
	}
	my_file17.close();
	A7 = new string[x];
	my_file17.open("Scedule_Match_type.txt", ios::in);
	while (!my_file17.eof())
	{
		my_file17 >> A7[j];
		++j;
	}
	my_file17.close();
	cout << "____Recent Matches List____" << endl << endl;
	for (int i = 0; i < x; ++i)
	{
		cout << "Match : " << A4[i] << " VS " << A5[i] << endl;
		cout << "Venue : " << A6[i] << endl;
		cout << "Date : " << A3[i] << endl;
		cout << "Match Type : " << A7[i] << endl;
	}

}


//*************//
//                                     //
//           DISPLAY_UPCOMING          //
//               MATCHES               //
//                                     //
//*************//


void match::displayUpcomingMatches()
{
	my_file18.open("Scedule_Match_team1_up.txt", ios::in);
	my_file19.open("Scedule_Match_team2_up.txt", ios::in);
	my_file20.open("Scedule_Match_venue_up.txt", ios::in);
	my_file21.open("Scedule_Match_date_up.txt", ios::in);
	my_file22.open("Scedule_Match_type_up.txt", ios::in);
	string tempo;
	int x = 0, j = 0;
	while (my_file18 >> tempo)
	{
		++x;
	}
	my_file18.close();
	my_file18.open("Scedule_Match_team1_up.txt", ios::in);
	A8 = new string[x];
	while (!my_file18.eof())
	{
		my_file18 >> A8[j];
		++j;
	}
	my_file18.close();
	tempo = "0";
	x = 0, j = 0;
	while (my_file19 >> tempo)
	{
		++x;
	}
	my_file19.close();
	A9 = new string[x];
	my_file19.open("Scedule_Match_team2_up.txt", ios::in);
	while (!my_file19.eof())
	{
		my_file19 >> A9[j];
		++j;
	}
	my_file19.close();

	tempo = "0";
	x = 0, j = 0;
	while (my_file20 >> tempo)
	{
		++x;
	}
	my_file20.close();
	A10 = new string[x];
	my_file20.open("Scedule_Match_venue_up.txt", ios::in);
	while (!my_file20.eof())
	{
		my_file20 >> A10[j];
		++j;
	}
	my_file20.close();

	tempo = "0";
	x = 0, j = 0;
	while (my_file21 >> tempo)
	{
		++x;
	}
	my_file21.close();
	A11 = new string[x];
	my_file21.open("Scedule_Match_date_up.txt", ios::in);
	while (!my_file21.eof())
	{
		my_file21 >> A11[j];
		++j;
	}
	my_file21.close();


	tempo = "0";
	x = 0, j = 0;
	while (my_file22 >> tempo)
	{
		++x;
	}
	my_file22.close();
	A12 = new string[x];
	my_file22.open("Scedule_Match_type_up.txt", ios::in);
	while (!my_file22.eof())
	{
		my_file22 >> A12[j];
		++j;
	}
	my_file22.close();
	cout << "____Upcoming Matches List____" << endl << endl;
	for (int i = 0; i < x; ++i) {
		cout << "Match : " << A8[i] << " VS " << A9[i] << endl;
		cout << "Venue : " << A10[i] << endl;
		cout << "Date : " << A11[i] << endl;
		cout << "Match Type : " << A12[i] << endl;
	}
}



//*************//
//                                     //
//           DISPLAY MATCHES           //
//                                     //
//                                     //
//*************//


void match::display_Matches()
{
	cout << "The previous and upcoming matches along  with all details : " << endl;
	cout << "Scheduled Matches : " << endl;
	match::displayRecentMatches();

	cout << "Previous Matches : " << endl;
	match::displayUpcomingMatches();

}





//*************//
//                                     //
//           DISPLAY_SCHEDULED         //
//               MATCHES               //
//                                     //
//*************//

void match::Display_Scedule_Matches()
{
	my_file13.open("Scedule_Match_team1.txt", ios::in);
	my_file14.open("Scedule_Match_team2.txt", ios::in);
	my_file15.open("Scedule_Match_venue.txt", ios::in);
	my_file16.open("Scedule_Match_date.txt", ios::in);
	my_file17.open("Scedule_Match_type.txt", ios::in);

	string tempo;
	int x = 0, j = 0;
	while (my_file13 >> tempo)
	{
		++x;
	}
	my_file13.close();
	my_file13.open("Scedule_Match_team1.txt", ios::in);
	A4 = new string[x];
	while (!my_file13.eof())
	{
		my_file13 >> A4[j];
		++j;
	}
	my_file13.close();
	tempo = "0";
	x = 0, j = 0;
	while (my_file14 >> tempo)
	{
		++x;
	}
	my_file14.close();
	A5 = new string[x];
	my_file14.open("Scedule_Match_team2.txt", ios::in);
	while (!my_file14.eof())
	{
		my_file14 >> A5[j];
		++j;
	}
	my_file14.close();

	tempo = "0";
	x = 0, j = 0;
	while (my_file15 >> tempo)
	{
		++x;
	}
	my_file15.close();
	A6 = new string[x];
	my_file15.open("Scedule_Match_venue.txt", ios::in);
	while (!my_file15.eof())
	{
		my_file15 >> A6[j];
		++j;
	}
	my_file15.close();

	tempo = "0";
	x = 0, j = 0;
	while (my_file16 >> tempo)
	{
		++x;
	}
	my_file16.close();
	A3 = new string[x];
	my_file16.open("Scedule_Match_date.txt", ios::in);
	while (!my_file16.eof())
	{
		my_file16 >> A3[j];
		++j;
	}
	my_file16.close();


	tempo = "0";
	x = 0, j = 0;
	while (my_file17 >> tempo) {
		++x;
	}
	my_file17.close();
	A7 = new string[x];
	my_file17.open("Scedule_Match_type.txt", ios::in);
	while (!my_file17.eof())
	{
		my_file17 >> A7[j];
		++j;
	}
	my_file17.close();
	cout << "____Schedule Matches____" << endl << endl;
	for (int i = 0; i < x; ++i) {
		cout << "Match : " << A4[i] << " VS " << A5[i] << endl;
		cout << "Venue : " << A6[i] << endl;
		cout << "Date : " << A3[i] << endl;
		cout << "Match Type : " << A7[i] << endl;
	}
}

//*************//
//                                     //
//           SCHEDULED                 //
//         MATCHE FUNCTION             //
//                                     //
//*************//
void match::scheduleMatch()
{
	string t;
	int j = 0, x = 0;
	cout << "_____Team Name_____" << endl << endl;
	my_file.open("Team_Name.txt", ios::in);
	while (my_file >> t) {
		cout << t << endl;
		++x;
	}
	my_file.close();
	x = 0;
	char choice;
	cout << "Enter a 't' For Secdule a Tournament and 'm' For Match:";
	cin >> choice;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter Again:";
		cin >> choice;
	}
	if (choice == 'm')
	{
		cout << "Enter a Number of Matches Which you Want to Schedule:";
		cin >> count_match;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Enter a Number of Matches Which you Want to Schedule:";
			cin >> count_match;
		}
		team1 = new string[count_match];
		team2 = new string[count_match];
		venue = new string[count_match];
		date = new string[count_match];
		match_type = new string[count_match];

		my_file13.open("Scedule_Match_team1.txt", ios::app);
		my_file14.open("Scedule_Match_team2.txt", ios::app);
		my_file15.open("Scedule_Match_venue.txt", ios::app);
		my_file16.open("Scedule_Match_date.txt", ios::app);
		my_file17.open("Scedule_Match_type.txt", ios::app);
		my_file18.open("Scedule_Match_team1_up.txt", ios::app);
		my_file19.open("Scedule_Match_team2_up.txt", ios::app);
		my_file20.open("Scedule_Match_venue_up.txt", ios::app);
		my_file21.open("Scedule_Match_date_up.txt", ios::app);
		my_file22.open("Scedule_Match_type_up.txt", ios::app);
		for (int i = 0; i < count_match; ++i)
		{
			cout << "Enter a Match Status:";
			cin >> match_status;
			if (match_status == "Recent")
			{
				cout << "Enter a Match Type:";
				cin >> match_type[i];
				my_file17 << match_type[i] << endl;
				cout << "Enter a One Team Name From Available Teams is:";
				cin >> team1[i];
				my_file13 << team1[i] << endl;
				cout << "Enter a Team Two Name From Available Teams is:";
				cin >> team2[i];
				my_file14 << team2[i] << endl;
				cout << "Enter a Venue of Match " << i + 1 << " is:";
				cin >> venue[i];
				my_file15 << venue[i] << endl;
				cout << "Enter  a Date of Match " << i + 1 << " is:";
				cin >> date[i];
				my_file16 << date[i] << endl;
			}
			else
			{
				cout << "Enter a Match Type:";
				cin >> match_type[i];
				my_file22 << match_type[i] << endl;
				cout << "Enter a One Team Name From Available Teams is:";
				cin >> team1[i];
				my_file18 << team1[i] << endl;
				cout << "Enter a Team Two Name From Available Teams is:";
				cin >> team2[i];
				my_file19 << team2[i] << endl;
				cout << "Enter a Venue of Match " << i + 1 << " is:";
				cin >> venue[i];
				my_file20 << venue[i] << endl;
				cout << "Enter  a Date of Match " << i + 1 << " is:";
				cin >> date[i];
				my_file21 << date[i] << endl;
			}
		}
		my_file13.close();
		my_file14.close();
		my_file15.close();
		my_file15.close();
		my_file16.close();
		my_file17.close();
		my_file18.close();
		my_file19.close();
		my_file20.close();
		my_file21.close();
		my_file22.close();
	}
	else if (choice == 't')
	{
		cout << "Enter a Match Status:";
		cin >> match_status;
		cout << "Enter a Tournament Name:";
		cin >> tornament_name;
		int c1;
		cout << "Enter a Total Teams in Tournament:";
		cin >> c1;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Enter Again a Total Teams in Tournament:";
			cin >> c1;
		}
		cout << "Enter a Total Matches of Tournament :";
		cin >> count_match;
		while (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Enter a Total Matches of Tournament :";
			cin >> count_match;
		}
		my_file13.open("Scedule_Match_team1.txt", ios::app);
		my_file14.open("Scedule_Match_team2.txt", ios::app);
		my_file15.open("Scedule_Match_venue.txt", ios::app);
		my_file16.open("Scedule_Match_date.txt", ios::app);
		my_file17.open("Scedule_Match_type.txt", ios::app);
		my_file18.open("Scedule_Match_team1_up.txt", ios::app);
		my_file19.open("Scedule_Match_team2_up.txt", ios::app);
		my_file20.open("Scedule_Match_venue_up.txt", ios::app);
		my_file21.open("Scedule_Match_date_up.txt", ios::app);
		my_file22.open("Scedule_Match_type_up.txt", ios::app);
		for (int i = 0; i < count_match; ++i)
		{
			if (match_status == "Recent")
			{
				cout << "Enter a Team One Name From Available Teams is:";
				cin >> team1[i];
				my_file13 << team1[i] << endl;
				cout << "Enter a Team Two Name From Available Teams is:";
				cin >> team2[i];
				my_file14 << team2[i] << endl;
				cout << "Enter a Venue of Match " << i + 1 << " is:";
				cin >> venue[i];
				my_file15 << venue[i] << endl;
				cout << "Enter  a Date of Match " << i + 1 << " is:";
				cin >> date[i];
				my_file16 << date[i] << endl;
			}
			else
			{
				cout << "Enter a Team One Name is:";
				cin >> team1[i];
				my_file18 << team1[i] << endl;
				cout << "Enter a Team Two Name is:";
				cin >> team2[i];
				my_file19 << team2[i] << endl;
				cout << "Enter a Venue of Match " << i + 1 << " is:";
				cin >> venue[i];
				my_file20 << venue[i] << endl;
				cout << "Enter  a Date of Match " << i + 1 << " is:";
				cin >> date[i];
				for (int j = 0; j < i; ++j)
				{
					if (date[i] == date[j])
					{
						cout << "Enter a New Date of Match:";
						cout << date[i];
					}
				}
				my_file21 << date[i] << endl;
			}
		}
		my_file13.close();
		my_file14.close();
		my_file15.close();
		my_file15.close();
		my_file16.close();
		my_file17.close();
		my_file18.close();
		my_file19.close();
		my_file20.close();
		my_file21.close();
		my_file22.close();
	}
	else {
		cout << "Invalid Input...!" << endl;
	}
}

//*************//
//                                     //
//           CONDUCTED                 //
//         MATCHE FUNCTION             //
//                                     //
//*************//


void match::conductMatch()
{
	char Choice;
	int condition;
	cout << "Enter a R For Conduct Already Scedule Match And N For New Secdule Match:";
	cin >> Choice;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter a Valid Input:";
		cin >> Choice;
	}
	if (Choice == 'N')
	{
		match::scheduleMatch();
	}
	else if (Choice == 'R') {
		match::Display_Scedule_Matches();
		match::displayUpcomingMatches();
		string Match_date;
		cout << "Enter a Match Date Which You Want to Conduct:";
		cin >> Match_date;
		my_file13.open("Scedule_Match_team1.txt", ios::in);
		my_file14.open("Scedule_Match_team2.txt", ios::in);
		my_file15.open("Scedule_Match_venue.txt", ios::in);
		my_file16.open("Scedule_Match_date.txt", ios::in);
		my_file17.open("Scedule_Match_type.txt", ios::in);
		my_file18.open("Scedule_Match_team1_up.txt", ios::in);
		my_file19.open("Scedule_Match_team2_up.txt", ios::in);
		my_file20.open("Scedule_Match_venue_up.txt", ios::in);
		my_file21.open("Scedule_Match_date_up.txt", ios::in);
		string te;
		int tbh = 0, j = 0, x;
		while (my_file16 >> te)
		{
			if (te == Match_date)
			{
				x = tbh;
				condition = 1;
			}
			++tbh;
		}
		my_file16.close();
		A3 = new string[tbh];
		my_file16.open("Scedule_Match_date.txt", ios::in);
		while (my_file16 >> A3[j])
		{
			++j;
		}
		my_file16.close();
		te = "0";
		tbh = 0, j = 0;
		while (my_file13 >> te)
		{
			++tbh;
		}
		my_file13.close();
		A4 = new string[tbh];
		my_file13.open("Scedule_Match_team1.txt", ios::in);
		while (my_file13 >> A4[j])
		{
			++j;
		}
		my_file13.close();



		tbh = 0, j = 0;
		while (my_file14 >> te)
		{
			++tbh;
		}
		my_file14.close();
		A5 = new string[tbh];
		my_file14.open("Scedule_Match_team2.txt", ios::in);
		while (my_file14 >> A5[j])
		{
			++j;
		}
		my_file14.close();
		te = "0";
		tbh = 0, j = 0;
		while (my_file15 >> te)
		{
			++tbh;
		}
		my_file15.close();
		A6 = new string[tbh];
		my_file15.open("Scedule_Match_venue.txt", ios::in);
		while (my_file15 >> A6[j])
		{
			++j;
		}
		my_file15.close();



		te = "0";
		tbh = 0, j = 0;
		while (my_file17 >> te)
		{
			++tbh;
		}
		my_file17.close();
		A7 = new string[tbh];
		my_file17.open("Scedule_Match_type.txt", ios::in);
		while (my_file17 >> A7[j])
		{
			++j;
		}
		my_file17.close();

		te = "0";
		tbh = 0, j = 0;
		while (my_file21 >> te)
		{
			if (te == Match_date)
			{
				x = tbh;
				condition = 2;
			}
			++tbh;
		}
		my_file21.close();
		A11 = new string[tbh];
		my_file21.open("Scedule_Match_date_up.txt", ios::in);
		while (my_file21 >> A11[j])
		{
			++j;
		}
		my_file21.close();
		te = "0";
		tbh = 0, j = 0;
		while (my_file18 >> te)
		{
			++tbh;
		}
		my_file18.close();
		A8 = new string[tbh];
		my_file18.open("Scedule_Match_team1_up.txt", ios::in);
		while (my_file18 >> A8[j])
		{
			++j;
		}
		my_file18.close();


		tbh = 0, j = 0;
		while (my_file19 >> te)
		{
			++tbh;
		}
		my_file19.close();
		A9 = new string[tbh];
		my_file19.open("Scedule_Match_team2_up.txt", ios::in);
		while (my_file19 >> A9[j])
		{
			++j;
		}
		my_file19.close();
		te = "0";
		tbh = 0, j = 0;
		while (my_file20 >> te)
		{
			++tbh;
		}
		my_file20.close();
		A10 = new string[tbh];
		my_file20.open("Scedule_Match_venue_up.txt", ios::in);
		while (my_file20 >> A10[j])
		{
			++j;
		}
		my_file20.close();



		te = "0";
		tbh = 0, j = 0;
		my_file22.open("Scedule_Match_type_up.txt", ios::in);
		while (my_file22 >> te)
		{
			++tbh;
		}
		my_file22.close();
		A12 = new string[tbh];
		my_file22.open("Scedule_Match_type_up.txt", ios::in);
		while (my_file22 >> A12[j])
		{
			++j;
		}
		my_file22.close();
		if (condition == 1)
		{
			cout << "____Conduct Match____" << endl << endl;
			cout << "Match : " << A4[x] << " VS " << A5[x] << endl;
			cout << "Venue : " << A6[x] << endl;
			cout << "Date : " << A3[x] << endl;
			cout << "Match Type : " << A7[x] << endl;
		}

		else if (condition == 2)
		{
			cout << "____Conduct Match____" << endl << endl;
			cout << "Match : " << A8[x] << " VS " << A9[x] << endl;
			cout << "Venue : " << A10[x] << endl;
			cout << "Date : " << A11[x] << endl;
			cout << "Match Type : " << A12[x] << endl;
		}
	}
	else {
		cout << "Invalid Input..!" << endl;
	}
	my_file17.close();
	my_file18.close();
	my_file19.close();
	my_file20.close();
	my_file21.close();
}
//*************//
//                                     //
//           DISPLAY                   //
//         TEAM FUNCTION               //
//                                     //
//*************//

void team::Display_Teams()
{
	string t;
	int j = 0, x = 0;
	cout << "_____All Team Name_____" << endl << endl;
	my_file.open("Team_Name.txt", ios::in);
	while (my_file >> t) {
		cout << t << endl;
		++x;
	}
	my_file.close();

}

//*************//
//                                     //
//           USER NAME,PASSWARD        //
//               SECTION               //
//                                     //
//*************//

team::team() :player()
{
	Admin_user_name = "Sami";
	password = "Sami_68";
}


//*************//
//                                     //
//              UPDATE                 //
//         CAPTION FUNCTION            //
//                                     //
//*************//

void team::Update_Captain()
{
	string UP_CAPTION;
	cout << "Enter a Captain Name Which You Want to Update:";
	cin >> UP_CAPTION;
	string h;
	int a = 0, b = 0, j = 0;
	my_file10.open("Captain_name.txt", ios::in);
	while (my_file10 >> h)
	{
		if (UP_CAPTION == h)
		{
			a = b;
		}
		++b;
	}
	my_file10.close();
	{
		A1 = new string[b];
		my_file10.open("Captain_name.txt", ios::in);
		while (my_file10 >> A1[j])
		{
			++j;
		}
		my_file10.close();
		cout << "Enter a New Captain is:";
		cin >> A1[a];
		my_file10.open("Captain_name.txt", ios::out);
		for (int i = 0; i < b; ++i)
		{
			my_file10 << A1[i] << endl;
		}
		my_file10.close();
	}

}

//*************//
//                                     //
//             UPDATE                  //
//         COACH FUNCTION              //
//                                     //
//*************//



void team::Update_Coach()
{
	string UP_COACH;
	cout << "Enter a Coach Name Which You Want to Update:";
	cin >> UP_COACH;

	//*************//
	//                                     //
	//            DELETE ARRAY             //
	//                                     //
	//*************//

	for (int i = 0; i < 7; ++i)
	{
		delete[] A;
		delete[] A1;
		delete[] Arr;
		delete[] Arr1;
		delete[] Arr2;
		delete[] Arr3;
		delete[] Arr4;
		delete[] Arr5;
	}
	string h, *A5;
	int a, b = 0, j = 0;
	my_file11.open("Coach_Name.txt", ios::in);
	while (my_file11 >> h)
	{
		cout << h << endl;
		if (h == UP_COACH)
		{
			a = b;
		}
		b++;
	}
	my_file11.close();
	{
		A5 = new string[b];
		my_file11.open("Coach_Name.txt", ios::in);
		while (my_file11 >> A5[j])
		{
			++j;
		}
		my_file11.close();
		cout << "Enter a New Captain is:";
		cin >> A5[a];
		my_file11.open("Coach_Name.txt", ios::out);
		for (int i = 0; i < b; ++i)
		{
			my_file11 << A5[i] << endl;
		}
		my_file11.close();
	}
}

//*************//
//                                     //
//             ADD                     //
//         PLAYER FUNCTION             //
//                                     //
//*************//

void team::add_player()
{

	int c = 0, c1 = 0, c2 = 0;
	cout << "Enter the number of teams which you want to store data" << endl;
	cin >> team_count;
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter Again Team count:";
		cin >> team_count;
	}
	Icc_ranking = new int[team_count * 3];
	my_file.open("Team_Name.txt", ios::app);
	my_file1.open("Players_Name.txt", ios::app);
	my_file2.open("Icc_Ranking_team.txt", ios::app);
	my_file3.open("Shirt_no.txt", ios::app);
	my_file4.open("Averages.txt", ios::app);
	my_file5.open("plyer_Total_runs.txt", ios::app);
	my_file6.open("Total_Match_player.txt", ios::app);
	my_file7.open("Total_Wicket_Player.txt", ios::app);
	my_file8.open("Total_match_won_team.txt", ios::app);
	my_file9.open("Total_match_lost_team.txt", ios::app);
	my_file10.open("Captain_name.txt", ios::app);
	my_file11.open("Coach_Name.txt", ios::app);
	my_file12.open("Information.txt", ios::app);



	for (int j = 0; j < team_count; j++)
	{
		cout << "Enter the team name " << endl;
		cin >> team_name[j];
		my_file << team_name[j] << endl;
		my_file12 << team_name[j] << endl;
		for (int k = 0; k < 3; ++k)
		{

			if (k == 0)
			{
				cout << "Team Ranking in ODI Format is:";
				cin >> Icc_ranking[c1];
				my_file2 << Icc_ranking[c1] << endl;
				my_file12 << Icc_ranking[c1] << endl;
				++c1;
			}

			else if (k == 1)
			{
				cout << "Team Ranking in T20 Format is:";
				cin >> Icc_ranking[c1];
				my_file2 << Icc_ranking[c1] << endl;
				my_file12 << Icc_ranking[c1] << endl;
				++c1;
			}
			else
			{
				cout << "Team Ranking in Test Format is:";
				cin >> Icc_ranking[c1];
				my_file2 << Icc_ranking[c1] << endl;
				my_file12 << Icc_ranking[c1] << endl;
				++c1;
			}
		}
		if (c < 1)
		{
			cout << "Enter the players of both teams count which you want to enter : ";
			cin >> size;
			while (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Enter Again Both Teams Players Count:";
				cin >> size;
			}
			name = new string[size * team_count];
			shirt_no = new int[size * team_count];
			average = new double[size * team_count];
			total_runs = new int[size * team_count];
			matches_played = new int[size * team_count];
			total_wickets = new int[size * team_count];
			++c;
		}
		for (int i = 0; i < size; i++)
		{
			cout << "------------------------------------------------ " << endl;
			cout << "Enter the name of player :";
			cin.ignore();
			getline(cin, name[c2]);
			my_file1 << name[c2] << endl;
			my_file12 << name[c2] << endl;


			cout << "Enter the shirt number : ";
			cin >> shirt_no[c2];
			my_file3 << shirt_no[c2] << endl;
			my_file12 << shirt_no[c2] << endl;


			cout << "Enter the average of player :";
			cin >> average[c2];
			my_file4 << average[c2] << endl;
			my_file12 << average[c2] << endl;


			cout << "Enter the Total Runs of player:";
			cin >> total_runs[c2];
			my_file5 << total_runs[c2] << endl;
			my_file12 << total_runs[c2] << endl;


			cout << "Enter the matches no. that player played :";
			cin >> matches_played[c2];
			my_file6 << matches_played[c2] << endl;
			my_file12 << matches_played[c2] << endl;


			cout << "Enter the Total wickets of player :";
			cin >> total_wickets[c2];
			my_file7 << total_wickets[c2] << endl;
			my_file12 << total_wickets[c2] << endl;
			cout << endl;
			++c2;
		}
		cout << "Enter total Matches Won By Team:";
		cin >> total_m_won[j];
		my_file8 << total_m_won[j] << endl;
		my_file12 << total_m_won[j] << endl;

		cout << "Enter a Total Matches Lost By Team: ";
		cin >> total_m_lost[j];
		my_file9 << total_m_lost[j] << endl;
		my_file12 << total_m_lost[j] << endl;


		cout << "Enter  a Captain of Team is:";
		cin.ignore();
		getline(cin, team_captain[j]);
		my_file10 << team_captain[j] << endl;
		my_file12 << team_captain[j] << endl;

		cout << "Enter a Coach Name of Team is:";
		getline(cin, team_coach[j]);
		my_file11 << team_coach[j] << endl;
		my_file12 << team_coach[j] << endl;
	}

	my_file.close();
	my_file1.close();
	my_file2.close();
	my_file3.close();
	my_file4.close();
	my_file5.close();
	my_file6.close();
	my_file7.close();
	my_file8.close();
	my_file9.close();
	my_file10.close();
	my_file11.close();
	my_file12.close();
}

//*************//
//                                     //
//             REMOVAL                 //     
//                                     //
//         PLAYER FUNCTION             //
//                                     //
//*************//


void team::removal_player()
{
	string removal_player;
	cout << "Enter the player name which data you want to remove :";
	cin >> removal_player;
	int j = 0, so;
	int z = 0, x, y, e = 0;
	int counter1 = 0, counter2 = 0;
	string too;
	my_file10.open("Captain_name.txt", ios::in);
	while (my_file10 >> too)
	{
		if (too == removal_player)
		{
			y = e;
		}
		++e;
	}
	so = y;
	A1 = new string[e];
	my_file10.close();
	{
		my_file10.open("Captain_name.txt", ios::in);
		while (my_file10 >> A1[j])
		{
			++j;
		}
		my_file10.close();
		for (int i = 0; i < y * team_count; ++i)
		{
			if (A1[i] == removal_player)
			{
				for (int j = i; j < ((y * team_count) - 1); ++j)
				{
					A1[j] = A1[j + 1];
					y--;
					i--;
				}
			}
		}
		my_file10.open("Captain_name.txt", ios::out);
		for (int i = 0; i < so; ++i)
		{
			my_file10 << A1[i] << endl;
		}
		my_file10.close();

		x = 0, z = 0, y = 0, e = 0, so = 0, j = 0;
		my_file12.open("Information.txt", ios::in);
		while (my_file12 >> too)
		{
			if (too == removal_player)
			{
				y = e;
			}
			++e;
		}
		so = y;
		my_file12.close();
		A = new string[e];
		my_file12.open("Information.txt", ios::in);
		while (my_file12 >> A[j])
		{
			++j;
		}
		my_file12.close();

		x = 0, z = 0, y = 0, e = 0, so = 0, j = 0;
		my_file1.open("Players_Name.txt", ios::in);
		while (my_file1 >> too)
		{
			if (too == removal_player)
			{
				x = z;
			}
			++z;
		}
		my_file1.close();
		int	s = 0;
		Arr = new string[z];
		s = z;
		j = 0;
		my_file1.open("Players_Name.txt", ios::in);
		while (my_file1 >> Arr[j])
		{
			++j;

		}
		my_file1.close();
		z = 0, j = 0, too = "0";
		my_file3.open("Shirt_no.txt", ios::in);
		while (my_file3 >> too)
		{
			++z;
		}
		my_file3.close();
		Arr1 = new string[z];
		my_file3.open("Shirt_no.txt", ios::in);
		while (my_file3 >> Arr1[j])
		{
			++j;

		}
		my_file3.close();

		z = 0, j = 0, too = "0";
		my_file4.open("Averages.txt", ios::in);
		while (my_file4 >> too)
		{
			++z;
		}
		my_file4.close();

		Arr2 = new string[z];
		my_file4.open("Averages.txt", ios::in);
		while (my_file4 >> Arr2[j]) {
			++j;

		}
		my_file4.close();

		z = 0, j = 0, too = "0";
		my_file5.open("plyer_Total_runs.txt", ios::in);
		while (my_file5 >> too)
		{
			++z;
		}
		my_file5.close();
		Arr3 = new string[z];
		my_file5.open("plyer_Total_runs.txt", ios::in);
		while (my_file5 >> Arr3[j])
		{
			++j;

		}
		my_file5.close();

		s = 0, z = 0, j = 0, too = "0";
		my_file6.open("Total_Match_player.txt", ios::in);
		while (my_file6 >> too)
		{
			++z;
		}
		my_file6.close();

		Arr4 = new string[z];
		my_file6.open("Total_Match_player.txt", ios::in);
		while (my_file6 >> Arr4[j])
		{
			++j;

		}
		my_file6.close();

		z = 0, j = 0, too = "0";
		my_file7.open("Total_Wicket_Player.txt", ios::in);
		while (my_file7 >> too)
		{
			++z;
		}
		my_file7.close();

		Arr5 = new string[z];
		my_file7.open("Total_Wicket_Player.txt", ios::in);
		while (my_file7 >> Arr5[j])
		{
			++j;

		}
		my_file7.close();

		my_file1.open("Players_Name.txt", ios::out);
		my_file3.open("Shirt_no.txt", ios::out);
		my_file4.open("Averages.txt", ios::out);
		my_file5.open("plyer_Total_runs.txt", ios::out);
		my_file6.open("Total_Match_player.txt", ios::out);
		my_file7.open("Total_Wicket_Player.txt", ios::out);

		int jbh = x;
		for (int i = 0; i < (x * team_count); i++)
		{
			if (Arr[i] == removal_player)
			{

				for (int j = i; j < ((x * team_count) - 1); j++)
				{
					Arr[j] = Arr[j + 1];
					Arr1[j] = Arr1[j + 1];
					Arr2[j] = Arr2[j + 1];
					Arr3[j] = Arr3[j + 1];
					Arr4[j] = Arr4[j + 1];
					Arr5[j] = Arr5[j + 1];

					x--;
					i--;
				}

			}
		}
		for (int i = 0; i < jbh; ++i)
		{
			my_file1 << Arr[i] << endl;
			my_file3 << Arr1[i] << endl;
			my_file4 << Arr2[i] << endl;
			my_file5 << Arr3[i] << endl;
			my_file6 << Arr4[i] << endl;
			my_file7 << Arr5[i] << endl;
		}

		my_file1.close();
		my_file3.close();
		my_file4.close();
		my_file5.close();
		my_file6.close();
		my_file7.close();
	}

}

//*************//
//                                     //
//             SEARCH                  //     
//                                     //
//         PLAYER FUNCTION             //
//                                     //
//*************//

void team::search_player()
{
	string search;
	cout << "Enter the name which you want to search: ";
	cin >> search;

	int z = 0, x, o = 0;
	string t;
	ifstream fin;
	cout << "____Player Info____" << endl << endl;
	fin.open("Players_Name.txt");
	while (true)
	{
		if (fin.eof())
		{
			break;
		}
		fin >> t;
		if (t == search)
		{
			x = z;
		}
		++z;
	}
	fin.close();
	{
		int	s = 0;
		Arr = new string[z];
		s = z;
		int j = 0;
		fin.open("Players_Name.txt");
		while (true)
		{
			if (fin.eof())
			{
				break;
			}
			fin >> Arr[j];
			++j;

		}

		fin.close();
		if (x > 1)
		{
			cout << "The Player Name is:" << Arr[x - 1] << endl;
		}
		else
		{
			cout << "The Player Name is:" << Arr[x] << endl;
		}

		z = 0, j = 0, t = "0";
		my_file3.open("Shirt_no.txt", ios::in);
		while (!my_file3.eof())
		{
			my_file3 >> t;
			++z;
		}
		my_file3.close();
		Arr1 = new string[z];
		my_file3.open("Shirt_no.txt", ios::in);

		while (!my_file3.eof())
		{
			my_file3 >> Arr1[j];
			++j;

		}
		my_file3.close();

		if (x > 1)
		{
			cout << "The Shirt No: " << Arr1[x - 1] << endl;
		}
		else
		{
			cout << "The Shirt No: " << Arr1[x] << endl;
		}
		z = 0, j = 0, t = "0";

		my_file4.open("Averages.txt", ios::in);
		while (!my_file4.eof())
		{
			my_file4 >> t;
			++z;
		}
		my_file4.close();
		Arr2 = new string[z];
		my_file4.open("Averages.txt", ios::in);
		while (!my_file4.eof())
		{
			my_file4 >> Arr2[j];
			++j;

		}
		my_file4.close();
		if (x > 1)
		{
			cout << "The Player Average: " << Arr2[x - 1] << endl;
		}
		else
		{
			cout << "The Player Average: " << Arr2[x] << endl;
		}
		z = 0, j = 0, t = "0";
		my_file5.open("plyer_Total_runs.txt", ios::in);
		while (!my_file5.eof())
		{
			my_file5 >> t;
			++z;
		}
		my_file5.close();
		Arr3 = new string[z];
		my_file5.open("plyer_Total_runs.txt", ios::in);
		while (!my_file5.eof())
		{
			my_file5 >> Arr3[j];
			++j;

		}
		my_file5.close();
		if (x > 1)
		{
			cout << "The Player Total Runs: " << Arr3[x - 1] << endl;
		}
		else {
			cout << "The Player Total Runs: " << Arr3[x] << endl;
		}
		s = 0, z = 0, j = 0, t = "0";


		my_file6.open("Total_Match_player.txt", ios::in);
		while (!my_file6.eof())
		{
			my_file6 >> t;
			++z;
		}
		my_file6.close();
		Arr4 = new string[z];
		my_file6.open("Total_Match_player.txt", ios::in);
		while (!my_file6.eof())
		{
			my_file6 >> Arr4[j];
			++j;

		}
		my_file6.close();
		if (x > 1)
		{
			cout << "The matches no. that player played :" << Arr4[x - 1] << endl;
		}
		else
		{
			cout << "The matches no. that player played :" << Arr4[x] << endl;
		}
		z = 0, j = 0, t = "0";

		my_file7.open("Total_Wicket_Player.txt", ios::in);
		while (true)
		{
			if (my_file7.eof())
			{
				break;
			}
			my_file7 >> t;
			++z;
		}
		my_file7.close();

		Arr5 = new string[z];
		my_file7.open("Total_Wicket_Player.txt", ios::in);
		while (true)
		{
			if (my_file7.eof())
			{
				break;
			}
			my_file7 >> Arr5[j];
			++j;

		}
		my_file7.close();
		if (x > 1)
		{
			cout << "The Total wickets of player :" << Arr5[x - 1] << endl;
		}
		else {
			cout << "The Total wickets of player :" << Arr5[x] << endl;
		}
	}
}


//*************//
//                                     //
//             UPDATE                  //     
//                                     //
//         PLAYER FUNCTION             //
//                                     //
//*************//


void team::update_player()
{
	string update;
	cout << "Enter the which player data you want to update :";
	cin >> update;

	int z = 0, x;
	string tmp;
	my_file1.open("Players_Name.txt", ios::in);
	while (my_file1 >> tmp)
	{
		if (tmp == update)
		{
			x = z;
		}
		++z;
	}
	my_file1.close();
	{
		int	s = 0;
		Arr = new string[z];
		s = z;
		int j = 0;
		my_file1.open("Players_Name.txt", ios::in);
		while (my_file1 >> Arr[j])
		{
			++j;
			//++s;
		}
		my_file1.close();
		my_file1.open("Players_Name.txt", ios::out);
		cout << "Enter the name ";
		cin >> Arr[x];
		for (int i = 0; i < z; ++i)
		{
			my_file1 << Arr[i] << endl;
		}
		my_file1.close();
		s = 0, z = 0, j = 0, tmp = "0";
		my_file3.open("Shirt_no.txt", ios::in);

		while (my_file3 >> tmp)
		{
			++z;
		}
		my_file3.close();

		Arr1 = new string[z];
		my_file3.open("Shirt_no.txt", ios::in);
		while (my_file3 >> Arr1[j])
		{
			++j;

		}
		my_file3.close();
		my_file3.open("Shirt_no.txt", ios::out);
		cout << "Enter the Shirt No: ";
		cin >> Arr1[x];
		for (int i = 0; i < z; ++i)
		{
			my_file3 << Arr1[i] << endl;
		}
		my_file3.close();
		s = 0, z = 0, j = 0, tmp = "0";
		my_file4.open("Averages.txt", ios::in);
		while (my_file4 >> tmp)
		{
			++z;
		}
		my_file4.close();
		Arr2 = new string[z];
		my_file4.open("Averages.txt", ios::in);
		while (my_file4 >> Arr2[j])
		{
			++j;

		}
		my_file4.close();
		my_file4.open("Averages.txt", ios::out);
		cout << "Enter the Player Average: ";
		cin >> Arr2[x];
		for (int i = 0; i < z; ++i)
		{
			my_file4 << Arr2[i] << endl;
		}
		my_file4.close();

		s = 0, z = 0, j = 0, tmp = "0";
		my_file5.open("player_Total_runs.txt", ios::in);
		while (my_file5 >> tmp)
		{
			++z;
		}
		my_file5.close();

		Arr3 = new string[z];
		my_file5.open("player_Total_runs.txt", ios::in);
		while (my_file5 >> Arr3[j])
		{
			++j;

		}
		my_file5.close();
		my_file5.open("player_Total_runs.txt", ios::out);
		cout << "Enter the Player Total Runs: ";
		cin >> Arr3[x];
		for (int i = 0; i < z; ++i)
		{
			my_file5 << Arr3[i] << endl;
		}
		my_file5.close();

		s = 0, z = 0, j = 0, tmp = "0";
		my_file6.open("Total_Match_player.txt", ios::in);
		while (my_file6 >> tmp)
		{
			++z;
		}
		my_file6.close();
		Arr4 = new string[z];
		my_file6.open("Total_Match_player.txt", ios::in);
		while (my_file6 >> Arr4[j])
		{
			j++;
		}
		my_file6.close();
		my_file6.open("Total_Match_player.txt", ios::out);
		cout << "Enter the matches no. that player played :";
		cin >> Arr4[x];
		for (int i = 0; i < z; ++i)
		{
			my_file6 << Arr4[i] << endl;
		}
		my_file6.close();

		s = 0, z = 0, j = 0, tmp = "0";
		my_file7.open("Total_Wicket_Player.txt", ios::in);
		while (my_file7 >> tmp)
		{
			++z;
		}
		my_file7.close();
		Arr5 = new string[z];
		my_file7.open("Total_Wicket_Player.txt", ios::in);
		while (my_file7 >> Arr5[j])
		{
			++j;

		}
		my_file7.close();
		my_file7.open("Total_Wicket_Player.txt", ios::out);
		cout << "Enter the total wickets of player :";
		cin >> Arr5[x];
		for (int i = 0; i < z; ++i)
		{
			my_file7 << Arr5[i] << endl;
		}
		my_file7.close();
	}
}


//*************//
//                                     //
//             DISPLAYE                //     
//                                     //
//         DATA FUNCTION               //
//                                     //
//*************//

void player::displaye_data()
{
	static int c2 = 0;
	string* array11;
	outfile.open("Information.txt", ios::in);

	int cl = 0;
	string tem;
	while (outfile >> tem)
	{
		++cl;
	}
	outfile.close();
	outfile.open("Information.txt", ios::in);
	array11 = new string[cl];
	while (outfile >> array11[c2])
	{
		cout << "_Team " << " Information__" << endl;
		cout << "Team Name is:";
		cout << array11[c2] << endl;
		++c2;

		cout << "Team Ranking in ODI Format is:";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "Team Ranking in T20 Format is:";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "Team Ranking in Test Format is:";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "------------------------------------------------ " << endl;


		cout << "The name of player : ";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "The shirt number : ";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "The average of player : ";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "The total runs of player: ";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "The matches no. that player played : ";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "The total wickets of player  : ";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "Total Matches Won By Team :";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "Total Matches Lost By Team is:";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "Team Captain name is:";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;

		cout << "Team Coach Name is:";
		outfile >> array11[c2];
		cout << array11[c2] << endl;
		++c2;
	}
	outfile.close();

}
