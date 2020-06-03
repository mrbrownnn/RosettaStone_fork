// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Rosetta/Battlegrounds/Cards/Cards.hpp>
#include <Rosetta/Battlegrounds/Models/MinionPool.hpp>

namespace RosettaStone::Battlegrounds
{
void MinionPool::Initialize()
{
    std::size_t idx = 0;

    // Tier 1
    for (const auto& card : Cards::GetTier1Minions())
    {
        for (std::size_t i = 0; i < NUM_COPIES_OF_EACH_TIER1_MINIONS; ++i)
        {
            m_minions.at(idx) = { Minion(card), idx, true };
            ++idx;
        }
    }

    // Tier 2
    for (const auto& card : Cards::GetTier2Minions())
    {
        for (std::size_t i = 0; i < NUM_COPIES_OF_EACH_TIER2_MINIONS; ++i)
        {
            m_minions.at(idx) = { Minion(card), idx, true };
            ++idx;
        }
    }

    // Tier 3
    for (const auto& card : Cards::GetTier3Minions())
    {
        for (std::size_t i = 0; i < NUM_COPIES_OF_EACH_TIER3_MINIONS; ++i)
        {
            m_minions.at(idx) = { Minion(card), idx, true };
            ++idx;
        }
    }

    // Tier 4
    for (const auto& card : Cards::GetTier4Minions())
    {
        for (std::size_t i = 0; i < NUM_COPIES_OF_EACH_TIER4_MINIONS; ++i)
        {
            m_minions.at(idx) = { Minion(card), idx, true };
            ++idx;
        }
    }

    // Tier 5
    for (const auto& card : Cards::GetTier5Minions())
    {
        for (std::size_t i = 0; i < NUM_COPIES_OF_EACH_TIER5_MINIONS; ++i)
        {
            m_minions.at(idx) = { Minion(card), idx, true };
            ++idx;
        }
    }

    // Tier 6
    for (const auto& card : Cards::GetTier6Minions())
    {
        for (std::size_t i = 0; i < NUM_COPIES_OF_EACH_TIER6_MINIONS; ++i)
        {
            m_minions.at(idx) = { Minion(card), idx, true };
            ++idx;
        }
    }
}
}  // namespace RosettaStone::Battlegrounds
