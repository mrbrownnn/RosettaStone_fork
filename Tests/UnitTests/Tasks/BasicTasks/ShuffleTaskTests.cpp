// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "gtest/gtest.h"
#include <Utils/TestUtils.h>

#include <hspp/Tasks/BasicTasks/ShuffleTask.h>

using namespace Hearthstonepp;

TEST(ShuffleTask, GetTaskID)
{
    BasicTasks::ShuffleTask init;
    EXPECT_EQ(init.GetTaskID(), +TaskID::SHUFFLE);
}

TEST(ShuffleTask, Run)
{
    BasicTasks::ShuffleTask init;
    TestUtils::PlayerGenerator gen(CardClass::DRUID, CardClass::ROGUE);

    for (int i = 0; i < 5; i++)
    {
        auto card = TestUtils::GenerateMinionCard("minion", 5, 1);
        gen.player1.cards.emplace_back(new Minion(card));
    }

    MetaData result = init.Run(gen.player1, gen.player2);
    EXPECT_EQ(result, MetaData::SHUFFLE_SUCCESS);
    EXPECT_EQ(gen.player1.cards.size(), static_cast<size_t>(5));
}