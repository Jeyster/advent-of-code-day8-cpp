#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include <string>
#include <vector>
#include "Register.h"
#include "Instruction.h"

std::vector<std::string> importInput(std::string fileName);
void displayVector(std::vector<std::string> tab);
Register findRegisterByName(std::vector<Register> &registers, std::string const &name);
void createRegisterFromString(std::vector<Register> &registers, std::string const &input);
void createRegistersFromInput(std::vector<Register> &registers, std::vector<std::string> const &input);

#endif // TOOLS_H_INCLUDED
