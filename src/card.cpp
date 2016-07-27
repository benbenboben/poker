//
//  card.cpp
//  poker
//
//  Created by Ben Ellis on 7/14/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#include "card.h"

Card::Card() {
    
}

Card::~Card() {
    
}

Card::Card(int suit, int rank) {
    suit_ = suit;
    rank_ = rank;
    str_suit_ = "";
    str_rank_ = "";
}

Card::Card(int suit, int rank, std::string str_suit, std::string str_rank) {
    suit_ = suit;
    rank_ = rank;
    str_suit_ = str_suit;
    str_rank_ = str_rank;
}

int Card::get_rank() const {
    return rank_;
}

int Card::get_suit() const {
    return suit_;
}

bool Card::operator<(const Card& rhs) const {
    if(!order_suits_) return rank_ < rhs.get_rank();
    if(suit_ != rhs.get_suit()) return suit_ < rhs.get_suit();
    return rank_ < rhs.get_rank();
}

bool Card::operator>(const Card& rhs) const {
    return !(*this < rhs);
}

bool Card::operator==(const Card& rhs) const {
    return (suit_ == rhs.get_suit() && rank_ == rhs.get_rank());
}

bool Card::operator!=(const Card& rhs) const {
    return !(*this == rhs);
}

bool Card::operator<=(const Card& rhs) const {
    return (*this < rhs || *this == rhs);
}

bool Card::operator>=(const Card& rhs) const {
    return (*this > rhs || *this == rhs);
}

void Card::operator=(const Card& rhs) {
    suit_ = rhs.get_suit();
    rank_ = rhs.get_rank();
    str_suit_ = rhs.get_str_suit();
    str_rank_ = rhs.get_str_rank();
}

std::string Card::get_str_suit() const {
    return str_suit_;
}

std::string Card::get_str_rank() const {
    return str_rank_;
}

void Card::show() const {
    std::cout << (*this).str() << std::endl;
}

std::string Card::str() const {
    std::string str_card;
    str_card = std::to_string(suit_) + std::to_string(rank_);
    if(str_suit_ != "" || str_rank_ != "") str_card = str_rank_ + str_suit_;
    return str_card;
}
