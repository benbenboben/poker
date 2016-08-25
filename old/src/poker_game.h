//
// Created by Ben Ellis on 8/3/16.
//

#ifndef POKER_POKER_GAME_H
#define POKER_POKER_GAME_H

#include "poker_hand.h"
#include "deck.h"
//#include <algorithm>

class PokerGame
{
public:
    PokerGame();
    ~PokerGame();
    void init_hand();
    void init_community();
    double enumerate_all();
    int monte_carlo_trial(const int& nleft_community);
    double monte_carlo_loop(const int& ntrials=25000);
    void monte_carlo_omp_wrap(const int ntrials);
    std::pair<int, double> monte_carlo_omp(Deck deck, std::vector<PokerHand> players, std::vector<Card> community_cards,
                                  int community_cards_left, const int ntrials);
private:
    Deck deck_;
    std::vector<PokerHand> players_;
    std::vector<Card> community_cards_;
    Card get_card_from_user();
    PokerHand find_best_hand(const std::vector<std::vector<Card>>& hands_of_5);
};

#endif //POKER_POKER_GAME_H
