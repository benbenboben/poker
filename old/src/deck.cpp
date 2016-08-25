//
//  deck.cpp
//  poker
//
//  Created by Ben Ellis on 7/15/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

#include "deck.h"
#include "card.h"

const std::vector<std::string> Deck::SUITS_ = {"s", "c", "h", "d"};
const std::vector<std::string> Deck::RANKS_ = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};


Deck::Deck(const bool& fill) {

}

Deck::Deck() {
    repopulate();
    //for(int isuit = 0; isuit < SUITS_.size(); isuit++) {
    //    for(int irank=0; irank < RANKS_.size(); irank++) {
    //        // Card c(isuit, irank, SUITS_[isuit], RANKS_[irank]);
    //        Card c(isuit, irank);
    //        deck_.push_back(c);
    //    }
    //}
    rand_eng_.seed(time(0));
}

Deck::~Deck() {

}

void Deck::sort() {
    std::sort(deck_.begin(), deck_.end());
}

void Deck::shuffle() {
    std::shuffle(std::begin(deck_), std::end(deck_), rand_eng_);
}

Card Deck::draw_delete_back() {
    Card tmp = deck_.back();
    deck_.pop_back();
    return tmp;
}

Card Deck::draw_delete_front() {
    Card c = deck_.front();
    deck_.erase(std::begin(deck_));
    return c;
}

void Deck::add_back(const Card& c) {
    if(!find(c)) deck_.push_back(c);
}

void Deck::add_front(const Card& c) {
    if(!find(c)) deck_.insert(std::begin(deck_), c);
}

bool Deck::find(const Card& c) const {
    return std::find(std::begin(deck_), std::end(deck_), c) != std::end(deck_);
}

void Deck::delete_card(const Card& c) {
    std::vector<Card>::iterator pos;
    pos = std::find(std::begin(deck_), std::end(deck_), c);
    if(pos != std::end(deck_)) deck_.erase(pos);
}

void Deck::show(const std::vector<Card>& hand) {
    if(hand.size() == 0) {
        std::cout << "No cards!" << std::endl;
    }
    for(const Card& c: hand) {
        std::cout << display_card(c) << " ";
    }
    std::cout << std::endl;
}

std::string Deck::display_card(const Card& c) {
    std::string card = c.str();
    return card;
}

long Deck::size() const {
    return deck_.size();
}

Card Deck::draw_delete_rand_card() {
    std::uniform_int_distribution<> d(0, deck_.size() - 1);
    Card c = deck_[d(rand_eng_)];
    delete_card(c);
    return c;
}

const std::vector<Card>& Deck::get_deck() {
    return deck_;
}

void Deck::add_front(const std::vector<Card> &c) {
    for(const Card& i: c) {
        add_front(i);
    }
}

void Deck::add_back(const std::vector<Card> &c) {
    for(const Card &i: c) {
        add_back(i);
    }
}

void Deck::clear() {
    deck_.clear();
}

bool Deck::empty() {
    return deck_.empty();
}

void Deck::repopulate() {
    clear();
    for(int isuit = 0; isuit < SUITS_.size(); isuit++) {
        for(int irank=0; irank < RANKS_.size(); irank++) {
            // Card c(isuit, irank, SUITS_[isuit], RANKS_[irank]);
            Card c(isuit, irank, SUITS_[isuit], RANKS_[irank]);
            deck_.push_back(c);
        }
    }
}

std::string Deck::str() {
    std::string ans = "";
    int i = 0;
    for(const Card& c: deck_) {
        ++i;
        ans += c.str() + " ";
        if(i % 13 == 0) ans += "\n";
    }
    return ans;
}

bool Deck::find(const std::string& suit, const std::string& rank) const {
    return find(generate_card(suit, rank));
}

void Deck::add_front(const std::string& suit, const std::string& rank) {
    if(!find(suit, rank)) {
        add_front(generate_card(suit, rank));
    }
}

void Deck::add_back(const std::string& suit, const std::string& rank) {
    if(!find(suit, rank)) {
        add_back(generate_card(suit, rank));
    }
}

void Deck::delete_card(const std::string& suit, const std::string& rank) {
    Card c = generate_card(suit, rank);
    if(find(c)) {
        delete_card(c);
    }
}

Card Deck::generate_card(const std::string& suit, const std::string& rank) const {
    std::vector<std::string>::const_iterator it_suit = std::find(std::begin(SUITS_), std::end(SUITS_), suit);
    std::vector<std::string>::const_iterator it_rank = std::find(std::begin(RANKS_), std::end(RANKS_), rank);
    int isuit = std::distance(std::begin(SUITS_), it_suit);
    int irank = std::distance(std::begin(RANKS_), it_rank);
    Card c(isuit, irank, SUITS_[isuit], RANKS_[irank]);
    return c;
}
