#pragma once

#include <string>
#include "TamplateArray.h"

using namespace std;

class User
{
	int _id;
	string _login;
	string _password;
	string _name;
	struct mess_t
	{
		int idSender = 0;
		string nameSender = "";
		string message = "";
	};
	Array <struct mess_t> _message;

public:

	User();
	User(string login, string password, string name, int id);
	~User() = default;
	User(const User& other);

	void setId(int id);
	void setName(string name);
	int getId();
	string getLogin();
	string getName();
	bool verifLogin(string login);
	bool verifPassword(string password);
	void writeMessage(int idSender, string name, string message);
	int getQuantityMessage();
	string readMessage(int number);
	int readSender(int number);
	string readNameSender(int number);
};

