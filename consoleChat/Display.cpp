#include "Display.h"

Display::Display(const Display& other)
{
    this->_str = other._str;
}

string Display::getLoginInput()
{
    cout << "������� �����: ";
    cin >> this->_str;
    return _str;
}

string Display::getPasswordInput()
{
    cout << "������� ������: ";
    cin >> this->_str;
    return _str;
}

string Display::setName()
{
    cout << "������� ���: ";
    cin >> this->_str;
    return _str;
}

string Display::getMessInput(string name)
{
    cout << "��������� ��� " << name << endl;
    cin.ignore();
    getline(cin, this->_str);
    return _str;
}

bool Display::loginExists()
{
    cout << "����� ����� �����" << endl;
    return false;
}

void Display::wrongLogOrPas()
{
    cout << "������������ ����� ��� ������" << endl;
}

void Display::logIn(string name)
{
    cout << "�� ����� ��� " << name << endl;
}

void Display::noMessage()
{
    cout << "��������� ���" << endl;
}

void Display::noUsers()
{
    cout << "�� ���� ���� � ����" << endl;
}

char Display::creLog()
{
    cout << "������� '1' ����� ������� ������ ������������" << endl;
    cout << "������� '2' ����� ����� ��� ������������ �������������" << endl;
    cout << "������� 'q' ����� ����� �� ����" << endl;
   
    char input;
    auto trueSymbol = false;

    while (!trueSymbol)
    {
        cin >> input;
        if ((input == '1') || (input == '2') || (input == 'q')) trueSymbol = true;
    }
    return input;
}

char Display::registeredUser()
{
    cout << "������� '1' ����� �������� ���������" << endl;
    cout << "������� '2' ����� ��������� ���������" << endl;
    cout << "������� '3' ����� ����� ��� ������ ������������� ��� ������� ������" << endl;
    cout << "������� 'q' ����� ����� �� ����" << endl;

    char input;
    auto trueSymbol = false;

    while (!trueSymbol)
    {
        cin >> input;
        if ((input == '1') || (input == '2') || (input == 'q') || (input == '3')) trueSymbol = true;
    }
    return input;
}


