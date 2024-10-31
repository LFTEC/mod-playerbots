#include "Playerbots.h"
#include "FosActions.h"
#include "FosStrategy.h"

bool MoveFromBronjahmAction::Execute(Event event)
{
    Unit* boss = nullptr;
    boss = AI_VALUE2(Unit*, "find target", "bronjahm");
    if (!boss)
        return false;

    
    float distance = bot->GetExactDist2d(boss->GetPosition());
    float targetDis = 30.0f;
    if (distance >= targetDis)
        return false;
    return MoveAway(boss, targetDis - distance);
}

bool MoveFromBronjahmAction::isUseful() { return bot->HasAura(SPELL_CORRUPT_SOUL); }

bool AttackCorruptedSoulFragmentAction::Execute(Event event)
{
    Unit* fragment = nullptr;

    GuidVector targets = AI_VALUE(GuidVector, "possible targets no los");

    for (auto i = targets.begin(); i != targets.end(); ++i)
    {
        Unit* unit = botAI->GetUnit(*i);
        if (unit && unit->GetEntry() == NPC_CORRUPTED_SOUL_FRAGMENT)
        {
            fragment = unit;
            break;
        }
    }

    if (!fragment)
        return false;

    if (botAI->IsDps(bot))
    {
        if (AI_VALUE(Unit*, "current target") == fragment)
            return false;

        return Attack(fragment);
    }
    else if (botAI->IsTank(bot))
    {
        float distance = bot->GetExactDist2d(fragment->GetPosition());
        float targetDis = 10.0f;
        if (distance >= targetDis)
            return false;
        return MoveAway(fragment, targetDis - distance);
    }
    else
        return false;
    
}

bool AttackCorruptedSoulFragmentAction::isUseful() { return true; }
