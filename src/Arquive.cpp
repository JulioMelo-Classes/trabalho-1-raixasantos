#include "Arquive.hpp"
#include "KenoBet.hpp"

#include <fstream>
#include <sstream>

/*! */
void Arquive::set_local(std::string local_)
{
    local = local_;
}

/*! */
std::string Arquive::get_local(void)
{
    return local;
}

/*! */
bool read_lines(Arquive &file_bet, KenoBet &player){
    std::ifstream file1;
    std::vector<std::string> lines;

    file1.open(file_bet.get_local());

    if(file1.is_open())
    {   
        while(!file1.eof()){
            std::string texto;
            getline(file1, texto);
            lines.push_back(texto);
        }
    }

    if(lines.empty())
        std::cout << "Arquivo vazio! Tente novamente: \n"; // error message

    file1.close();

    set_infos(lines, player);

    return true; // conditions
}

/*! */
void set_infos(std::vector<std::string> & lines, KenoBet &player)
{
    std::stringstream ss_wage, ss_nr, ss_spots;

    ss_wage << lines[0];
    cash_type wage_;
    ss_wage >> wage_;
    player.set_wage(wage_);

    ss_nr << lines[1];
    int NR;
    ss_nr >> NR;
    player.NR = NR;

    player.IC = player.get_wage()/(cash_type) player.NR;

    ss_spots << lines[2];
    number_type spot_;
    set_of_numbers_type v_spot_;
    while(!ss_spots.eof())
    { 
        ss_spots >> spot_;
        v_spot_.push_back(spot_);   
    }      

    // Ordenar o v_spot_

    player.add_number(v_spot_);  
}

/*
    std::vector<char> verify_elements = {'0', '1', '2', '3', '4', '5', '6', 
                            '7', '8', '9', '.', ' '};  

*/