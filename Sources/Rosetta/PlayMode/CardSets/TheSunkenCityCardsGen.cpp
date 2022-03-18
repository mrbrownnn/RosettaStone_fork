// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// Hearthstone++ is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <Rosetta/PlayMode/CardSets/TheSunkenCityCardsGen.hpp>

namespace RosettaStone::PlayMode
{
void TheSunkenCityCardsGen::AddHeroes(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddHeroPowers(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddDruid(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddDruidNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddHunter(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddHunterNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddMage(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddMageNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddPaladin(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddPaladinNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddPriest(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddPriestNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddRogue(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddRogueNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddShaman(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddShamanNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddWarlock(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddWarlockNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddWarrior(std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddWarriorNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddDemonHunter(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddDemonHunterNonCollect(
    std::map<std::string, CardDef>& cards)
{
}

void TheSunkenCityCardsGen::AddNeutral(std::map<std::string, CardDef>& cards)
{
    // --------------------------------------- MINION - NEUTRAL
    // [TSC_032] Blademaster Okani - COST:4 [ATK:2/HP:6]
    // - Set: THE_SUNKEN_CITY, Rarity: Legendary
    // --------------------------------------------------------
    // Text: <b>Battlecry:</b>
    //       <b>Secretly</b> choose to <b>Counter</b> the next minion
    //       or spell your opponent plays while this is alive.
    // --------------------------------------------------------
    // GameTag:
    // - ELITE = 1
    // - BATTLECRY = 1
    // --------------------------------------------------------
    // RefTag:
    // - COUNTER = 1
    // --------------------------------------------------------
}

void TheSunkenCityCardsGen::AddNeutralNonCollect(
    std::map<std::string, CardDef>& cards)
{
    // ---------------------------------------- SPELL - NEUTRAL
    // [TSC_032t] Minion Counter - COST:0
    // - Set: THE_SUNKEN_CITY
    // --------------------------------------------------------
    // Text: <b>Counter</b> the next minion your opponent plays.
    // --------------------------------------------------------

    // ---------------------------------------- SPELL - NEUTRAL
    // [TSC_032t2] Spell Counter - COST:0
    // - Set: THE_SUNKEN_CITY
    // --------------------------------------------------------
    // Text: <b>Counter</b> the next spell your opponent plays.
    // --------------------------------------------------------
}

void TheSunkenCityCardsGen::AddAll(std::map<std::string, CardDef>& cards)
{
    AddHeroes(cards);
    AddHeroPowers(cards);

    AddDruid(cards);
    AddDruidNonCollect(cards);

    AddHunter(cards);
    AddHunterNonCollect(cards);

    AddMage(cards);
    AddMageNonCollect(cards);

    AddPaladin(cards);
    AddPaladinNonCollect(cards);

    AddPriest(cards);
    AddPriestNonCollect(cards);

    AddRogue(cards);
    AddRogueNonCollect(cards);

    AddShaman(cards);
    AddShamanNonCollect(cards);

    AddWarlock(cards);
    AddWarlockNonCollect(cards);

    AddWarrior(cards);
    AddWarriorNonCollect(cards);

    AddDemonHunter(cards);
    AddDemonHunterNonCollect(cards);

    AddNeutral(cards);
    AddNeutralNonCollect(cards);
}
}  // namespace RosettaStone::PlayMode