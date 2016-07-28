//
//  poker_hand.hpp
//  poker
//
//  Created by Ben Ellis on 7/15/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#ifndef poker_hand_h
#define poker_hand_h

#include <iostream>
#include <vector>

#include "deck.h"

class PokerHand : public Deck
{
public:
    PokerHand();
    PokerHand(const std::vector<Card>& cards);
    void print_all_hands();
    void score_hand(const std::vector<Card>& sub_hand);
    void score_hand();
private:
    static const int MAX_HAND_ = 7;
    static const int SCORE_SIZE_ = 5;
    int hand_score_;
    int special_value_1_;
    int special_value_2_;
    std::vector<Card> best_hand_;
    static bool is_flush(const std::vector<Card>& sub_hand);
    static bool is_straight(const std::vector<Card>& sub_hand);
    static bool is_royal_flush(const std::vector<Card>& sub_hand);
    static bool is_straight_flush(const std::vector<Card>& sub_hand);
    static bool has_ace(const std::vector<Card>& sub_hand);
    static int has_x_of_a_kind(const int& x, const std::vector<Card>& sub_hand);
    static std::pair<int, int> has_x_y_of_a_kind(const int& x, const int& y, const std::vector<Card>& sub_hand);
};

#endif /* poker_hand_h */
