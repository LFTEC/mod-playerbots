#include "FosStrategy.h"
#include "FosMultipliers.h"

void WotlkDungeonFosStrategy::InitTriggers(std::vector<TriggerNode*>& triggers) {
    triggers.push_back(
        new TriggerNode("move from bronjahm",
                        NextAction::array(0, new NextAction("move from bronjahm", ACTION_MOVE + 5), nullptr)));
    triggers.push_back(new TriggerNode(
        "switch to soul fragment", NextAction::array(0, new NextAction("attack corrupted soul fragment", ACTION_RAID + 1), nullptr)));
}

void WotlkDungeonFosStrategy::InitMultipliers(std::vector<Multiplier*>& multipliers)
{
    multipliers.push_back(new BronjahmMultiplier(botAI));
    multipliers.push_back(new AttackFragmentMultiplier(botAI));
}