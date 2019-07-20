// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <Rosetta/Actions/Summon.hpp>
#include <Rosetta/Games/Game.hpp>

namespace RosettaStone::Generic
{
void Summon(Player& player, Minion* minion, int fieldPos)
{
    player.GetFieldZone().Add(*minion, fieldPos);

    player.GetGame()->UpdateAura();

    player.GetGame()->summonedMinions.emplace_back(minion);

    // Process after summon trigger
    player.GetGame()->taskQueue.StartEvent();
    player.GetGame()->triggerManager.OnAfterSummonTrigger(&player, minion);
    player.GetGame()->ProcessTasks();
    player.GetGame()->taskQueue.EndEvent();
}
}  // namespace RosettaStone::Generic