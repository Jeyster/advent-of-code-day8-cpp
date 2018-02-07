#include "Register.h"
#include <iostream>

using namespace std;

Register::Register(string name, int value) : m_name(name), m_value(value){}
Register::Register(string name) : m_name(name), m_value(0){}
Register::Register() : m_name(""), m_value(0){}

const string Register::getName()
{
    return this->m_name;
}

const int Register::getValue()
{
    return this->m_value;
}

const void Register::display()
{
    cout << "Nom du registre : " << this->m_name << endl;
    cout << "Valeur du registre : " << this->m_value << endl << endl;
}
