//
//  main.cpp
//  poker
//
//  Created by Ben Ellis on 7/14/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#include "poker_game.h"
#include <algorithm>

int main(int argc, const char * argv[]) {
    std::string prompt;
    std::cout << " ===================================== " << std::endl;
    std::cout << " === TEXAS HOLD'EM ODDS CALCULATOR === " << std::endl;
    std::cout << " ===================================== " << std::endl;
    std::cout << sizeof(short) << " " << sizeof(int) << std::endl;
    do {
        PokerGame game;
        game.init_hand();
        game.init_community();
        //game.monte_carlo_omp_wrap(20000);
        game.monte_carlo_loop();
        std::cout << "Would you like to do another hand (y or n)? ";
        std::cin >> prompt;
        for(auto x: prompt) std::tolower(x);
        std::cout << std::endl;
    } while(prompt.at(0) == 'y');
    return 0;
}


