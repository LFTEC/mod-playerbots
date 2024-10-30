#include "FosTriggers.h"
#include "Playerbots.h"
#include "AiObject.h"
#include "AiObjectContext.h"

bool MoveFromBronjahmTrigger::IsActive()
{
    Unit* boss = nullptr;
    boss = AI_VALUE2(Unit*, "find target", "bronjahm");
    if (boss && boss->HasUnitState(UNIT_STATE_CASTING))
    {
        if (boss->FindCurrentSpellBySpellId(SPELL_CORRUPT_SOUL))
            return true;
    }
    return false;
}

bool SwitchToSoulFragment::IsActive()
{
    Unit* fragment = nullptr;
    fragment = AI_VALUE2(Unit*, "find target", "corrupted soul fragment");
    if (fragment)
        return true;

    return false;
}
