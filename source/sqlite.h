#pragma once
#include "sqlite3.h"
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

class sqlite
{
public:
	sqlite();
	~sqlite();
	void ConnectSQL();
	int check1, check;
	sqlite3 *DB;
	sqlite3_stmt *stmt, *stmt1;
	string sql, time_insert;
	char Object[100], namefriend[100];
	char *namehhriend;
	char *error, **results = NULL, *sql_query, q1[100], q2[100], q3[100], *time_UCT;
	int rc, rc1, time_second ,checkview;
	void CreateTable();
	int PrintIdUsernameFrien(const char *query, char *a, char *b);
	int SelectData1(const char *query, char *a);
	int SelectData1(const char *query, char *a, char *b);
	int SelectData(const char *query, char *a, char *b, char *c);
	int SelectDataForSend(const char *query, char *a, char *b, char *c);
	int SelectDataForRevice(const char *query, char *a, char *b, char *c, char *d);
	int SelectData4(const char *query, char *a);
	int SelectData5(const char *query, char *a);
	int SelectData8(const char *query, char *a);
	int CheckBlock(const char *query, char *ReQuery, char *Requery1, char *Requery2, char *UsernameCheck, char *UsernameFriendCheck);
	int CheckSignUp(const char *query, char *ReQuery);
	int checkSignIn(const char *query, char *ReQuery, char *Requery1, char *UsernameCheck, char *password);
	int InsertOrDelOrUpdate(const char *query);

	int ShowListFriendPlace(const char *query, char *a);
	void ShowListFriendUseTime();
	
	//Modul user
	int SignUp();
	int SignIn();

	// modul friend
	int CheckRequestAddFriend();
	int AddFriend(char *namefriend);
	int AddFriend();
	void ShowListFriend();
	int DelFriend();
	int FixInFormationFriend();
	int WatchInFormationFriend( );
	int BlockFriend();

	// modul message 
	int SendMessage( char *To);
	int SendMessage( char *To, char *Content);
	int ReplyMessageUseName();
	int ReplyMessageUseId(); // gui tin nhan theo id nguoi dung
	int ShowMessageSend(); 
	int ShowMessageRevice();
	void ShowMessage();
	int DelMessageSend();
	int DelMessageRevicer();
	int ReadMessageRevice();
	int ReadMessageSend();
	
};

