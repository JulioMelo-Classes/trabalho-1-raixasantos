#include "Arquive.hpp"
#include "Interface.hpp"
#include "KenoBet.hpp"
#include "Operations.hpp"

#include <iostream>
#include <string>
#include <iomanip>

/*! Resets the console.
    @return void 
*/
void reset(void)
{
    system("clear");
}

/*! Reads the file with bet and wage. 
    @param
*/
bool Interface::start(KenoBet &player, Arquive &file_bet, int argc, char *argv[])
{   
    std::string local_ = argv[1];

    if(local_.find(".dat") != std::string::npos)
        file_bet.set_local(local_);
    else
        file_bet.set_local("data/bet_1.dat"); // error message

    std::cout << ">>> Lendo arquivo de apostas [" << file_bet.get_local() << 
                "], por favor aguarde..." << std::endl;   

    if(read_lines(file_bet, player))
    {
        show_initial(player);
        return true;
    }
    else
    {   
        reset();
        std::cout << "Aposta inválida! Tente novamente: " << std::endl; // receber qual a error message
        return false;
    }
}

/*! Shows the initial informations. */
void Interface::show_initial(KenoBet &player)
{   
    std::cout << "------------------------------------------" <<
                "----------------------------" << std::endl;
    std::cout << ">>> Aposta lida com sucesso!\n    Você apostará um total de $" << player.get_IC() 
            << " créditos.\n    Jogará um total de " << player.get_NR() 
            << " rodadas, apostando $" << std::setprecision(5) << player.get_wage()
            << " créditos por rodada.\n" << std::endl;

    if(player.size() > 1){
        std::cout << "    Sua aposta tem " << player.size()
            << " números, eles são: [ ";
    }
    else
    {
        std::cout << "    Sua aposta tem " << player.size()
            << " número, ele é: [ ";
    }
    
    for(auto spot : player.get_spots())
    {
        std::cout << spot << " ";
    }
    std::cout << "]" << std::endl;

    std::cout << "    -----------+-----------" << std::endl
              << "    Hits       | Retorno" << std::endl;

    for(int j = 0; j < player.size()+1; j++){
            std::cout << "    " << j << "          | " << player.payoff_table[player.size()-1][j] << std::endl;
    }
}


/*
    player.IC -> crédito inicial (valor que coloca no inicio)

    player.wage -> valor por rodada

    player.current_credits -> valor ao longo das partidas
*/

/*! Shows rounds informations. */
void Interface::show_game(KenoBet &player, int current_round)
{
    if(current_round == 1)
        player.set_current_credits(player.get_IC());

    std::cout << "------------------------------------------" <<
                "----------------------------" << std::endl;
    std::cout << "    Esta é a rodada #" << current_round 
            << " de " << player.get_NR() << ", sua aposta é $"
            << player.get_wage() << ". Boa sorte!" << std::endl;

    player.set_current_credits(player.get_wage()*-1);

    std::cout << "    Os números sorteados são: [ "; 
    set_of_numbers_type numbers_to_check = v_numbers_random();
    for(auto i : numbers_to_check)
    {
        std::cout << i << " ";
    }
    std::cout << "]\n" << std::endl;

    set_of_numbers_type player_hits = player.get_hits(numbers_to_check);
    std::cout << "    Você acertou os números [ "; 
    for(auto i = player_hits.begin(); i != player_hits.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << "], um total de " << player_hits.size() << " hits de " 
            << player.size() << std::endl;
    
    cash_type rate = player.payoff_table[player.size()-1][player_hits.size()];
    
    std::cout << "    Sua taxa de retorno é " 
            << rate << ", assim você sai com: $" 
            << player.get_wage() * rate << std::endl;

    
    player.set_current_credits(player.get_wage() * rate);
    std::cout << "    Você possui um total de: $" << player.get_current_credits() 
            << " créditos." << std::endl;

    if(current_round == player.get_NR())
    {
        std::cout<<">>>> Fim de rodadas" << std::endl;        
    }
}

/*! Shows final informations. */
void Interface::show_summary(KenoBet &player)
{
    std::cout << "------------------------------------------" <<
                "----------------------------" << std::endl;
    std::cout << "    ======= Sumário =======" << std::endl;
    std::cout << "    >>> Você gastou um total de $"
            << player.get_IC() << " créditos" << std::endl;

    cash_type diference = player.get_current_credits() - player.get_IC();
    if(diference < 0)
    {
        std::cout << "    >>> Que pena! você perdeu $"
                << diference*-1
                << " créditos!" << std::endl;
    }
    else
    {
        std::cout << "    >>> Hooray! você ganhou $"
                << diference
                << " créditos!" << std::endl;
    }
    std::cout << "    >>> Você está saindo do jogo com um total de $"
            << player.get_current_credits() << " créditos.\n" << std::endl;

}