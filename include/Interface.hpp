#ifndef Interface_hpp
#define Interface_hpp

#include "Arquive.hpp"
#include "KenoBet.hpp"

#include <iostream>

class Interface {
    public:
        /*! Reads the file with bet and wage. */
        bool start(KenoBet &player, Arquive &file_bet, int argc, char *argv[]);

        /*! Shows the initial informations. */
        void show_initial(KenoBet &player);

        /*! Shows rounds informations. */
        void show_game(KenoBet &player, int current_round);

        /*! Shows final informations. */
        void show_summary(KenoBet &player);
};


/*! Resets the console. */
void reset(void);

#endif