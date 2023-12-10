#include <simlib.h>
#include "headers/aliens.h"
#include "headers/quality.h"
#include "headers/facilities.h"

Aliens::Aliens(Quality* quality)
{
    this->_quality = quality;
}

void Aliens::Behavior() 
{
    const int probab = (int)(Uniform(0, 1000));
    if (probab < 100) {
        this->_quality->setQuality(0);
        Seize(aliensCame);
        Print("Oh no! Napadli nas mimozemstani. Vsechna psenice je v pici.\n");
    }
}