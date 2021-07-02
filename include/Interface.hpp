#ifndef Interface_hpp
#define Interface_hpp

#include "Arquive.hpp"
#include "KenoBet.hpp"

#include <iostream>

class Interface {
    public:
        /*! Reads the file with bet and wage. */
        void start(KenoBet &player, Arquive &file_bet, int argc, char *argv[]);

        /*! Shows the initial informations. */
        void show_initial(KenoBet &player);
};


/*! Resets the console. */
void reset(void);

#endif