//
//  deck.h
//  poker
//
//  Created by Ben Ellis on 7/15/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#ifndef deck_h
#define deck_h

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

#include "card.h"

class Deck {
public:
    Deck();
    Deck(const bool& fill);
    ~Deck();
    void sort();
    void shuffle();
    Card draw_delete_back();
    Card draw_delete_front();
    void delete_card(const Card& c);
    void add_back(const Card& c);
    void add_front(const Card& c);
    bool find(const Card& c) const;
    void show() const;
    static std::string display_card(const Card& c);
    long size() const;
protected:
    std::vector<Card> deck_;
    //static const unsigned SEED_;
    static const std::vector<std::string> SUITS_;
    static const std::vector<std::string> RANKS_;
    std::default_random_engine rand_eng_;
};



#endif /* deck_h */
