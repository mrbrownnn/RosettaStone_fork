// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Games/Game.hpp>
#include <Rosetta/Models/Enchantment.hpp>
#include <Rosetta/Models/Player.hpp>

#include <algorithm>
#include <utility>

namespace RosettaStone
{
Enchantment::Enchantment(Player* player, Card* card,
                         std::map<GameTag, int> tags, Entity* target)
    : Playable(player, card, std::move(tags)), m_target(target)
{
    // Do nothing
}

Enchantment* Enchantment::GetInstance(Player* player, Card* card,
                                      Entity* target)
{
    std::map<GameTag, int> tags;
    tags[GameTag::ENTITY_ID] = player->game->GetNextID();
    tags[GameTag::CONTROLLER] = player->playerID;
    tags[GameTag::ZONE] = static_cast<int>(ZoneType::SETASIDE);

    Enchantment* instance = new Enchantment(player, card, tags, target);

    target->appliedEnchantments.emplace_back(instance);

    return instance;
}

Entity* Enchantment::GetTarget() const
{
    return m_target;
}

void Enchantment::Remove()
{
    if (!card->power.GetDeathrattleTask().empty())
    {
        for (auto& power : card->power.GetDeathrattleTask())
        {
            ITask* clonedPower = power->Clone();

            clonedPower->SetPlayer(m_target->player);
            clonedPower->SetSource(m_target);
            clonedPower->SetTarget(this);

            game->taskQueue.Enqueue(clonedPower);
        }
    }

    if (activatedTrigger != nullptr)
    {
        activatedTrigger->Remove();
    }

    const auto iter = std::find(m_target->appliedEnchantments.begin(),
                                m_target->appliedEnchantments.end(), this);
    if (iter != m_target->appliedEnchantments.end())
    {
        m_target->appliedEnchantments.erase(iter);
    }
}
}  // namespace RosettaStone
