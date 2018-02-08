#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <string>
#include <vector>
#include "Register.h"
#include "Instruction.h"

std::vector<std::string> importInput(std::string fileName);
void displayVector(std::vector<std::string> tab);
Register* findRegisterPointeurByName(std::vector<Register> &registers, std::string const &name);
Register findRegisterByName(std::vector<Register> &registers, std::string const &name);
void createRegisterFromString(std::vector<Register> &registers, std::string const &input);
void createRegistersFromInput(std::vector<Register> &registers, std::vector<std::string> const &input);
void createInstructionFromString(std::vector<Register> &registers, std::vector<Instruction> &instructions, std::string const &input);
void createInstructionsFromInput(std::vector<Register> &registers, std::vector<Instruction> &instructions, std::vector<std::string> const &input);
bool convertStringIntoBool(Register* conditionReg, std::string const &conditionOperator, int const &conditionNumber);
void executeInstructions(std::vector<Register> &registers, std::vector<Instruction> &instructions);
int getMaxValueFromRegisters(std::vector<Register> &registers);

#endif // TOOLS_H_INCLUDED
