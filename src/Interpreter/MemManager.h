//
// Created by Sam on 09/01/2020.
//

#ifndef TESTING_MEMMANAGER_H
#define TESTING_MEMMANAGER_H

#define WORD unsigned int
#define PART unsigned short
#define PART_BIT (sizeof(PART)*8)
#include <vector>


class MemManager {
public:
    MemManager();

    void setInstruction(PART value);
    PART getInstruction();
    PART getInstructionAddress();
    PART accessAt(PART address);
    void setData(PART address, PART value);
    void incrementInstruction();
private:
    std::vector<PART> data;

};


#endif //TESTING_MEMMANAGER_H
