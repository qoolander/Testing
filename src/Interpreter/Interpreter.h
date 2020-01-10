//
// Created by Sam on 09/01/2020.
//

#ifndef TESTING_INTERPRETER_H
#define TESTING_INTERPRETER_H

#define OP 0xff000000
#define D1 0x00ff0000
#define D2 0x0000ff00
#define D3 0x000000ff

#include "MemManager.h"
#include <list>
#include <string>

class Interpreter {

public:
    void iterate();

    Interpreter();
    void initiateProgram(std::list<PART> data);
private:
    MemManager memory;
    void runInstruction(WORD instr);
};


#endif //TESTING_INTERPRETER_H
