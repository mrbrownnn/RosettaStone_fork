// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include "gtest/gtest.h"

#include <Rosetta/Actions/ActionParams.hpp>
#include <Rosetta/Cards/Cards.hpp>
#include <Rosetta/Views/Board.hpp>

#include <effolkronium/random.hpp>

using Random = effolkronium::random_static;

using namespace RosettaStone;

class TestActionParams : public ActionParams
{
 public:
    TestActionParams() = default;

    TestActionParams(const TestActionParams&) = delete;
    TestActionParams(TestActionParams&&) noexcept = delete;

    TestActionParams& operator=(const TestActionParams&) = delete;
    TestActionParams& operator=(TestActionParams&&) noexcept = delete;

    void Init(const Board& board)
    {
        m_board = &board;
        Initialize(m_board->GetCurPlayerStateRefView().GetActionValidGetter());
    }

    std::size_t GetNumber(ActionType actionType, ActionChoices& choices) final
    {
        if (actionType != ActionType::MAIN_ACTION)
        {
            if (choices.Size() == 1)
            {
                return choices.Get(0);
            }
        }

        const std::size_t count = choices.Size();
        const auto randIdx = Random::get<std::size_t>(0, count - 1);
        const int result = static_cast<int>(randIdx);

        return result;
    }

 private:
    const Board* m_board = nullptr;
};

TEST(ActionValidChecker, Check)
{
    GameConfig config;
    config.player1Class = CardClass::WARLOCK;
    config.player2Class = CardClass::PALADIN;
    config.startPlayer = PlayerType::PLAYER1;
    config.doFillDecks = false;
    config.autoRun = false;

    Game game(config);
    game.Start();
    game.ProcessUntil(Step::MAIN_START);

    Player* player1 = game.GetPlayer1();
    Player* player2 = game.GetPlayer2();
    player1.SetTotalMana(10);
    player1.SetUsedMana(0);
    player2.SetTotalMana(10);
    player2.SetUsedMana(0);

    const auto weapon1 = dynamic_cast<Weapon*>(Entity::GetFromCard(
        player1, Cards::GetInstance().FindCardByName("Fiery War Axe")));
    player1.GetHero()->AddWeapon(*weapon1);

    const auto weapon2 = dynamic_cast<Weapon*>(Entity::GetFromCard(
        player2, Cards::GetInstance().FindCardByName("Arcanite Reaper")));
    player2.GetHero()->AddWeapon(*weapon2);

    for (std::size_t i = 0; i < 3; ++i)
    {
        Entity* entity1 = Entity::GetFromCard(
            player1, Cards::GetInstance().FindCardByName("Fireball"),
            std::nullopt, &player1.GetHandZone());
        player1.GetHandZone().Add(*entity1);
    }

    for (std::size_t i = 0; i < 3; ++i)
    {
        Entity* entity2 = Entity::GetFromCard(
            player2, Cards::GetInstance().FindCardByName("Frostbolt"),
            std::nullopt, &player2.GetHandZone());
        player2.GetHandZone().Add(*entity2);
    }

    for (std::size_t i = 0; i < 6; ++i)
    {
        Entity* entity1 = Entity::GetFromCard(
            player1, Cards::GetInstance().FindCardByName("Flame Imp"),
            std::nullopt, &player1.GetFieldZone());
        player1.GetFieldZone().Add(*entity1);
    }

    for (std::size_t i = 0; i < 4; ++i)
    {
        Entity* entity2 = Entity::GetFromCard(
            player2, Cards::GetInstance().FindCardByName("Worthless Imp"),
            std::nullopt, &player2.GetFieldZone());
        player2.GetFieldZone().Add(*entity2);
    }

    TestActionParams actionParams;
    const Board board(game, game.GetCurrentPlayer().playerType);

    EXPECT_NO_THROW(actionParams.Init(board));

    EXPECT_EQ(actionParams.GetChecker().GetMainOpType(0),
              MainOpType::PLAY_CARD);
    EXPECT_EQ(actionParams.GetChecker().GetMainOpType(1), MainOpType::ATTACK);
    EXPECT_EQ(actionParams.GetChecker().GetMainOpType(2),
              MainOpType::USE_HERO_POWER);
    EXPECT_EQ(actionParams.GetChecker().GetMainOpType(3), MainOpType::END_TURN);
}