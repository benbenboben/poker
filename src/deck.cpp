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
#include <cstdlib>

#include "deck.h"
#include "card.h"

const std::vector<std::string> Deck::SUITS_ = {"s"};//, "c", "h", "d"};
const std::vector<std::string> Deck::RANKS_ = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
const unsigned Deck::SEED_ = std::chrono::system_clock::now().time_since_epoch().count();

Deck::Deck() {
    
}

Deck::Deck(const bool& fill) {
    if(fill) {
        for(int isuit = 0; isuit < SUITS_.size(); isuit++) {
            for(int irank=0; irank < RANKS_.size(); irank++) {
                // Card c(isuit, irank, SUITS_[isuit], RANKS_[irank]);
                Card c(isuit, irank);
                deck_.push_back(c);
            }
        }
    }
}

Deck::~Deck() {
    
}

void Deck::sort() {
    std::sort(deck_.begin(), deck_.end());
}

void Deck::shuffle() {
    //std::shuffle(deck_.begin(), deck_.end(), std::default_random_engine(SEED_));
    //for(int i = 0; i < deck_.size(); i++) {
    //    unsigned int j = std::rand() % deck_.size();
    //    std::swap(deck_[i], deck_[j]);
    //}
    std::shuffle(std::begin(deck_), std::end(deck_), std::default_random_engine(SEED_));
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
    deck_.push_back(c);
}

void Deck::add_front(const Card& c) {
    deck_.insert(std::begin(deck_), c);
}

bool Deck::find(const Card& c) const {
    return std::find(std::begin(deck_), std::end(deck_), c) != std::end(deck_);
}

void Deck::delete_card(const Card& c) {
    std::vector<Card>::iterator pos;
    pos = std::find(std::begin(deck_), std::end(deck_), c);
    if(pos != std::end(deck_)) deck_.erase(pos);
}

void Deck::show() const {
    if(deck_.size() == 0) {
        std::cout << "No cards!" << std::endl;
    }
    for(const Card& c: deck_) {
        std::cout << display_card(c) << " ";
    }
    std::cout << std::endl;
}

std::string Deck::display_card(const Card& c) const {
    std::string card = RANKS_[c.get_rank()] + SUITS_[c.get_suit()];
    return card;
}

long Deck::size() const {
    return deck_.size();
}