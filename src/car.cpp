#include <simlib.h>
#include "headers/car.h"
#include "headers/facilities.h" 

const double carTravel = 20.0;
const double carTravelDisperse = 1.0;
const double zrniDeploymentMin = 10.0;
const double zrniDeploymentMax = 20.0;

const int grainLoadTons = 5;

void Car::Behavior()
{
    // Cesta, vylozeni, cesta zpet
    Wait(Normal(carTravel, carTravelDisperse));
    double deploymentTime = 10 + Exponential(3.0);
    Wait(deploymentTime);
    vykecavani(deploymentTime);
    Leave(grainWarehouse, grainLoadTons);
    Print("Stav zrni ve skladu: %d\n", grainWarehouse.Free());
    Wait(Normal(carTravel, carTravelDisperse));
    Print("Kara se vratila\n");
    Leave(cars, 1);
}