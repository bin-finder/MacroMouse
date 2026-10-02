#pragma once
#include "Icommand.h"

class BaseCommand : public Icommand{
    public:
    void update(){}
    void postStop(){}
    void startup(){}
};