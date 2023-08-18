#ifndef MEMORY_RECALL_OPERATION_H
#define MEMORY_RECALL_OPERATION_H

#include <memory>
#include "Operation.h"
#include "MemorySaveOperation.h"
#include <iostream>

class MemoryRecallOperation final : public Operation {
    std::shared_ptr<MemorySaveOperation> m_memorySave;
public:
    MemoryRecallOperation(const std::shared_ptr<MemorySaveOperation>& memorySave)
        : m_memorySave(memorySave)
    {
    }
    void addOperand(int operand) override {
        std::cerr << "MemoryRecallOperation::addOperand() should not be invoked" << std::endl;
    }

    bool isCompleted() override {
        return true;
    }

    int getResult() override {
        return m_memorySave->getResult();
    }
};

#endif // MEMORY_RECALL_OPERATION_H
