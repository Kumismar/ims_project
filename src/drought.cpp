#include <simlib.h>
#include <cmath>
#include "headers/drought.h"
#include "headers/quality.h"

Drought::Drought(Quality* quality)
{
    this->_quality = quality;
}

void Drought::Behavior() 
{
    const int probab = (int)(Uniform(0, 100));
    const int percentToLose = (int)(Uniform(0, 20));
    if (probab < 25) {
        const int quality = this->_quality->getQuality();
        const int toChange = std::round(quality / 100.0 * percentToLose);
        this->_quality->setQuality(quality - toChange);
        Print("Sucho nam znicilo %d%% psenice z puvodnich %d%% psenice, tedy %d%%\n", percentToLose, quality, toChange);
    }
}