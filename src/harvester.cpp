#include "headers/harvester.h"
#include "headers/facilities.h"
#include "headers/car.h"
#include <simlib.h>

const int twoDays = 24 * 60 * 2;
const double harvesting = 16.0;
const double harvestingDispersion = 1.5;

Harvester::Harvester(int quality)
{
    this->_quality = quality;
}

void Harvester::Behavior() 
{
    // Pokud prileteli mimozemstani, kombajn vubec nepracuje
    Seize(aliensCame);
    Release(aliensCame);
    // Inicializace skladu zrni
    Enter(grainWarehouse, grainWarehouse.Capacity());
    while (hectares.Free() != 0) {
        int probab = (int)(Uniform(0, 100));
        if (probab < 2) {
            // Porucha kombajnu
            double waittime = Exponential(twoDays);
            Wait(waittime);
            harvesterRepair(waittime);
        }
        Enter(cars, 1);
        Enter(hectares, 1);
        Seize(day);
        Wait(Normal(harvesting, harvestingDispersion));
        (new Car)->Activate();
        Release(day);
    }
}