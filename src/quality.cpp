#include <simlib.h>
#include "headers/quality.h"
#include "headers/frost.h"
#include "headers/drought.h"
#include "headers/heavy_rains.h"
#include "headers/pests.h"
#include "headers/facilities.h"
#include "headers/constants.h"
#include "headers/aliens.h"

void Quality::Behavior() 
{
    (new Aliens(this))->Activate();
    Wait(1);
    if (this->_quality == 0) {
        this->Cancel();
    }
    Print("Pred zimou mame %d%% psenky\n", this->_quality);
    Seize(underGround);
    (new Frost(this))->Activate();
    Wait(fiveMonths);
    Print("Po zime mame %d%% psenky\n", this->_quality);
    Release(underGround);

    Seize(growth);
    Wait(fiveMonths);
    (new Drought(this))->Activate();
    (new HeavyRains(this))->Activate();
    (new Pests(this))->Activate();
    Print("Pockali jsme 5 mesicu az vyrosteme juchu\n");
    Release(growth);

}


int Quality::getQuality() 
{
    return this->_quality;
}

void Quality::setQuality(int value) 
{
    this->_quality = value;
}