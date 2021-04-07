#pragma once

#include "User.h"
#include "Display.h"
#include "TamplateArray.h"

enum avtomatState
{
	QUIT = 0,
	CRE_LOG,
	W_R_MESS,
};

class Chat
{
	int _id;
	Display _disp;
	Array <class User> _user;
	int _id—urrent;

public:
	Chat();
	~Chat() = default;

	void createUser();
	int logIn();
	int getQuantUsers();
	void readMessage(int id);
	void writeMessage(int id);
	void avtoState();
	int createLogUsers();
	int readWriteMess();
};

