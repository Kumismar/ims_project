#include <simlib.h>
#include <time.h>
#include "headers/quality.h"
#include "headers/constants.h"
#include "headers/facilities.h"


Facility underGround("");
Facility afterWinter("");
Facility growth("");

int main() 
{
    RandomSeed(time(nullptr));
    SetOutput("output.log");
    Print("Start simulace\n\n");
    for (int year = 2023; year < 2123; year++) {
        Init(startTime, endTime);
        Print("\nRok: %d\n", year);

        underGround.Clear();
        afterWinter.Clear();
        growth.Clear();

        Quality* quality = new Quality();
        quality->Activate();

        Run();

        int percentage = quality->getQuality();
        Print("Zbylo nam %d%% psenice\n", percentage);
    }
    
    return 0;
}