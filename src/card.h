//
//  card.h
//  poker
//
//  Created by Ben Ellis on 7/14/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#ifndef card_h
#define card_h

#include <iostream>

class Card {
public:
    // Card(unsigned int suit, unsigned int rank, const bool order_suits);
    Card();
    Card(int suit, int rank);
    Card(int suit, int rank, std::string str_suit, std::string str_rank);
    ~Card();
    int get_suit() const;
    int get_rank() const;
    bool operator<(const Card& rhs) const;
    bool operator>(const Card& rhs) const;
    bool operator<=(const Card& rhs) const;
    bool operator>=(const Card& rhs) const;
    bool operator==(const Card& rhs) const;
    bool operator!=(const Card& rhs) const;
    void operator=(const Card& rhs);
    void show() const;
    std::string str() const;
    std::string get_str_suit() const;
    std::string get_str_rank() const;
private:
    int suit_;
    int rank_;
    std::string str_suit_;
    std::string str_rank_;
    static const bool order_suits_ = false;
};

//bool cmp(const Card& lhs, const Card& rhs);


// const bool Card::order_suits_ = false;

#endif /* card_h */
