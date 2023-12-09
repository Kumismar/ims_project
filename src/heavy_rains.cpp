#include <simlib.h>
#include <cmath>
#include "headers/heavy_rains.h"
#include "headers/quality.h"

HeavyRains::HeavyRains(Quality* quality) 
{
    this->_quality = quality;
}

void HeavyRains::Behavior() 
{
    const int probab = (int)(Random() * 100);
    const int percentToLose = (int)(Random() * 20);
    if (probab < 25) {
        const int quality = this->_quality->getQuality();
        const int toChange = std::round(quality / 100.0 * percentToLose);
        this->_quality->setQuality(quality - toChange);
        Print("Deste nam znicily %d%% psenice z puvodnich %d%% psenice, tedy %d%%\n", percentToLose, quality, toChange);
    }
}