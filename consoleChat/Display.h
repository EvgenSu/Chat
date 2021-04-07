#pragma once

#include <iostream>
#include <string>

using namespace std;

class Display
{
	string _str;

public:
	Display() = default;
	~Display() = default;
	Display(const Display& other);

	string getLoginInput();
	string getPasswordInput();
	string setName();
	string getMessInput(string name);
	bool loginExists();
	void wrongLogOrPas();
	void logIn(string name);
	void noMessage();
	void noUsers();
	char creLog();
	char registeredUser();
};

