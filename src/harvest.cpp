#include "headers/harvest.h"
#include "headers/facilities.h"
#include <simlib.h>

const int oneMonth = 24 * 60 * 30;

void Harvest::Behavior()
{
    Seize(aliensCame);
    Release(aliensCame);
    Wait(oneMonth);
    Print("Mesic ubehl, zbylo %d hektaru\n", hectares.Free());
    Enter(hectares, hectares.Free());
}