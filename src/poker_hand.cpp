//
//  poker_hand.cpp
//  poker
//
//  Created by Ben Ellis on 7/15/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#include "poker_hand.h"
#include "misc.h"

enum class HANDS {HIGH, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH, ROYAL_FLUSH};

PokerHand::PokerHand() : Deck(false) {
    
};

PokerHand::PokerHand(const std::vector<Card>& cards) {
    deck_ = cards;
}

/*
void PokerHand::generate_all_hands(const int& offset, const int& k, std::vector<Card>& tmp, std::vector<std::vector<Card>>& all_hands) const {
    if(k == 0) {
        all_hands.push_back(tmp);
        return;
    }
    for(int i = offset; i <= MAX_HAND_ - k; ++i) {
        tmp.push_back(deck_[i]);
        generate_all_hands(i + 1, k - 1, tmp, all_hands);
        tmp.pop_back();
    }
}
*/
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
    if(is_straight_flush(sub_hand) && sub_hand[0].get_rank() > 0) return true;
    return false;
}

bool PokerHand::is_straight_flush(const std::vector<Card>& sub_hand) {
    if(is_straight(sub_hand) && is_flush(sub_hand)) return true;
    return false;
}

bool PokerHand::has_four_of_a_kind(const std::vector<Card>& sub_hand) {
    std::vector<std::vector<Card>> groups_of_four = combinations(sub_hand, 4);
    for(const std::vector<Card>& h: groups_of_four) {
        int rank = h[0].get_rank();
        bool has_it = true;
        for(const Card& c: h) {
            if(c.get_rank() != rank) {
                has_it = false;
                break;
            }
        }
        if(has_it) {
            //special_value_1_ = rank;
            return true;
        }
    }
    return false;
}
