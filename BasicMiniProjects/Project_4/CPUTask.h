// CPUTask.h

#pragma once
#include "ITask.h"

class CPUTask : public ITask
{
public:
    void execute() override;
};