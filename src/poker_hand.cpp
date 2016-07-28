//
//  poker_hand.cpp
//  poker
//
//  Created by Ben Ellis on 7/15/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#include "poker_hand.h"
#include "misc.h"

const std::vector<std::string> HANDS_ = {"HIGH", "PAIR", "TWO_PAIR", "THREE_OF_A_KIND",
                                         "STRAIGHT", "FLUSH", "FULL_HOUSE", "FOUR_OF_A_KIND",
                                         "STRAIGHT_FLUSH", "ROYAL_FLUSH"};

PokerHand::PokerHand() : Deck(false) {
    
};

PokerHand::PokerHand(const std::vector<Card>& cards) {
    deck_ = cards;
}

void PokerHand::print_all_hands() {
    std::vector<std::vector<Card>> all_hands = combinations(deck_, SCORE_SIZE_);
    std::cout << all_hands.size() << std::endl;
    for(int ihand = 0; ihand < all_hands.size(); ihand++) {
        std::cout << "hand " << ihand << std::endl;
        for(int icard = 0; icard < all_hands[ihand].size(); icard++) {
            std::cout << display_card(all_hands[ihand][icard]) << " ";
        }
        std::cout << std::endl;
    }
}

bool PokerHand::is_flush(const std::vector<Card>& sub_hand) {
    int suit = sub_hand[0].get_suit();
    for(const Card& c: sub_hand) {
        if(c.get_suit() != suit) return false;
    }
    return true;
}

bool PokerHand::is_straight(const std::vector<Card>& sub_hand) {
    std::vector<Card>::const_iterator end_iter = std::end(sub_hand);
    if(has_ace(sub_hand) && sub_hand[0].get_rank() == 0) end_iter -= 1;
    for(std::vector<Card>::const_iterator i = std::begin(sub_hand); i != end_iter; i++) {
        std::vector<Card>::const_iterator j = i + 1;
        if(j == end_iter) break;
        if((*j).get_rank() - (*i).get_rank() != 1) {
            return false;
        }
    }
    return true;
}

bool PokerHand::has_ace(const std::vector<Card>& sub_hand) {
    for(const Card& c: sub_hand) {
        if(c.get_rank() == RANKS_.size() - 1) return true;
    }
    return false;
}

void PokerHand::score_hand() {
    score_hand(deck_);
}

void PokerHand::score_hand(const std::vector<Card>& sub_hand) {
    std::cout << "true " << true << std::endl;
    std::cout << "has straight " << is_straight(sub_hand) << std::endl;
}

bool PokerHand::is_royal_flush(const std::vector<Card>& sub_hand) {
    //if(is_straight_flush(sub_hand) && sub_hand[0].get_rank() > 0) return true;
    return is_straight_flush(sub_hand) && sub_hand[0].get_rank() > 0;
    //return false;
}

bool PokerHand::is_straight_flush(const std::vector<Card>& sub_hand) {
    //if(is_straight(sub_hand) && is_flush(sub_hand)) return true;
    return is_straight(sub_hand) && is_flush(sub_hand);
    //return false;
}

int PokerHand::has_x_of_a_kind(const int& x, const std::vector<Card>& sub_hand) {
    std::vector<std::vector<Card>> groups_of_x = combinations(sub_hand, x);
    for(const std::vector<Card>& x_hand: groups_of_x) {
        int rank = x_hand[0].get_rank();
        bool has_it = true;
        for(const Card& c: x_hand) {
            if(c.get_rank() != rank) {
                has_it = false;
                break;
            }
        }
        if(has_it) {
            return rank;
        }
    }
    return -1;
}

std::pair<int, int> PokerHand::has_x_y_of_a_kind(const int& x, const int& y, const std::vector<Card>& sub_hand) {
    std::pair<int, int> result (-1, -1);
    std::vector<std::vector<Card>> groups_of_x = combinations(sub_hand, x);
    for(const std::vector<Card>& x_hand: groups_of_x) {
        std::vector<Card> y_hand;
        for(const Card& card: sub_hand) {
            if(std::find(std::begin(x_hand), std::end(x_hand), card) == std::end(sub_hand)) y_hand.push_back(card);
        }
        if(x_hand.size() + y_hand.size() != sub_hand.size()) std::cout << "ERROR" << std::endl;
        int x_hand_result = has_x_of_a_kind(x, x_hand);
        int y_hand_result = has_x_of_a_kind(y, y_hand);
        if(x_hand_result >= 0 && y_hand_result >= 0) {
            result.first = x_hand_result;
            result.second = y_hand_result;
            return result;
        }
    }
    return result;
}
