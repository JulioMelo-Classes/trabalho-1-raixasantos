#include "Arquive.hpp"
#include "Interface.hpp"
#include "KenoBet.hpp"

#include <iostream>

/*! Resets the console.*/
void Interface::reset(void)
{
    system("clear");
}

/*! Reads the file with bet and wage. */
void Interface::start(int argc, char *argv[])
{
    // Chamar função do Arquive.hpp
    std::cout << "Lendo arquivo de apostas [" << argv[1] << 
                "], por favor aguarde..." << std::endl; 
    std::cout << "------------------------------------------" <<
                "----------------------------" << std::endl;   
}

/*! Shows the initial informations. */
void Interface::show_initial(void)
{
    KenoBet player;
    std::cout << "Você apostará um total de $" << player.get_wage() 
            << " créditos.\n Jogará um total de " << player.size() 
            << " rodadas, apostando $" << " créditos por rodada.";
}
