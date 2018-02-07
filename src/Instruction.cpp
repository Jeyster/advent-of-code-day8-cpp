#include "Instruction.h"

using namespace std;

Instruction::Instruction(Register reg, string opera, int number, Register conditionRegister, bool condition) : m_register(reg), m_operator(opera), m_number(number), m_conditionRegister(conditionRegister), m_condition(condition){}
