//
//  main.cpp
//  poker
//
//  Created by Ben Ellis on 7/14/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
//#include <ncurses.h>

#include "card.h"
#include "deck.h"
#include "poker_hand.h"
#include "misc.h"


int main(int argc, const char * argv[]) {
    //initscr();			/* Start curses mode 		  */
    //printw("Hello World !!!");	/* Print Hello World		  */
    //refresh();			/* Print it on to the real screen */
    //getch();			/* Wait for user input */
    //endwin();			/* End curses mode		  */
    //return 0;
    
    Deck deck(true);
    //std::cout << "original deck" << std::endl;
    //deck.show();
    //deck.shuffle();
    //std::cout << "shuffled deck" << std::endl;
    //deck.show();
    
    PokerHand hand_1;
    for(int i = 0; i < 5; i++) hand_1.add_back(deck.draw_delete_back());
    std::cout << "hand" << std::endl;
    hand_1.sort();
    hand_1.show();
    //std::cout << "all hands" << std::endl;
    //hand_1.print_all_hands();
    hand_1.score_hand();
    
    deck = Deck(true);
    
    PokerHand hand_2;
    for(int i = 0; i < 6; i++) hand_2.add_back(deck.draw_delete_front());
    hand_2.add_back(deck.draw_delete_back());
    Card tmp = hand_2.draw_delete_front();
    tmp = hand_2.draw_delete_front();
    hand_2.sort();
    hand_2.show();
    hand_2.score_hand();
    
    deck = Deck(true);
    
    PokerHand hand_3;
    for(int i = 0; i < 4; i++) hand_3.add_back(deck.draw_delete_front());
    hand_3.add_back(deck.draw_delete_back());
    //Card tmp = hand_3.draw_delete_front();
    //tmp = hand_3.draw_delete_front();
    hand_3.sort();
    hand_3.show();
    hand_3.score_hand();
    return 0;
}
