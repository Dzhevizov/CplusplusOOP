#ifndef DIVISION_OPERATION_H
#define DIVISION_OPERATION_H

#include <vector>
#include "Operation.h"

class DivisionOperation final : public Operation {
    std::vector<int> operands;
    int result;
public:
    void addOperand(int operand) override {
        this->operands.push_back(operand);

        if (this->isCompleted()) {
            this->result = this->operands[0] / this->operands[1];
        }
    }

    bool isCompleted() override {
        return this->operands.size() == 2;
    }

    int getResult() override {
        return this->result;
    }
};

#endif // DIVISION_OPERATION_H
