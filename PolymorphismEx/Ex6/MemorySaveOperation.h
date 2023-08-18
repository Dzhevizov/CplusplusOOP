#ifndef MEMORY_SAVE_OPERATION_H
#define MEMORY_SAVE_OPERATION_H

#include <stack>
#include "Operation.h"

class MemorySaveOperation final : public Operation {
    std::stack<int> operands;
public:
    void addOperand(int operand) override {
        this->operands.push(operand);
    }

    bool isCompleted() override {
        return false;
    }

    int getResult() override {
        const int result = operands.top();
        operands.pop();
        return result;
    }
};

#endif // MEMORY_SAVE_OPERATION_H
