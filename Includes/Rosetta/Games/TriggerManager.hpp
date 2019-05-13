// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ROSETTASTONE_TRIGGER_MANAGER_HPP
#define ROSETTASTONE_TRIGGER_MANAGER_HPP

#include <functional>

namespace RosettaStone
{
class Entity;
class Player;

//!
//! \brief TriggerManager class.
//!
//! This class monitors trigger and invokes method when a trigger is activated.
//!
class TriggerManager
{
 public:
    //! Callback for trigger when player's turn is started.
    //! \param player A player to execute trigger.
    //! \param sender An entity that is the source of trigger.
    void OnStartTurnTrigger(Player* player, Entity* sender) const;

    //! Callback for trigger when player's turn is ended.
    //! \param player A player to execute trigger.
    //! \param sender An entity that is the source of trigger.
    void OnEndTurnTrigger(Player* player, Entity* sender) const;

    //! Callback for trigger when entity is healed.
    //! \param player A player to execute trigger.
    //! \param sender An entity that is the source of trigger.
    void OnHealTrigger(Player* player, Entity* sender) const;

    //! Callback for trigger when entity attacks target.
    //! \param player A player to execute trigger.
    //! \param sender An entity that is the source of trigger.
    void OnAttackTrigger(Player* player, Entity* sender) const;

    //! Callback for trigger when entity is summoned.
    //! \param player A player to execute trigger.
    //! \param sender An entity that is the source of trigger.
    void OnSummonTrigger(Player* player, Entity* sender) const;

    //! Callback for trigger when entity is taken damage.
    //! \param player A player to execute trigger.
    //! \param sender An entity that is the source of trigger.
    void OnTakeDamageTrigger(Player* player, Entity* sender) const;

    std::function<void(Player*, Entity*)> startTurnTrigger;
    std::function<void(Player*, Entity*)> endTurnTrigger;
    std::function<void(Player*, Entity*)> healTrigger;
    std::function<void(Player*, Entity*)> attackTrigger;
    std::function<void(Player*, Entity*)> summonTrigger;
    std::function<void(Player*, Entity*)> takeDamageTrigger;
};
}  // namespace RosettaStone

#endif  // ROSETTASTONE_TRIGGER_MANAGER_HPP
