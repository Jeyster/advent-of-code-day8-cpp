#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <cstdlib>
#include <cstddef>
#include "tools.h"

using namespace std;

vector<string> importInput(string fileName)
{
    ifstream myStream(fileName.c_str());
    if(!myStream)
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
        //exit(0);
    }

    string line;
    vector<string> input;
    while(getline(myStream, line))
    {
        input.push_back(line);
    }

    return input;
}

void displayVector(vector<string> tab)
{
    vector<string>::iterator itTab;
    for(itTab = tab.begin(); itTab != tab.end(); ++itTab)
    {
        cout << *itTab << endl;
    }
    cout << endl;
}

Register* findRegisterPointeurByName(vector<Register> &registers, string const &name)
{
    for(int i(0); i != registers.size(); ++i)
    {
        if(registers[i].getName() == name)
        {
            return &registers[i];
        }
    }
}

Register findRegisterByName(vector<Register> &registers, string const &name)
{
    for(int i(0); i != registers.size(); ++i)
    {
        if(registers[i].getName() == name)
        {
            return registers[i];
        }
    }
    return Register();
}

void createRegisterFromString(vector<Register> &registers, string const &input)
{
    istringstream iss(input.c_str());
    vector<string> instructionVector(istream_iterator<string>{iss}, istream_iterator<string>());
    string registerName(instructionVector[0]);

    /* Si Registre non présent dans tableau, le créer et l'ajouter */
    if(findRegisterByName(registers, registerName).getName() == "")
    {
        registers.push_back(Register(registerName));
    }
}

void createRegistersFromInput(vector<Register> &registers, vector<string> const &input)
{
    for(int i(0); i != input.size(); ++i)
    {
        createRegisterFromString(registers, input[i]);
    }
}

void createInstructionFromString(vector<Register> &registers, vector<Instruction> &instructions, string const &input)
{
    istringstream iss(input.c_str());
    vector<string> instructionVector(istream_iterator<string>{iss}, istream_iterator<string>());

    string registerName(instructionVector[0]);
    string instructionOperator(instructionVector[1]);
    string numberStr(instructionVector[2]);
    int number(atoi(numberStr.c_str()));
    string conditionRegisterName(instructionVector[4]);
    string conditionOperator(instructionVector[5]);
    string conditionNumberStr(instructionVector[6]);
    int conditionNumber(atoi(conditionNumberStr.c_str()));

    Register* reg = findRegisterPointeurByName(registers, registerName);
    Register* conditionReg = findRegisterPointeurByName(registers, conditionRegisterName);

    instructions.push_back(Instruction(reg, instructionOperator, number, conditionReg, conditionOperator, conditionNumber));
}

void createInstructionsFromInput(vector<Register> &registers, vector<Instruction> &instructions, vector<string> const &input)
{
    for(int i(0); i != input.size(); ++i)
    {
        createInstructionFromString(registers, instructions, input[i]);
    }
}

bool convertStringIntoBool(Register* conditionReg, string const &conditionOperator, int const &conditionNumber)
{
    if(conditionOperator == "==")
    {
        return (conditionReg->getValue() == conditionNumber);
    }
    else if(conditionOperator == "!=")
    {
        return (conditionReg->getValue() != conditionNumber);
    }
    else if(conditionOperator == "<")
    {
        return (conditionReg->getValue() < conditionNumber);
    }
    else if(conditionOperator == ">")
    {
        return (conditionReg->getValue() > conditionNumber);
    }
    else if(conditionOperator == "<=")
    {
        return (conditionReg->getValue() <= conditionNumber);
    }
    else if(conditionOperator == ">=")
    {
        return (conditionReg->getValue() >= conditionNumber);
    }
    else
    {
        cout << "Erreur conversion booléen d'instruction !!!" << endl;
        return false;
    }
}

void executeInstructions(vector<Register> &registers, vector<Instruction> &instructions)
{
    for(int i(0); i != instructions.size(); ++i)
    {
        Instruction currentInstruction(instructions[i]);
        Register* instructedRegister(currentInstruction.getRegister());
        bool condition(convertStringIntoBool(currentInstruction.getConditionRegister(), currentInstruction.getConditionOperator(), currentInstruction.getConditionNumber()));

        if(condition)
        {
            int newValue(0);
            if(currentInstruction.getOperator() == "inc")
            {
                newValue = instructedRegister->getValue() + currentInstruction.getNumber();
                instructedRegister->setValue(newValue);
            }
            else if(currentInstruction.getOperator() == "dec")
            {
                newValue = instructedRegister->getValue() - currentInstruction.getNumber();
                instructedRegister->setValue(newValue);
            }
        }
    }
}

int getMaxValueFromRegisters(vector<Register> &registers)
{
    int maxValue(0);
    for(int i(0); i != registers.size(); ++i)
    {
        if(registers[i].getValue() > maxValue)
        {
            maxValue = registers[i].getValue();
        }
    }

    return maxValue;
}
