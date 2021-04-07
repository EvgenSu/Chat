#include "Display.h"

Display::Display(const Display& other)
{
    this->_str = other._str;
}

string Display::getLoginInput()
{
    cout << "Введите логин: ";
    cin >> this->_str;
    return _str;
}

string Display::getPasswordInput()
{
    cout << "Введите пароль: ";
    cin >> this->_str;
    return _str;
}

string Display::setName()
{
    cout << "Введите имя: ";
    cin >> this->_str;
    return _str;
}

string Display::getMessInput(string name)
{
    cout << "Сообщение для " << name << endl;
    cin.ignore();
    getline(cin, this->_str);
    return _str;
}

bool Display::loginExists()
{
    cout << "Логин такой занят" << endl;
    return false;
}

void Display::wrongLogOrPas()
{
    cout << "Неправильный логин или пароль" << endl;
}

void Display::logIn(string name)
{
    cout << "Вы вошли под " << name << endl;
}

void Display::noMessage()
{
    cout << "Сообщений нет" << endl;
}

void Display::noUsers()
{
    cout << "Вы пока одни в чате" << endl;
}

char Display::creLog()
{
    cout << "Введите '1' чтобы создать нового пользователя" << endl;
    cout << "Введите '2' чтобы зайти под существующим пользователем" << endl;
    cout << "Введите 'q' чтобы выйти из чата" << endl;
   
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
    cout << "Введите '1' чтобы написать сообщение" << endl;
    cout << "Введите '2' чтобы прочитать сообщение" << endl;
    cout << "Введите '3' чтобы зайти под другим пользователем или создать нового" << endl;
    cout << "Введите 'q' чтобы выйти из чата" << endl;

    char input;
    auto trueSymbol = false;

    while (!trueSymbol)
    {
        cin >> input;
        if ((input == '1') || (input == '2') || (input == 'q') || (input == '3')) trueSymbol = true;
    }
    return input;
}


