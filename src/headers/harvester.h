#pragma once

#include <simlib.h>

class Harvester : public Process
{
    int _quality;
public:
    Harvester(int quality);
    void Behavior() override;
};