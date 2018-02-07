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

/*
void createRegisterAndInstructionFromInput(vector<Register> &registers, vector<Instruction> &instructions, string const &input)
{
    istringstream iss(input.c_str());
    vector<string> instructionVector(istream_iterator<string>{iss}, istream_iterator<string>());

    string registerName(instructionVector[0]);
    string instructionOperator(instructionVector[1]);
    int number(instructionOperator[2]); */
    /* TO DO */
    /* create the instruction condition */

    /* Si Registre non présent dans tableau, le créer et l'ajouter */
    /*
    if(findRegisterByName(registers, registerName).getName() == "")
    {
        registers.push_back(Register(registerName));
    }
}

void createRegistersFromInput(vector<Register> &registers, vector<Instruction> &instructions, vector<string> const &input)
{
    for(int i(0); i != input.size(); ++i)
    {
        createRegisterAndInstructionFromInput(registers, instructions, input[i]);
    }
}
*/
