#include <simlib.h>
#include <cmath>
#include "headers/frost.h"
#include "headers/quality.h"

Frost::Frost(Quality* quality)
{
    this->_quality = quality;
}

void Frost::Behavior() 
{
    const int probab = (int)(Random() * 100);
    const int percentToLose = (int)(Random() * 20);
    if (probab < 33) {
        this->_quality->setQuality(this->_quality->getQuality() - percentToLose);
        Print("Mraz nam znicil %d%% psenice\n", percentToLose);
    }
}