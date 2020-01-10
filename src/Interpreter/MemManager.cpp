//
// Created by Sam on 09/01/2020.
//

#include "MemManager.h"

MemManager::MemManager() {
    data = std::vector<PART>();
    data.resize(0x1<<PART_BIT);
}

PART MemManager::accessAt(PART address) {
    return data.at(address);
}

void MemManager::setData(PART address, PART value) {
    data[address] = value;
}

PART MemManager::getInstructionAddress() {
    return 0x00;
}

void MemManager::incrementInstruction() {
    data[0]++;
}

PART MemManager::getInstruction() {
    return accessAt(getInstructionAddress());
}

void MemManager::setInstruction(PART value) {
    setData(getInstructionAddress(), value);
}

