#include "User.h"

User::User()
{
	this->_id = 0;
	this->_login = "";
	this->_password = "";
	this->_name = "";
}

User::User(string login, string password, string name, int id)
{
	this->_login = login;
	this->_password = password;
	this->_name = name;
	this->_id = id;
}

User::User(const User& other)
{
	this->_id = other._id;
	this->_login = other._login;
	this->_password = other._password;
	this->_name = other._name;
}

void User::setId(int id)
{
	this->_id = id;
}

void User::setName(string name)
{
	this->_name = name;
}

int User::getId()
{
	return this->_id;
}

string User::getName()
{
	return this->_name;
}

string User::getLogin()
{
	return this->_login;
}

bool User::verifLogin(string login)
{
	return (this->_login == login) ? true : false;
}

bool User::verifPassword(string password)
{
	return (this->_password == password) ? true : false;
}

void User::writeMessage(int idSender, string name, string message)
{
	mess_t messStruct;
	messStruct.idSender = idSender;
	messStruct.nameSender = name;
	messStruct.message = message;
	this->_message.insertAtEnd(messStruct);
}

int User::getQuantityMessage()
{
	return this->_message.getLength();
}

string User::readMessage(int number)
{
	return this->_message[number].message;
}

int User::readSender(int number)
{
	return this->_message[number].idSender;
}

string User::readNameSender(int number)
{
	return this->_message[number].nameSender;
}
