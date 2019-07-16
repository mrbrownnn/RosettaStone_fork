// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_DAMAGE_NUMBER_TASK_HPP
#define ROSETTASTONE_DAMAGE_NUMBER_TASK_HPP

#include <Rosetta/Tasks/ITask.hpp>

namespace RosettaStone::SimpleTasks
{
//!
//! \brief DamageNumberTask class.
//!
//! This class represents the task for taking damage with stacked number.
//!
class DamageNumberTask : public ITask
{
 public:
    //! Constructs task with given \p character and \p damage.
    //! \param entityType The entity type of target to take damage.
    //! \param isSpellDamage true if it is spell damage, and false otherwise.
    DamageNumberTask(EntityType entityType, bool isSpellDamage = false);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

    //! Returns Clone Of Object (pure virtual).
    //! \returns clone of object.
    //! \this uses for thread safe. not to access same task in multiple threads
    ITask* CloneImpl() override;;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    TaskStatus Impl(Player& player) override;

    bool m_isSpellDamage = false;
};
}  // namespace RosettaStone::SimpleTasks

#endif  // ROSETTASTONE_DAMAGE_NUMBER_TASK_HPP
