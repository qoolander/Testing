//
// Created by Sam on 09/01/2020.
//

#include "Interpreter.h"


Interpreter::Interpreter() {
    memory = MemManager();
}



void Interpreter::iterate() {
    PART op = memory.getInstructionAddress();
    memory.incrementInstruction();
    PART data = memory.getInstructionAddress();
    runInstruction((op<<PART_BIT) + data); //#opdt -> #(op code) + (data)
    memory.incrementInstruction();
}

void Interpreter::runInstruction(WORD instr) {
    switch(instr & OP){
        case 0x00:
            //00 RR RR RR
            //ADD rA rB rC
            // rA = rB + rC
            memory.setData(instr & D1, memory.accessAt(instr&D2) + memory.accessAt(instr&D3));
            break;
        case 0x01:
            //01 RR RR XX
            //ADI rA rB DATA
            //rA = rB + DATA
            memory.setData(instr & D1, memory.accessAt(instr&D2) + instr&D3);
            break;
        case 0x02:
            //02 RR RR RR
            //NAND rA rB rC
            //rA = rB NAND rC
            memory.setData(instr & D1, ~(memory.accessAt(instr&D2) & memory.accessAt(instr&D3)));
            break;
        case 0x03:
            //03 RR XX NA
            //SET rA DATA 00
            //rA = DATA
            memory.setData(instr&D1, instr&D2);
            break;
        case 0x04:
            //04 RR RR NA
            //SET rA rB 00
            //rA = rB
            memory.setData(instr&D1, instr&D2);
        case 0x05:
            //05 RR RR XX
            //BNE rA rB DATA
            //Memory address set to DATA if rA != rB
            if(instr&D1 != instr&D2){
                memory.setInstruction(instr&D3);
            }
        default:

            break;
    }
}

void Interpreter::initiateProgram(std::list<PART> data) {
    PART i = 0;
    while(data.size()>0){
        memory.setData(i, data.front());
        i++;
        data.pop_front();
    }
}
