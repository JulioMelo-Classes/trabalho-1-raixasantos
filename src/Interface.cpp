#include "Arquive.hpp"
#include "Interface.hpp"
#include "KenoBet.hpp"

#include <iostream>
#include <string>
#include <iomanip>

/*! Resets the console.*/
void reset(void)
{
    system("clear");
}

/*! Reads the file with bet and wage. */
void Interface::start(KenoBet &player, Arquive &file_bet, int argc, char *argv[])
{   
    std::string local_ = argv[1];

    if(local_.find(".dat") != std::string::npos)
        file_bet.set_local(local_);
    else
        file_bet.set_local("data/bet_1.dat"); // error message

    std::cout << ">>> Lendo arquivo de apostas [" << file_bet.get_local() << 
                "], por favor aguarde..." << std::endl; 
    std::cout << "------------------------------------------" <<
                "----------------------------" << std::endl;   

    if(read_lines(file_bet, player))
        show_initial(player);
    else
    {   
        reset();
        std::cout << "Aposta inválida! Tente novamente: " << std::endl;
    }
}

/*! Shows the initial informations. */
void Interface::show_initial(KenoBet &player)
{
    std::cout << ">>> Aposta lida com sucesso!\n    Você apostará um total de $" << player.get_wage() 
            << " créditos.\n    Jogará um total de " << player.NR 
            << " rodadas, apostando $" << std::setprecision(5) << player.IC 
            << " créditos por rodada.\n" << std::endl;

    std::cout << "    Sua aposta tem " << player.size()
            << " números, eles são: [ ";
    for(auto spot : player.get_spots())
    {
        std::cout << spot << " ";
    }
    std::cout << "]\n" << std::endl;
}
