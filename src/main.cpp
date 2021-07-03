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
        for(int i = 0; i < rounds; i++)
        {
            interface.show_game(player, i+1);
        }

        interface.show_summary(player);
    }

    player.reset();
}
