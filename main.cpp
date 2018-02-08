#include <iostream>
#include <sstream>
#include <iterator>
#include "tools.h"

using namespace std;

int main()
{
    vector<string> input(importInput("input.txt"));
    //displayVector(input);
    //cout << input.size() << endl;

    vector<Register> registers;
    vector<Instruction> instructions;
    createRegistersFromInput(registers, input);
    createInstructionsFromInput(registers, instructions, input);
    executeInstructions(registers, instructions);

    cout << endl << getMaxValueFromRegisters(registers) << endl;

    /* !!! DEBUG !!! */
    /*
    for(int i(0); i != registers.size(); ++i)
    {
        registers[i].display();
    }
    cout << registers.size() << endl;
    */
    /* !!!!!!!!!!!!! */

    /* !!! DEBUG !!! */
    /*
    for(int i(0); i != instructions.size(); ++i)
    {
        instructions[i].display();
    }
    cout << instructions.size() << endl;
    */
    /* !!!!!!!!!!!!! */

    return 0;
}
