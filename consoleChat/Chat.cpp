#include "Chat.h"

Chat::Chat()
{
	this->_id = 0;
	this->_idСurrent = 0;
}

void Chat::createUser()
{
	auto login = _disp.getLoginInput();
	auto exists = false;

	if (_user.getLength())
	{
		while (!exists)
		{			
			for (auto i = 0; i < _user.getLength(); i++)
			{
				if (login == _user[i].getLogin())
				{
					exists = _disp.loginExists();
					login = _disp.getLoginInput();
					break;
				}
				else
				{
					exists = true;
				}
			}
		}
	}

	auto password = _disp.getPasswordInput();
	auto name = _disp.setName();
	this->_id++;
	_user.insertAtEnd(User(login, password, name, this->_id));
}

int Chat::logIn()
{
	auto login = _disp.getLoginInput();
	auto password = _disp.getPasswordInput();

	for (auto i = 0; i < _user.getLength(); i++)
	{
		if (_user[i].verifLogin(login))
		{
			if (_user[i].verifPassword(password))
			{
				_disp.logIn(_user[i].getName());
				return _user[i].getId();
			}
			else
			{
				_disp.wrongLogOrPas();
				return 0;
			}
		}
	}
	_disp.wrongLogOrPas();
	return 0;
}

int Chat::getQuantUsers()
{
	return _user.getLength();
}

void Chat::readMessage(int id)
{
	auto quantMess = _user[id].getQuantityMessage();
	if (quantMess == 0)
	{
		_disp.noMessage();
		return;
	}
	else if (quantMess > 10)
	{
		for (auto i = quantMess - 10; i < quantMess; i++)
		{
			cout << "сообщение от " << _user[id].readNameSender(i) << endl;
			cout << _user[id].readMessage(i) << endl;
			cout << endl;
		}
		return;
	}
	else
	{
		for (auto i = 0; i < quantMess; i++)
		{
			cout << "сообщение от " << _user[id].readNameSender(i) << endl;
			cout << _user[id].readMessage(i) << endl;
			cout << endl;
		}
		return;
	}
}

void Chat::writeMessage(int id)
{
	auto quantUsers = getQuantUsers();
	string name;

	if (quantUsers > 1)
	{
		cout << "Введите номер пользователя которому хотите отправить сообщение или 'z', чтобы отправить всем" << endl;
		for (auto i = 0; i < quantUsers; i++)
		{
			if (_user[i].getId() == id)
			{
				name = _user[i].getName();
			}
			else
			{
				cout << i << " : " << _user[i].getName() << endl;
			}
		}

		char number;
		auto trueSymbol = false;

		while (!trueSymbol)
		{
			cin >> number;
			if (number == 'z')
			{
				auto mess = _disp.getMessInput("Всех");
				for (auto i = 0; i < quantUsers; i++)
				{
					if (_user[i].getId() == id) break;
					_user[i].writeMessage(id, name, mess);
					trueSymbol = true;
				}
			}
			else
			{
				int num = number - '0';
				if ((0 <= num) && (num < quantUsers))
				{
					auto mess = _disp.getMessInput(_user[num].getName());
					_user[num].writeMessage(id, name, mess);
					trueSymbol = true;
				}
			}
		}
	}
	else
	{
		_disp.noUsers();
	}
}

void Chat::avtoState()
{
	int input = createLogUsers();
	bool begin = true;

	while (begin)
	{
		if (input == CRE_LOG)
		{
			input = createLogUsers();
		}
		else if(input == W_R_MESS)
		{
			input = readWriteMess();
		}
		else begin = false;
	}
}

int Chat::createLogUsers()
{
	auto input = _disp.creLog();
	if (input == '1')
	{
		createUser();
	}
	else if (input == '2')
	{
		this->_idСurrent = logIn();
		if (_idСurrent) return W_R_MESS;
	}
	else if (input == 'q') return QUIT;
	return CRE_LOG;
}

int Chat::readWriteMess()
{
	auto input = _disp.registeredUser();
	if (input == '1')
	{
		writeMessage(this->_idСurrent);
		return W_R_MESS;
	}
	else if (input == '2')
	{
		readMessage(this->_idСurrent - 1);
		return W_R_MESS;
	}
	else if (input == '3')
	{
		return CRE_LOG;
	}
	else if (input == 'q') return QUIT;
	else return W_R_MESS;
}
