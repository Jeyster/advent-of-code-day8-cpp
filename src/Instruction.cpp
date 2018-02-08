#include "Instruction.h"
#include <iostream>

using namespace std;

Instruction::Instruction(Register* reg, string opera, int number, Register* conditionRegister, string conditionOperator, int conditionNumber) : m_register(reg), m_operator(opera), m_number(number), m_conditionRegister(conditionRegister), m_conditionOperator(conditionOperator), m_conditionNumber(conditionNumber) {}

Register* Instruction::getRegister()
{
    return m_register;
}

const string Instruction::getOperator()
{
    return m_operator;
}

const int Instruction::getNumber()
{
    return m_number;
}

Register* Instruction::getConditionRegister()
{
    return m_conditionRegister;
}

const string Instruction::getConditionOperator()
{
    return m_conditionOperator;
}

const int Instruction::getConditionNumber()
{
    return m_conditionNumber;
}

const void Instruction::display()
{
    char opera;
    if(this->m_operator == "inc")
    {
        opera = '+';
    }
    else if(this->m_operator == "dec")
    {
        opera = '-';
    }
    cout << this->m_register->getName() << " " << opera << " " << this->m_number << " si " << this->m_conditionRegister->getName() << " " << this->m_conditionOperator << " " << this->m_conditionNumber << endl;
    cout << endl;
}
