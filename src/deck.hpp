//
//  deck.hpp
//  poker_calculator
//
//  Created by Ben Ellis on 7/15/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#ifndef deck_hpp
#define deck_hpp

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

#include "card.hpp"

class Deck {
public:
    Deck();
    Deck(const bool& fill);
    ~Deck();
    void sort();
    void shuffle();
    Card draw_delete_back();
    Card draw_delete_front();
    Card draw_delete_rand_card();
    Card draw_delete_card(const Card& c);
    Card draw_delete_card(const std::string& suit, const std::string& rank);
    Card generate_card(const std::string& suit, const std::string& rank) const;
    const std::vector<Card>& get_deck();
    void delete_card(const Card& c);
    void delete_card(const std::string& suit, const std::string& rank);
    void add_front(const Card& c);
    void add_back(const Card& c);
    void add_front(const std::vector<Card>& c);
    void add_back(const std::vector<Card>& c);
    void add_front(const std::string& suit, const std::string& rank);
    void add_back(const std::string& suit, const std::string& rank);
    bool find(const Card& c) const;
    bool find(const std::string& suit, const std::string& rank) const;
    static void show(const std::vector<Card>& hand);
    static std::string display_card(const Card& c);
    long size() const;
    void repopulate();
    void clear();
    bool empty();
    std::string str();
protected:
    std::vector<Card> deck_;
    std::default_random_engine rand_eng_;
    static const std::vector<std::string> SUITS_;
    static const std::vector<std::string> RANKS_;
};



#endif /* deck_hpp */
