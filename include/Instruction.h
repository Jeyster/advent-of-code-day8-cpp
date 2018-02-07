#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Register.h"
#include <string>

class Instruction
{
    public:
        Instruction(Register register, std::string opera, int number, Register conditionRegister, bool condition);

    protected:

    private:
        Register m_register;
        std::string m_operator;
        int m_number;
        Register m_conditionRegister;
        bool m_condition;
};

#endif // INSTRUCTION_H
