#ifndef _PLAYERBOT_WOTLKDUNGEONNEXACTIONCONTEXT_H
#define _PLAYERBOT_WOTLKDUNGEONNEXACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "FosActions.h"

class WotlkDungeonFosActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonFosActionContext() {
            creators["move from bronjahm"] = &WotlkDungeonFosActionContext::move_from_bronjahm;
            creators["attack corrupted soul fragment"] = &WotlkDungeonFosActionContext::attack_corrupted_soul_fragment;
        }
    private:
        static Action* move_from_bronjahm(PlayerbotAI* ai) { return new MoveFromBronjahmAction(ai); }
        static Action* attack_corrupted_soul_fragment(PlayerbotAI* ai) { return new AttackCorruptedSoulFragmentAction(ai); }
};

#endif
