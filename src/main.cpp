#include "Arquive.hpp"
#include "KenoBet.hpp"
#include "Interface.hpp"
#include "Operations.hpp"

int main(int argc, char *argv[]) {
    Interface interface;
    Arquive file_bet;
    KenoBet player;

    if(interface.start(player, file_bet, argc, argv))    
    {
        number_type rounds = player.get_NR();
        for(int i = 1; i < rounds+1; i++)
        {
            interface.show_game(player, i);
        }

        interface.show_summary(player);
    }

    player.reset();
}
