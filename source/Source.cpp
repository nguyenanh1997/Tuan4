#include <ios>
#include <iostream>
#include "sqlite3.h"
#include "sqlite.h"
#include "view.h"
using namespace std;
string kkkk;
string iiii;
sqlite a;
view VIEW;
char q[100];
int main()
{
	do
	{
		cout << "1 Dang nhap" << endl;
		cout << "2 dang ky " << endl;
		cout << "3 thoat" << endl;
		cout << "nhap so tuong ung voi chuc nang can dung" << endl;
		fflush(stdin);
		getline(cin, kkkk);
		if (kkkk == "1")
		{
			if (a.SignIn() == 1)
			{
				do
				{
					cout << "1 Nhan tin" << endl;
					cout << "2 Hien thi tin nhan" << endl;
					cout << "3 Ket ban" << endl;
					cout << "4 Danh sach ban be" << endl;
					cout << "5 Block " << endl;
					cout << "6 xoa ban be" << endl;
					cout << "7 kiem tra loi moi ket ban" << endl;
					cout << "8 dang xuat" << endl;
					cout << "nhap chuc nang" << endl;

					fflush(stdin);
					getline(cin, iiii);

					if (iiii == "1")
					{
						VIEW.SendMessageView(a.ReplyMessageUseName());

					}
					if (iiii == "2")
					{
						a.ShowMessage();
					}
					if (iiii == "3")
					{
						VIEW.AddFriendView(a.AddFriend());
					}
					if (iiii == "4")
					{
						a.ShowListFriend();
					}
					if (iiii == "5")
					{
						VIEW.BlockView(a.BlockFriend());
					}
					if (iiii == "6")
					{
						VIEW.DelFriendView(a.DelFriend());
					}
					if (iiii == "7")
					{
						VIEW.CheckRequestAddFreindView(a.CheckRequestAddFriend());
					}
					if (iiii == "8")
					{
						cout << "dang xuat thanh cong" << endl;
					}
				} while (iiii != "8");
				
			}
		}
		if (kkkk == "2")
		{
			VIEW.logupView( a.SignUp() );
		}
	} while (kkkk != "3");
}
