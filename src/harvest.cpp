#include "headers/harvest.h"
#include "headers/facilities.h"
#include <simlib.h>

const int oneMonth = 24 * 60 * 30;

void Harvest::Behavior()
{
    // Pokud prileteli mimozemstani, sklizen vubec nenastane
    Seize(aliensCame);
    Release(aliensCame);
    // Po mesici je zbytek urody zahozen
    Wait(oneMonth);
    hectaresLeft(hectares.Free());
    Enter(hectares, hectares.Free());
}