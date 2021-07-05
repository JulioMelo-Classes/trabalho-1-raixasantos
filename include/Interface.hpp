#ifndef Interface_hpp
#define Interface_hpp

#include "Arquive.hpp"
#include "KenoBet.hpp"

#include <iostream>
#include <string>
#include <iomanip> // std::setprecision

class Interface {
    public:
        
        /*! Reads the file with bet and other information.
            @param player The KenoBet's object.
            @param file_bet The Arquive's object.
            @param argc The number of command-line arguments passed.
            @param argv The list of all the arguments.
            @return T If all information from command-line is ok. F Otherwise. */
        bool start(KenoBet &player, Arquive &file_bet, int argc, char *argv[]);

        /*! Shows the initial information. 
            @param player The KenoBet's object.
            @return void */
        void show_initial(KenoBet &player);

        /*! Shows rounds information. 
            @param player The KenoBet's object.
            @param current_round Index of the current round. 
            @return void */
        void show_game(KenoBet &player, int current_round);

        /*! Shows final information.
            @param player The KenoBet's object.
            @return void */
        void show_summary(KenoBet &player);
};

#endif