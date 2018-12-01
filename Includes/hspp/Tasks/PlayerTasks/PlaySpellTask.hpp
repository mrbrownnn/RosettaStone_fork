// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_PLAY_SPELL_TASK_HPP
#define HEARTHSTONEPP_PLAY_SPELL_TASK_HPP

#include <hspp/Tasks/Requirement.hpp>
#include <hspp/Tasks/TaskAgent.hpp>
#include <hspp/Tasks/Tasks.hpp>

namespace Hearthstonepp::PlayerTasks
{
//!
//! \brief PlaySpellTask class.
//!
//! This class represents the task for playing spell.
//! It specifies target and casts spell to given target.
//!
class PlaySpellTask : public ITask
{
 public:
    //! Constructs task with given \p agent and \p entity.
    //! \param agent The task agent that interacts with game interface.
    //! \param source A pointer to source entity to play card.
    //! \param target A target of the card to receive power.
    PlaySpellTask(TaskAgent& agent, Entity* source, Entity* target);

    //! Returns task ID.
    //! \return Task ID.
    TaskID GetTaskID() const override;

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    MetaData Impl(Player& player) override;

    //! Checks that spell card needs target.
    //! \param power A pointer to power of the card.
    //! \return true if spell card needs target, and false otherwise.
    static bool NeedTarget(Power* power);

    Entity* m_source = nullptr;
    Requirement m_requirement;
    Entity* m_target = nullptr;
};
}  // namespace Hearthstonepp::PlayerTasks

#endif  // HEARTHSTONEPP_PLAY_SPELL_TASK_HPP
