#include "Arquive.hpp"
#include "KenoBet.hpp"
#include "Interface.hpp"
#include "Operations.hpp"

int main(int argc, char *argv[]) {
    Interface interface;
    Arquive file_bet;
    KenoBet player;

    interface.start(player, file_bet, argc, argv);    
}
