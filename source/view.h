#pragma once
class view
{
public:
	view();
	~view();
	void loginView(int status);
	void logupView(int status);

	// method friend
	void AddFriendView(int status);
	void CheckRequestAddFreindView(int status);
	void DelFriendView(int status);
	void BlockView(int status);
	void FixInformationFriend(int status); // sua thong tin ban be va gui tin nhan cho nguoi do
	void ShowListFriend();
	// method message
	void ShowMessageView();
	void SendMessageView(int status);
};

