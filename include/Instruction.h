#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Register.h"
#include <string>

class Instruction
{
    public:
        Instruction(Register* reg, std::string opera, int number, Register* conditionRegister, std::string conditionOperator, int conditionNumber);
        Register* getRegister();
        const std::string getOperator();
        const int getNumber();
        Register* getConditionRegister();
        const std::string getConditionOperator();
        const int getConditionNumber();
        const void display();

    protected:

    private:
        Register* m_register;
        std::string m_operator;
        int m_number;
        Register* m_conditionRegister;
        std::string m_conditionOperator;
        int m_conditionNumber;
};

#endif // INSTRUCTION_H
