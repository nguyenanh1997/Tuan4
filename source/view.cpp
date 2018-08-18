#include "view.h"
#include <iostream>
using namespace std;
view::view()
{
}


view::~view()
{
}
void view::loginView(int status)
{
	if (status == 0)
	{
		cout << "sai mat khau" << endl;
	}
	if (status == 1)
	{
		cout << "dang nhap thanh cong" << endl;
	}
	if (status == 2)
	{
		cout << "tai khoan khong ton tai \n" << endl;
	}
	
}
void view::logupView(int status)
{
	if (status == 0)
	{
		cout << "tai khoan da ton tai" << endl;
	}
	else
	{
		if (status)
			cout << "dang ky thanh cong " << endl;
		else
			cout << "co loi xay ra trong qua trinh dang ky";
	}
}
void view::AddFriendView(int status)
{
	if (status == 1)
	{
		cout << "them ban thanh cong" << endl;
	}
	if(status == 0)
	{
		cout << "nguoi nay da bi block" << endl;
	}
	if (status == 10)
	{
		cout << "da gui loi moi ket ban roi" << endl;
	}
	if (status == 2)
	{
		cout << "tai khoan nay khong ton tai" << endl;
	}
}
void view::ShowListFriend()
{
	cout << "in ra danh sach ban be thanh cong " << endl;
}
void view::CheckRequestAddFreindView(int status)
{
	if (status == 1)
	{
		cout << " thanh cong roi " << endl;
	}
	else
	{
		cout << " khong thanh cong" << endl;
	}
}
void view::DelFriendView(int status)
{
	if (status == 1)
	{
		cout << " thanh cong roi nhe" << endl;
	}
	if (status == 0)
	{
		cout << " khong co trong danh sach ban be" << endl;
	}
}
void view::BlockView(int status)
{
	if (status == 0)
	{
		cout << " tai khoan ban muon block khong ton tai" << endl;
	}
	if (status == 1)
	{
		cout << "block thanh cong roi" << endl;
	}
}
void view::SendMessageView(int status)
{
	if (status == 1)
	{
		cout << " thanh cong roi nhe" << endl;
	}
	else
		cout << " khong thanh cong nhe" << endl;
}