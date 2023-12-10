#include <simlib.h>
#include "headers/day_cycle.h"
#include "headers/facilities.h"

const int oneNight = 14 * 60;
const int oneDay = 10 * 60;

void DayCycle::Behavior() 
{
    while (true) {
        Wait(oneDay);
        (new Night)->Activate();
        Wait(oneNight);
        Release(day);
    }
}

void Night::Behavior()
{
    Seize(day);
}