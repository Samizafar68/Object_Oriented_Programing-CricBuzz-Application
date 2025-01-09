#pragma once
//*************//
//            PLAYER CLASS             //
//           Abstract class            //
//                                     //
//*************//

class player
{

public:

	string* name;
	int* shirt_no;
	double* average;
	int* total_runs;
	int* matches_played;
	int* total_wickets;
	int size;

public:
	player();
	virtual void add_player() = 0;
	virtual void removal_player() = 0;
	virtual void search_player() = 0;
	virtual void update_player() = 0;
	void displaye_data();


	//*************//
	//           DESTRUCTOR                //
	//                                     //
	//*************//

};
//*************//
//                                     //
//           TEAM CLASSS               //
//                                     //
//*************//


class team :public player
{

public:

	string team_name[20];
	int* Icc_ranking;
	int no__of_players;
	int total_m_won[20];
	int total_m_lost[20];
	string team_captain[20];
	string team_coach[20];
	string Admin_user_name;
	string password;
	int team_count;

public:

	team();
	void add_player();
	void search_player();
	void update_player();
	void removal_player();
	void Display_data1();
	void Update_Captain();
	void Update_Coach();
	void Display_Teams();


	//*************//
	//           DESTRUCTOR                //
	//                                     //
	//*************//

};
//*************//
//                                     //
//           MATCH CLASS               //
//                                     //
//*************//


class match :public team
{
private:

	string* team1;
	string* team2;
	string* date;
	string* venue;
	string* match_type;
	string tornament_name;
	string commentators;
	string umpire;
	string match_status;
	int count_match;

public:

	match();
	void conductMatch();
	void  scheduleMatch();

	void updateWorldRecords(); //**//

	void  updateTeamRanking();
	void Display_Scedule_Matches();
	void Displayupdateworldrecord();
	void  updatePlayerRanking();//**//

	void displayUpcomingMatches();
	void  displayRecentMatches();
	void display_Matches();
};
