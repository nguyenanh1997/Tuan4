#include "sqlite.h"
#include "sqlite3.h"
#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

sqlite::sqlite() // Connect to DataBase
{
	ConnectSQL();
}

sqlite::~sqlite() // close database
{
	sqlite3_close(DB);
}

void sqlite::ConnectSQL() 
{
	int CheckConnect;
	CheckConnect = sqlite3_open("AppChat.db", &DB);
	if (CheckConnect)
	{
		cout << "khong ket noi duoc voi CSDL";
	}
	else
	{
		cout << "ket noi thanh cong" << endl;

	}

}
void sqlite::CreateTable() // create table in database
{
	cout << "Creating MyTable ..." << endl;
	const char *sqlCreateTable = "CREATE TABLE user (id INTEGER PRIMARY KEY, username STRING, password STRING);";
	rc = sqlite3_exec(DB, sqlCreateTable, NULL, NULL, &error);
	if (rc)
	{
		cerr << "Error executing SQLite3 statement: " << sqlite3_errmsg(DB) << endl << endl;
		sqlite3_free(error);
	}
	else
	{
		cout << "Created MyTable." << endl << endl;
	}
}
int sqlite::InsertOrDelOrUpdate(const char *query) // insert delete or update data to table
{
	rc = sqlite3_exec(DB, query, NULL, NULL, &error);
	if (rc)
	{
		cerr << "Error executing SQLite3 statement: " << sqlite3_errmsg(DB) << endl << endl;
		sqlite3_free(error);
		return 0; 
	}
	else
	{
		cout << "Inserted a value into DataBase." << endl << endl;
		return 1;
	}
}
int sqlite::SelectData1(const char *query, char *a) // ham nay bi hong roi chuyen sang dung ham selectdata4
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, 16);
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW )
	{
		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt, 0));
		return 1;
	}
	return 0;
}
int sqlite::SelectData1(const char *query, char *a, char *b)
{
	sqlite3_prepare_v2(DB, query, -1, &stmt1, NULL);
	sqlite3_bind_int(stmt1, 1, 16);
	if((rc1 = sqlite3_step(stmt1)) == SQLITE_ROW)
	{
		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt1, 0));
		strcpy_s(b, 100, (char*)sqlite3_column_text(stmt1, 1));
		cout << "Nguoi gui: " << b << endl;
		cout << "Noi Dung : " << a << endl;	
	}
	return 0;
}
int sqlite::PrintIdUsernameFrien(const char *query, char *a, char *b)
{
	sqlite3_prepare_v2(DB, query, -1, &stmt1, NULL);
	sqlite3_bind_int(stmt1, 1, 16);
	while((rc1 = sqlite3_step(stmt1)) == SQLITE_ROW)
	{
		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt1, 0));
		strcpy_s(b, 100, (char*)sqlite3_column_text(stmt1, 1));
		cout << "Id: " << a << endl;
		cout << "Ten: " << b << endl;
	}
	return 0;
}
int sqlite::SelectData(const char *query, char *a, char *b, char *c)
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, 16);
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt, 0));
		strcpy_s(b, 100, (char*)sqlite3_column_text(stmt, 1));
		strcpy_s(c, 100, (char*)sqlite3_column_text(stmt, 2));
	}
	return 0;
}
int sqlite::SelectDataForSend(const char *query, char *a, char *b, char *c)
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, 16);
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt, 0));
		strcpy_s(b, 100, (char*)sqlite3_column_text(stmt, 1));
		strcpy_s(c, 100, (char*)sqlite3_column_text(stmt, 2));
		cout << "STT: " << a << endl;
		cout << "Nguoi nhan: " <<  b << endl;
		cout << "Noi dung: " << c << endl;
	}
	return 1;
}
int sqlite::SelectDataForRevice(const char *query, char *a, char *b, char *c, char *d)
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, 16);
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt, 0));
		strcpy_s(b, 100, (char*)sqlite3_column_text(stmt, 1));
		strcpy_s(c, 100, (char*)sqlite3_column_text(stmt, 2));
		strcpy_s(d, 100, (char*)sqlite3_column_text(stmt, 3));
		cout << "STT: " << a << endl;
		if (strcmp(d, "2") == 0)
		{
			cout << " chua doc" << endl;
		}
		else
			cout << " da doc" << endl;
		cout << "Nguoi gui: " << b << endl;
		cout << "Noi dung: " << c << endl;
	}
	return 1;
}
int sqlite::SelectData4(const char *query, char *a)
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 2, 1000);
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{	
		
		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt, 0));
		
		cout << a << endl;
		return 1;
	}
	return 0;
}
int sqlite::SelectData8(const char *query, char *a)
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 2, 1000);
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{

		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt, 0));

		cout << a << endl;
	}
	return 0;
}
int sqlite::SelectData5(const char *query, char *a)
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 2, 1000);
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{

		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt, 0));

		cout << a << endl;
	}
	return 1;
}
int sqlite::CheckSignUp(const char *query, char *ReQuery) // kiem tra tai khoan co ton tai hay khong
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, 16);                                                                
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{   
		return 1;
	}
	return 0;
}
int sqlite::checkSignIn(const char *query, char *ReQuery, char *ReQuery1, char *UsernameCheck, char *password) // chuc nang dang nhap
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, 16);
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		strcpy_s(ReQuery, 100, (char*)sqlite3_column_text(stmt, 0)); // username 
		if (strcmp(UsernameCheck, ReQuery) == 0) // so sanh xem tai khoan nay co ton tai khong
		{
			strcpy_s(ReQuery1, 100, (char*)sqlite3_column_text(stmt, 1));
			if (strcmp(ReQuery1, password) == 0)
				return 1;// da khop voi mat khau trong DB
			else
				return 0; // sai mat khau roi
		}
		
		
	}
	return 2;
}
int sqlite::CheckBlock(const char *query, char *ReQuery, char *ReQuery1, char *ReQuery2, char *UsernameCheck, char *UsernameFriendCheck) // kiem tra xem co bi block trong danh sach ban be khong
{
	sqlite3_prepare_v2(DB, query, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, 16);
	while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		
			strcpy_s(ReQuery, 100, (char*)sqlite3_column_text(stmt, 0)); // username Ob
			strcpy_s(ReQuery1, 100, (char*)sqlite3_column_text(stmt, 1)); // username of friend 
			strcpy_s(ReQuery2, 100, (char*)sqlite3_column_text(stmt, 2)); // statuc frien

			if ( strcmp( ReQuery, UsernameCheck) == 0) // checking Username Ob
			{
				if (strcmp(ReQuery1, UsernameFriendCheck) == 0) // Checking Username Of Friend
				{
					if (strcmp(ReQuery2, "0") == 0) // checking status
					{
						return 0; // da block
					}
					if (strcmp(ReQuery2, "1") == 0) // checking status
					{
						return 1; // da ket ban roi
					}
					if (strcmp(ReQuery2, "2") == 0) // checking status
					{
						return 1; // da gui loi moi ket ban roi
					}
				}
					
			}
	}
	return 2; // tai khoan khong co trong danh sach 
}
int sqlite::CheckRequestAddFriend()
{
	char requery1[100], requery2[100], requery3[100];
	string Fname;
	sql = "select usernameofob from friend where usernameoffriend = '" + string(Object) + "' and statusfriend = 2 ";
	sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
	strcpy(sql_query, sql.c_str());
	int check = SelectData5(sql_query, q1);
	if ( check )// kiem tra xem co thang nao gui loi moi ket ban khong
	{

		cout << "Nhap ten nguoi ban muon dong y: " << endl;
		fflush(stdin);
		cin >> q1; // nhap co hoac khong
		cin.get();

		Fname = string(q1);

		sql = "select id from friend where statusfriend = 2 and usernameoffriend = '" + string(q1) + "' and usrenameofob = '" + string(Object) + "' "; // kiem tra xem da co trong danh sach ban be chua
		sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());
		
		if ( SelectData1(sql_query, requery1) ) // neu da co trong table friend roi thi update trang thai cua ca 2
		{
			sql = "update friend set statusfriend = 1 where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(q1) + "' "; // sql de cap nhap statusfriend trong bang friend
			sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
			strcpy(sql_query, sql.c_str());

			if (InsertOrDelOrUpdate(sql_query))
			{
				sql = "update friend set statusfriend = 1 where usernameofob = '" + string(q1) + "' and usernameoffriend = '" + string(Object) + "' "; // sql de cap nhap statusfriend trong bang friend
				sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
				strcpy(sql_query, sql.c_str());

				InsertOrDelOrUpdate(sql_query); // update statusfriend cua thang dua ra yeu cau thanh cong roi nhe
				return 1;
			}
		}
		else // neu chua co trong bang friend thi ket ban thoi
		{
			sql = "select id from friend where usernameofob = '" + string(q1) + "' and usernameoffriend = '" + string(Object) + "' "; // sql de cap nhap statusfriend trong bang friend
			sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
			strcpy(sql_query, sql.c_str());

			if (SelectData1(sql_query, requery1))
			{
				AddFriend( q1); // ket ban nhu binh thuong thoi

				sql = "update friend set statusfriend = 1 where usernameofob = '" + Fname + "' and usernameoffriend = '" + string(Object) + "' "; // sql de cap nhap statusfriend trong bang friend
				sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
				strcpy(sql_query, sql.c_str());

				InsertOrDelOrUpdate(sql_query); // update statusfriend cua thang dua ra yeu cau thanh cong roi nhe
				return 1;
			}
		}
	}
}
int sqlite::AddFriend(char *namefriend )
{
	string sql, place, birthday, sex, usernameofob, usernameoffriend;
	char *sql_query;
	char requery1[100], requery2[100], requery3[100];
	int check;

	sql = "select * from user where username ='" + string(namefriend) + "' ";
	sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
	strcpy(sql_query, sql.c_str());
	
	if ( strcmp(Object, namefriend) != 0 )
	{
		if ( CheckSignUp(sql_query,NULL) ) // neu tai khoan da ton tai thi tiep tuc
		{
			sql = "select usernameofob, usernameoffriend, statusfriend from friend";
			sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
			strcpy(sql_query, sql.c_str());

			check = CheckBlock(sql_query, requery1, requery2, requery3, Object, namefriend); // kiem tra xem minh da block no chua 
			if ( check == 2 ) // neu minh chua block hoac chua ket ban thi lai tiep tuc
			{
				
				sql = "select statusfriend from friend where usernameofob = '"+ string(namefriend)+ "' and usernameoffriend = '" +string(Object) + "' " ;
				sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
				strcpy(sql_query, sql.c_str());
				SelectData1(sql_query, q1);
				if ( strcmp(q1,"0") != 0) // kiem tra xem no da block minh chua neu chua thi tiep tuc 
				{
					sql = "select GioiTinh, NgaySinh, NoiO from user where username = '" + string(namefriend) + "' ";
					sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
					strcpy(sql_query, sql.c_str());

					SelectData(sql_query, requery1, requery2, requery3);// lay place, sex, birthday trong bang user

					// convert sang kieu string
					sex = string(requery1);
					birthday = string(requery2);
					place = string(requery3);
					usernameofob = string(Object);
					usernameoffriend = string(namefriend);

					// ghep chuoi
					sql = "insert into friend( usernameofob, usernameoffriend, statusfriend, place, birthday, sex) values('" + usernameofob + "','" + usernameoffriend + "',2,'" + place + "','" + birthday + "','" + sex + "') ";
					sql_query = new char[sql.length() + 1];  // convert sql sang char* de query
					strcpy(sql_query, sql.c_str());

					if (InsertOrDelOrUpdate(sql_query)) // neu them vao bang thanh cong thi return ve 1 
					{
						return 1; // da them ban thanh cong
					}
				}
			}
			if (check == 1)
				return 10; // da ket ban roi
			if (check == 0)
				return 0; // bi block cmnr 
		}
		else
			return 2; // tai khoan friend deo ton tai
	}
}
int sqlite::AddFriend()
{
	string fname;
	
	cout << "nhap ten nguoi ban muon ket ban : " << endl;
	fflush(stdin);
	getline(cin, fname);

	namehhriend = new char[fname.length() + 1];  // convert sql sang char* de query
	strcpy(namefriend, fname.c_str());

	return this->AddFriend(namefriend);
}
int sqlite::ShowListFriendPlace(const char *query, char *a)
{
	char q1[100];
	sqlite3_prepare_v2(DB, query, -1, &stmt1, NULL);
	sqlite3_bind_int(stmt1, 1, 16);
	while ((rc1 = sqlite3_step(stmt1)) == SQLITE_ROW)
	{
		strcpy_s(a, 100, (char*)sqlite3_column_text(stmt1, 0));

		cout << a << endl;

		sql = "select usernameoffriend from friend where place = '" + string(a) + "' and usernameofob = '"+ string(Object) +"' and statusfriend = 1 ";
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());
		
		SelectData8(sql_query, q1);
	}
	
	return 1;
}
void sqlite::ShowListFriendUseTime() // 
{	
	sql = "select usernameoffriend from friend where statusfriend = 1 and usernameofob = '" + string(Object) + "' order by timecontact desc";
	sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
	strcpy(sql_query, sql.c_str());
	SelectData5(sql_query, q1);
}
void sqlite::ShowListFriend()
{
	string check;
	ShowListFriendUseTime();
	int check1 = _getch();
	if ( check1 == 3)
	{
		char q1[100];
		sql = "select distinct place from friend where statusfriend = 1 and usernameofob = '" + string(Object) + "'";
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());

		ShowListFriendPlace(sql_query, q1);
	}
	cout << "ban co muon sua thong tin cua ai khong ?(1 || 0 )" << endl;
	getline(cin, check);
	if (check == "1")
	{
		 FixInFormationFriend();
	}
}
int sqlite::DelFriend()
{
	string sql;
	char *sql_query, q1[100];

	cout << "nhap ten nguoi ban muon block" << endl;
	fflush(stdin);
	gets_s(namefriend);
	cin.get();

	sql = "select id from friend where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(namefriend) + "' ";
	sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
	strcpy(sql_query, sql.c_str());

	if (SelectData1(sql_query, q1) == 1) // kiem tra xem co ton tai trong danh sach ban be hay khong
	{
		sql = "delete from friend where usernameofob ='" + string(Object) + "' and usernameoffriend = '" + string(namefriend) + "'";

		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());
		InsertOrDelOrUpdate(sql_query);
		return 1; // da xoa thanh cong
	}
	else
		return 0; // lam quai co trong danh sach ban be
}
int sqlite::FixInFormationFriend()
{
	string request, place, sex, birthday;
	char Content[100];
	string namefriend;
	cout << "nhap ten nguoi ban muon xem thong tin: " << endl;
	fflush(stdin);
	getline(cin, namefriend);

	sql = "select id from friend where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + namefriend+ "' and statusfriend = 1 ";
	sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
	strcpy(sql_query, sql.c_str());

	if (SelectData1(sql_query, q1) == 1) // kiem tra xem co trong danh sach ban be hay khong
	{
		sql = "select place , sex, birthday from friend where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + namefriend + "' ";
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());

		SelectData(sql_query, q1, q2, q3); // lay thong tin cu ra de xem xet
		cout << q1 << q2 << q3 << endl;

		cout << " An 1 de sua thong tin cua nguoi nay \n An 2 de gui tin nhan " << endl; 
		fflush(stdin);
		cin >> request; // nhap co hoac khong
		cin.get();

		if (request == "1") // sua thong tin
		{
			// lay thong tin
			cout << "nhap noi o: \n";
			fflush(stdin);
			gets_s(q1);
			cin.get();
			cout << "nhap gioi tinh: \n";
			fflush(stdin);
			gets_s(q2);
			cin.get();
			cout << "nhap ngay sinh:";
			fflush(stdin);
			gets_s(q3);
			cin.get();

			sql = "update friend set place ='" + string(q1) + "', sex ='" + string(q2) +"', birthday ='"+ string(q3) +"' where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + namefriend + "'";
			sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
			strcpy(sql_query, sql.c_str());
			cout << sql;
			return InsertOrDelOrUpdate(sql_query);
		}
		if (request == "2") //gui tin nhan
		{
			cout << "nhap noi dung tin nhan" << endl; // lay noi dung tin nhan
			fflush(stdin);
			gets_s(Content);
			cin.get();

			// 2 la da gui, 1 la da doc
			sql = "insert into message(revicer,sender,content,statusmessage,statussender,statusrevicer) values ( '" + namefriend + "' , '" + string(Object) + "' , '" + string(Content) + "' , 2, 1, 1)"; // truy van
			sql_query = new char[sql.length() + 1]; // convert sang *char de query
			strcpy(sql_query, sql.c_str());

			return InsertOrDelOrUpdate(sql_query); // insert data vao table message
		}
	}
	else
		return 0; // lam gi co trong danh sach ban be
}
int sqlite::WatchInFormationFriend() // ham nay khong can dung nua
{
	string request;
	char Content[100];

	cout << "nhap ten nguoi ban muon block" << endl;
	fflush(stdin);
	gets_s(namefriend);
	cin.get();

	sql = "select id from friend where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(namefriend) + "' ";
	sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
	strcpy(sql_query, sql.c_str());

	if (SelectData1(sql_query, q1) == 1) // kiem tra xem co trong danh sach ban be hay khong
	{
		sql = "select place , sex, birthday from friend where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(namefriend) + "' ";
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());

		SelectData(sql_query, q1, q2, q3); // lay thong tin cu ra de xem xet
		cout << q1 << q2 << q3 << endl;

		cout << " ban co gui tin nhan toi nguoi nay? (co / khong )" << endl;
		fflush(stdin);
		cin >> request; // nhap co hoac khong
		cin.get();
		if (request == "co" || request == "Co" || request == "CO" || request == "cO") // xac nhan yeu cau nguoi dung
		{
			cout << "nhap noi dung tin nhan" << endl; // lay noi dung tin nhan
			fflush(stdin);
			gets_s(Content);
			cin.get();

			// 2 la da gui, 1 la da doc
			sql = "insert into message(revicer,sender,content,statusmessage,statussender,statusrevicer) values ( '" + string(namefriend) + "' , '" + string(Object) + "' , '" + string(Content) + "' , 2, 1, 1)"; // truy van
			sql_query = new char[sql.length() + 1]; // convert sang *char de query
			strcpy(sql_query, sql.c_str());

			return InsertOrDelOrUpdate(sql_query); // insert data vao table message
		}
	}
}
int sqlite::BlockFriend()  // chan 1 nguoi nao do
{
	string request, namefriend;
	char q1[100];

	cout << "nhap ten nguoi ban muon block" << endl;
	fflush(stdin);
	getline(cin, namefriend);

	cout << "ban chac chan muon block nguoi nay? (co || khong)" << endl;
	fflush(stdin);
	getline(cin, request);
	if (request == "co" || request == "Co" || request == "CO" || request == "cO") // xac nhan yeu cau nguoi dung
	{
		sql = "select id from friend where usernameoffriend = '" + string(namefriend) + "' and usernameofob = '" + string(Object) + "' ";
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());

		if ( SelectData1(sql_query, q1) ) // kiem tra xem da ket ban chua
		{
			sql = "update friend set statusfriend = 0 where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(namefriend) + "'";
			sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
			strcpy(sql_query, sql.c_str());

			InsertOrDelOrUpdate(sql_query); // update vao o trong friend
			return 1;
		}
		else
		{
			sql = "select id from user where username = '" + string(namefriend) + "' ";
			sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
			strcpy(sql_query, sql.c_str());

			if( CheckSignUp(sql_query,NULL) )
			{ 
				sql = "insert into friend(usernameofob, usernameoffriend, statusfriend) values('" + string(Object) + "' , '" + string(namefriend) + "' ,  0)";
				sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
				strcpy(sql_query, sql.c_str());

				InsertOrDelOrUpdate(sql_query);
				return 1;
			}
			else return 0; // tai khoan khong ton tai
			
		}
	}


}
int sqlite::SignUp()
{
	char username[100], password[100], hoten[100], gioitinh[100], noio[100], ngaysinh[100];
	cout << "nhap usename" << endl;
	fflush(stdin);
	gets_s(username);
	cin.get();
	cout << "nhap password" << endl;
	fflush(stdin);
	gets_s(password);
	cin.get();
	cout << "nhap ho ten" << endl;
	fflush(stdin);
	gets_s(hoten);
	cin.get();
	cout << "nhap gioi tinh" << endl;
	fflush(stdin);
	gets_s(gioitinh);
	cin.get();
	cout << "nhap noi o " << endl;
	fflush(stdin);
	gets_s(noio);
	cin.get();
	cout << "nhap ngay sinh " << endl;
	fflush(stdin);
	gets_s(ngaysinh);
	cin.get();

	// kiem tra xem username da ton tai chua
	sql = "select id from user where username = '" + (string)username + "' ";
	sql_query = new char[sql.length() + 1];
	strcpy(sql_query, sql.c_str());

	if (CheckSignUp(sql_query, NULL)) // kiem tra xem username da ton tai chua
	{
		return 0; // da ton tai roi dang ky lam gi nua
	}
	else
	{
		sql = "insert into user(username,password,hoten,gioitinh,noio,ngaysinh) values('" + string(username) + "' , '" + string(password) + "' , '" + string(hoten) + "','" + string(gioitinh) + "','" + string(noio) + "','" + string(ngaysinh) + "' ); ";
		sql_query = new char[sql.length() + 1];
		strcpy(sql_query, sql.c_str());
		
		return InsertOrDelOrUpdate(sql_query);
	}
	
}
int sqlite::SignIn()
{
	char username[100], password[100];
	cout << "nhap usename" << endl;
	fflush(stdin);
	gets_s(username);
	cin.get();
	cout << "nhap password" << endl;
	fflush(stdin);
	gets_s(password);
	cin.get();

	sql = "select id from user where username = '" + (string)username + "' ";
	sql_query = new char[sql.length() + 1];
	strcpy(sql_query, sql.c_str());

	if (CheckSignUp(sql_query, NULL)) // kiem tra xem username da ton tai chua
	{
		sql = "select id from user where password = '" + (string)password + "' ";
		sql_query = new char[sql.length() + 1];
		strcpy(sql_query, sql.c_str());

		if (CheckSignUp(sql_query, NULL)) // kiem tra xem username da ton tai chua
		{
			cout << " dang nhap thanh cong " << endl;
			strcpy( Object, username);
			return 1;
		}
		else
		{
			cout << "sai mat khau roi" << endl;
			return 0;
		}
	}
	else
	{
		cout << "tai khoan ko ton tai";
		return 2;
	}
}
int sqlite::SendMessage(char *To) 
{
	char Content[100];

	cout << "nhap noi dung tin nhan" << endl; // lay noi dung tin nhan
	fflush(stdin);
	gets_s(Content);
	cin.get();

	time_t timecontact = time(0);
	time_UCT = ctime(&timecontact);
	time_second = timecontact;

	sql = "update friend set timecontact = '" + to_string(time_second) + "' where usernameofob = '" + string(To) + "' and usernameoffriend = '" + string(Object) + "' ";
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	InsertOrDelOrUpdate(sql_query); // update data vao table message

	sql = "update friend set timecontact = '" + to_string(time_second) + "' where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(To) + "' ";
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	InsertOrDelOrUpdate(sql_query); // update data vao table message

	// 2 la da gui, 1 la da doc
	sql = "insert into message(revicer,sender,content,statusmessage,statussender,statusrevicer,time_uct) values ( '" + string(To) + "' , '" + string(Object) + "' , '" + string(Content) + "' , 2, 1, 1, '"+string(time_UCT)+"')"; // truy van
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	return InsertOrDelOrUpdate(sql_query); // insert data vao table message
}
int sqlite::SendMessage( char *To, char *Content) // cai nay de danh cho tra loi tin nhan khi xem chi tiet 1 tin nhan nao do 
{
	time_t timecontact = time(0);
	time_UCT = ctime(&timecontact);
	time_second = timecontact;

	sql = "update friend set timecontact = '" + to_string(time_second) + "' where usernameofob = '" + string(To) + "' and usernameoffriend = '" + string(Object) + "' ";
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	InsertOrDelOrUpdate(sql_query); // update data vao table message

	sql = "update friend set timecontact = '" + to_string(time_second) + "' where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(To) + "' ";
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	InsertOrDelOrUpdate(sql_query); // update data vao table message

	// 2 la da gui, 1 la da doc
	sql = "insert into message(revicer,sender,content,statusmessage,statussender,statusrevicer,time_uct) values ( '" + string(To) + "' , '" + string(Object) + "' , '" + string(Content) + "' , 2, 1, 1, '"+string(time_UCT)+"')"; // truy van
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	return InsertOrDelOrUpdate(sql_query); // insert data vao table message
}
int sqlite::ReplyMessageUseName() // reply tin nhan theo cach 1 
{
	int check;
	char Content[100], nameFriend[100], TimeSend[100];
	string friendornot;
	cout << "Gui toi : " << endl; // lay ten cua nguoi gui
	check = _getch();
	if (check == 12)
	{
		sql = "select id, usernameoffriend from friend where usernameofob = '" + string(Object) + "' ";
		sql_query = new char[sql.length() + 1]; // convert sang *char de query
		strcpy(sql_query, sql.c_str());

		PrintIdUsernameFrien(sql_query,q1,q2);

		ReplyMessageUseId();
	}
	else
	{
		fflush(stdin);
		gets_s(nameFriend);
		cin.get();

		if (strcmp(Object, nameFriend) == 0)
		{
			return 3; // tu gui tin nhan cho ban than 
		}
		sql = "select id from user where username ='" + string(nameFriend) + "'";
		sql_query = new char[sql.length() + 1]; // convert sang *char de query
		strcpy(sql_query, sql.c_str());

		if (CheckSignUp(sql_query, NULL)) // kiem tra xem username cua friend co ton tai hay khong
		{
			sql = "select id from friend where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(nameFriend) + "' and statusfriend = 0 "; // sql truy van ra id cua 1 moi quan he
			sql_query = new char[sql.length() + 1]; // convert sang *char de query
			strcpy(sql_query, sql.c_str());

			if (SelectData1(sql_query, q1))
			{
				return 2; // block roi nhe
			}
			else
			{

				sql = "select id from friend where usernameofob = '" + string(nameFriend) + "' and usernameoffriend = '" + string(Object) + "' and statusfriend = 0 "; // sql truy van ra id cua 1 moi quan he
				sql_query = new char[sql.length() + 1]; // convert sang *char de query
				strcpy(sql_query, sql.c_str());

				if (SelectData1(sql_query, q1))
				{
					return 2; // block roi nhe
				}
				else
				{
					cout << " nhap noi dung vao day nao: " << endl;
					fflush(stdin);
					gets_s(Content);
					cin.get();

					sql = "select id from friend where usernameofob = '" + string(Object) + "'  and usernameoffriend = '" + string(nameFriend) + "' ";
					sql_query = new char[sql.length() + 1]; // convert sang *char de query
					strcpy(sql_query, sql.c_str());
					time_t timecontact = time(0);
					time_UCT = ctime(&timecontact);
					time_second = timecontact;


					if (SelectData1(sql_query, q3))
					{
						friendornot = "1";
						sql = "update friend set timecontact = '" + to_string(time_second) + "' where usernameofob = '" + string(nameFriend) + "' and usernameoffriend = '" + string(Object) + "' ";
						sql_query = new char[sql.length() + 1]; // convert sang *char de query
						strcpy(sql_query, sql.c_str());

						InsertOrDelOrUpdate(sql_query); // insert data vao table message

						sql = "update friend set timecontact = '" + to_string(time_second) + "' where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(nameFriend) + "' ";
						sql_query = new char[sql.length() + 1]; // convert sang *char de query
						strcpy(sql_query, sql.c_str());

						InsertOrDelOrUpdate(sql_query); // insert data vao table message
					}
					else friendornot = "0";
					sql = "insert into message(revicer,sender,content,statusmessage, statussender,statusrevicer, time_uct) values ( '" + string(nameFriend) + "' , '" + string(Object) + "' , '" + string(Content) + "' , 2, 1, 1, '" + string(time_UCT) + "')"; // truy van
					sql_query = new char[sql.length() + 1]; // convert sang *char de query 
					strcpy(sql_query, sql.c_str());

					return InsertOrDelOrUpdate(sql_query); // insert data vao table message
				}
			}
		}
		else return 0; // tai khoan lam gi ton tai
	}
}
int sqlite::ShowMessageSend()
{
	char q1[100], q2[100], q3[100];
	string request;
	
	sql = "select id , revicer, content from message where sender ='" + string(Object) + "' and statussender = 1 "; // sql query de dua ra nhung tin nhan da gui
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	// in ra list nao 
	SelectDataForSend(sql_query, q1, q2, q3);
	
	
	cout << " An 1 de doc chi tiet 1 tin nhan \n An 2 de xoa tin nhan \n 3 de tro lai danh sach tin nhan" << endl;
	
	fflush(stdin);
	getline(cin, request);
	if (request == "1") // xac nhan yeu cau nguoi dung
	{
		ReadMessageSend();
		return 1;
	}
	if (request == "2")
	{
		DelMessageSend();
		return 1;
	}
	if (request == "3")
	{
		return 0;
	}

	cout << "An Ctrl + N de toi tin nhan da nhan" << endl;

	check = NULL;
	fflush(stdin);
	check1 = _getch();
	if (check1 == 14)
	{
		
		ShowMessageRevice();
	}
}
int sqlite::ShowMessageRevice()
{
	char q4[100];
	string request;
	sql = "select id , sender, content, statusmessage from message where revicer ='" + string(Object) + "' and statusrevicer = 1 "; // sql query de dua ra nhung tin nhan da gui
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	// in ra list nao 
	SelectDataForRevice(sql_query, q1, q2, q3, q4);

	cout << "An 1 de doc tin nhan " << endl;
	cout << "An 2 de xoa tin nhan " << endl;
	cout << "An 3 de tro lai danh sach tin nhan";
	
	fflush(stdin);
	getline(cin,request);
	if (request == "1") // xac nhan yeu cau nguoi dung
	{
		ReadMessageRevice();
		return 1;
	}
	if (request == "2")
	{
		DelMessageRevicer();
		return 1;
	}
	if (request == "3")
	{
		return 0;
	}

	cout << "\n Ctrl + N de toi danh sach tin nhan da gui" << endl;
	check = NULL;
	fflush(stdin);
	check = _getch();
	if (check == 14)
	{
		
		ShowMessageSend();
	}
	
}
int sqlite::DelMessageSend()
{
	char q1[100];
	string id;
	cout << "nhap id tin nhan ban muon xoa" << endl; // lay id cua tin nhan ma nguoi dung nhap
	fflush(stdin);
	getline(cin, id);
	
	sql = "select revicer from message where statussender = 1 and id =" + id + " and sender = '" +string(Object) + "' "; // convert 
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	if ( SelectData4(sql_query, q1) ) // kiem tra xem id nay co hop le khong hay ban dang co gang xoa id khong ton tai cung voi sender
	{
		sql = "update message set statussender = 0 where id = '" + id + "'"; // convert 
		sql_query = new char[sql.length() + 1]; // convert sang *char de query
		strcpy(sql_query, sql.c_str());

		cout << "xoa duoc roi" << endl;
		return InsertOrDelOrUpdate(sql_query); // thanh cong roi nhe

	}
	else
	{
		cout << "khong xoa duoc" << endl;
		return 0; // deo thanh cong
	}
}
int sqlite::DelMessageRevicer()
{
	string id;
	cout << "nhap id tin nhan ban muon xoa" << endl; // lay id cua tin nhan ma nguoi dung nhap
	fflush(stdin);
	getline(cin , id);

	sql = "select sender from message where statusrevicer = 1 and id =" +id+ " and revicer = '" + string(Object) + "' "; // convert 
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	if ( SelectData4(sql_query, q1) ) // kiem tra xem id nay co hop le khong hay ban dang co gang xoa id khong ton tai cung voi sender
	{
		sql = "update message set statusrevicer = 0 where id = '" + id + "'"; // convert 
		sql_query = new char[sql.length() + 1]; // convert sang *char de query
		strcpy(sql_query, sql.c_str());

		cout << "xoa duoc roi" << endl;
		return InsertOrDelOrUpdate(sql_query); // thanh cong roi nhe

	}
	else
	{
		cout << "khong thanh cong" << endl;
		return 0; // deo thanh cong
	}
}
int sqlite::ReadMessageRevice() // doc tin nhan da nhan duoc
{
	char id[100];
	int check;
	string request;
	cout << "de nghi nhap stt cua tin nhan ban muon xem" << endl; // lay id muon xem
	fflush(stdin);
	cin >> id;
	cin.get();

	sql = "select sender from message where statusrevicer = 1 and id =" + string(id) + " and revicer = '" + string(Object) + "' "; // lay nguoi gui tin nhan voi id vua nhap ma nguoi nhan la Ob
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	if ( SelectData4(sql_query, q1) ) // kiem tra xem co ton tai hay khong
	{
		sql = "select content, sender from message where  statusrevicer = 1 and revicer = '" + string(Object) + "' and id =" + string(id); // lay noi dung va nguoi gui thu de hien thi cho Ob
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());

		SelectData1(sql_query, q2, q3); // in ra thoi

		sql = "update message set statusmessage = 1 where revicer = '" + string(Object) + "' and id =" + string(id); // update de tin nhan sang da doc
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());
		
		InsertOrDelOrUpdate(sql_query);
		cout << "Bam Ctrl + R de tra loi tin nhan" << endl; // lay id muon xem

		check = _getch();
		if ( check == 1) // xac nhan yeu cau nguoi dung
		{
			return SendMessage(q1);
		}
	}
}
int sqlite::ReadMessageSend() // doc nhung tin nhan minh da gui
{
	char id[100];
	int check;
	string request;
	cout << "de nghi nhap stt cua tin nhan ban muon xem" << endl; // lay id muon xem
	fflush(stdin);
	cin >> id;
	cin.get();

	sql = "select revicer from message where statussender = 1 and id =" + string(id) + " and sender = '" + string(Object) + "' "; // lay nguoi gui tin nhan voi id vua nhap ma nguoi nhan la Ob
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	if (SelectData4(sql_query, q1)) // kiem tra xem co ton tai hay khong
	{
		sql = "select content, revicer from message where  statussender = 1 and sender = '" + string(Object) + "' and id =" + string(id); // lay noi dung va nguoi gui thu de hien thi cho Ob
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());

		SelectData1(sql_query, q2, q3); // in ra thoi

		sql = "update message set statusmessage = 2 where sender = '" + string(Object) + "' and id =" + string(id); // update de tin nhan sang da doc
		sql_query = new char[sql.length() + 1]; // convert sql sang char* de query
		strcpy(sql_query, sql.c_str());

		InsertOrDelOrUpdate(sql_query);

		cout << "Ban co muon gui lai tin nhan nay khong An Ctrl + R de gui lai " << endl; // 

		check = _getch();

		if ( check == 12 ) // xac nhan yeu cau nguoi dung
		{
			return SendMessage( q1, q2);
		}
	}
}
int sqlite::ReplyMessageUseId() // gui tin nhan theo id cua nguoi dung
{
	char id[100];
	cout << "de nghi nhap id ban muon gui tin nhan toi" << endl; // lay id muon xoa
	fflush(stdin);
	gets_s(id);
	cin.get();

	sql = "select usernameoffriend from friend where statusfriend = 1 and id =" + string(id) + " and usernameofob = '" + Object + "'"; // convert
	sql_query = new char[sql.length() + 1]; // convert sang *char de query
	strcpy(sql_query, sql.c_str());

	cout << " Gui toi: ";

	if (SelectData4(sql_query, q1)) // q1 se luu tru usernameoffriend
	{
		sql = "select id from friend where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(q1) + "' and statusfriend = 0 "; // sql truy van ra id cua 1 moi quan he
		sql_query = new char[sql.length() + 1]; // convert sang *char de query
		strcpy(sql_query, sql.c_str());

		if (SelectData1(sql_query, q1))
		{
			return 2; // block roi nhe
		}
		else
		{

			sql = "select id from friend where usernameofob = '" + string(q1) + "' and usernameoffriend = '" + string(Object) + "' and statusfriend = 0 "; // sql truy van ra id cua 1 moi quan he
			sql_query = new char[sql.length() + 1]; // convert sang *char de query
			strcpy(sql_query, sql.c_str());

			if (SelectData1(sql_query, q1))
			{
				return 2; // block roi nhe
			}
			else
			{
				cout << " \n nhap noi dung tin nhan" << endl; // lay noi dung tin nhan
				fflush(stdin);
				gets_s(q2); // noi dung luu vao bien q2
				cin.get();
				// 2 la da gui, 1 la da doc

				time_t timecontact = time(0); // lay thoi gian nao
				time_UCT = ctime(&timecontact);
				time_second = timecontact;

				sql = "update friend set timecontact = '" + to_string(time_second) + "' where usernameofob = '" + string(q1) + "' and usernameoffriend = '" + string(Object) + "' "; // update thoi gian lien lac
				sql_query = new char[sql.length() + 1]; // convert sang *char de query
				strcpy(sql_query, sql.c_str());

				InsertOrDelOrUpdate(sql_query); // insert data vao table message

				sql = "update friend set timecontact = '" + to_string(time_second) + "' where usernameofob = '" + string(Object) + "' and usernameoffriend = '" + string(q1) + "' ";// update thoi gian lien lac
				sql_query = new char[sql.length() + 1]; // convert sang *char de query
				strcpy(sql_query, sql.c_str());

				InsertOrDelOrUpdate(sql_query); // insert time second vao table friend

				sql = "insert into message(revicer,sender,content,statusmessage, statussender,statusrevicer, time_uct) values ( '" + string(q1) + "' , '" + string(Object) + "' , '" + string(q2) + "' , 2, 1, 1, '"+string(time_UCT)+"')"; // truy van
				sql_query = new char[sql.length() + 1]; // convert sang *char de query
				strcpy(sql_query, sql.c_str());

				return InsertOrDelOrUpdate(sql_query); // insert data vao table message
			}
		}
	}
	else return 0; // lam gi co trong danh sach ban be 
	
	

}
void sqlite::ShowMessage()
{
	
	string request;
	do
	{
		cout << " ban muon xem danh sach nao \n An 1 de xem tin nhan nhan \n An 2 de xem tin nhan gui \n An 0 de thoat ra ngoai" << endl;
		fflush(stdin);
		getline(cin, request);
		
		if (request == "1")
		{
			ShowMessageRevice();
		}
		if( request == "2" )
		{
			ShowMessageSend();
		}

	} while (request != "0");
}
