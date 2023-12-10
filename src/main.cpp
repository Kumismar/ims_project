#include <simlib.h>
#include <time.h>
#include "headers/quality.h"
#include "headers/facilities.h"
#include "headers/harvester.h"
#include "headers/harvest.h"

const int tenMonths = 60 * 24 * 300;
const int oneDay = 60 * 24;
const int startTime = 0;
const int endTime = 60 * 24 * 365;

Facility underGround("");
Facility afterWinter("");
Facility growth("");
Facility day("");
Facility aliensCame("");

Store hectares("", 200);
Store cars("", 2);
Store grainWarehouse("", 1000);

Stat p("Mnozstvi mouky");
Stat q("Kvalita obili");
Stat oprava("oprava");
Stat vykecavani("vykecavani");

int main() 
{
    RandomSeed(time(nullptr));
    SetOutput("output.log");
    Print("Start simulace\n\n");


    for (int year = 2023; year < 2030; year++) {
        Init(startTime, endTime);
        underGround.Clear();
        afterWinter.Clear();
        growth.Clear();
        day.Clear(); 
        aliensCame.Clear();

        hectares.Clear();
        cars.Clear();
        grainWarehouse.Clear();

        Quality* quality = new Quality();
        quality->Activate();
        (new Harvest)->Activate(tenMonths + oneDay);
        (new Harvester(quality->getQuality()))->Activate(tenMonths + oneDay);

        Run();

        q(quality->getQuality());
        double flour = (quality->getQuality() / 100.0) * Uniform(0.7, 0.8) * grainWarehouse.Free();
        p(flour);
        Print("finalni mnozstvi mouky: %ft\n", flour);
    }
    p.Output();
    q.Output();
    oprava.Output();
    vykecavani.Output();
    return 0;
}