//
//  poker_game.hpp
//  poker_calculator
//
//  Created by Ben Ellis on 7/19/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#ifndef poker_game_hpp
#define poker_game_hpp

#include "poker_hand.hpp"
#include "deck.hpp"
//#include <algorithm>

class PokerGame
{
public:
    PokerGame();
    ~PokerGame();
    void init_hand();
    void init_community();
    double enumerate_all();
    void monte_carlo_loop(const int& ntrials=25000);
    int monte_carlo_loop2(const int& ntrials=25000);
    void monte_carlo_loop_thread(const int& ntrials=25000);
    void monte_carlo_omp_wrap(const int ntrials);
    static int monte_carlo_omp(Deck deck, std::vector<PokerHand> players, std::vector<Card> community_cards,
                                  int community_cards_left, const int ntrials);
private:
    int monte_carlo_trial(const int& nleft_community);
    Deck deck_;
    std::vector<PokerHand> players_;
    std::vector<Card> community_cards_;
    Card get_card_from_user();
    static PokerHand find_best_hand(const std::vector<std::vector<Card>>& hands_of_5);
};

#endif /* poker_game_hpp */