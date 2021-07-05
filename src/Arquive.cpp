#include "Arquive.hpp"
#include "KenoBet.hpp"
#include "Operations.hpp"

// Determines the file's path.
void Arquive::set_local(std::string local_)
{
    local = local_;
}

// Retrieves the file's path.
std::string Arquive::get_local(void)
{
    return local;
}

// Reads data written to a file passed by command-line. 
bool read_lines(Arquive &file_bet, KenoBet &player){
    std::ifstream file;             //<! File will be opened.
    std::vector<std::string> lines;

    file.open(file_bet.get_local());

    if(file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "    [Erro] Arquivo vazio ou inexistente!\n";
        return false;
    }
    else
    {
        while(!file.eof())
        {
            std::string texto;
            getline(file, texto);
            lines.push_back(texto);
        }
    }

    if(!set_infos(lines, player)) // If have something wrong with the informations.
    {
        return false;
    }

    file.close();

    return true;
}

// Checks if the line contains something besides numbers.
bool others_symbols(std::string line)
{
    std::size_t procurar;

    procurar = line.find_first_not_of("0123456789. ");
    if(procurar != std::string::npos)
    {
        std::cout << "   [Erro] Caractere estranho: " 
                << line[procurar] << std::endl;
        return true;
    }

    return false;
}

// Checks if the line contains some space.
bool space_between(std::string line)
{
    if(line.find(" ") != std::string::npos)
    {
        std::cout << "    [Erro] Espaço indevido!" << std::endl;
        return true;
    }
    return false;
}

// Pass all information from the file to the KenoBet's object.
bool set_infos(std::vector<std::string> & lines, KenoBet &player)
{
    for(int i = 0; i < lines.size(); i++)
    {
        if(others_symbols(lines[i]))
            return false;
        if(i != 2 && space_between(lines[i]))
            return false;
        if(i > 2) // More then 3 lines
        {
            std::cout << "    [Erro] Formatação da aposta inválida!" << std::endl;
            return false;
        }
    }

    std::stringstream ss_ic, ss_nr, ss_spots;
    cash_type IC_;
    int NR;
    number_type spot_, greater_ = 81, less_ = 0;
    set_of_numbers_type v_spot_;

    // ------------- Credits --------------------
    ss_ic << lines[0];
    ss_ic >> IC_;
    if(IC_ < 1)
    {
        std::cout << "    [Erro] Valor de aposta inválido." << std::endl;
        return false;
    }

    player.set_IC(IC_);

    // ------------- Number of rounds --------------------    
    ss_nr << lines[1];
    ss_nr >> NR;
    if(NR < 1)
    {
        std::cout << "    [Erro] Número de rodadas inválido." << std::endl;
        return false;
    }

    player.set_NR(NR);

    if(player.get_IC()/(cash_type) player.get_NR() <= 0)
    {
        std::cout << "    [Erro] Valor de aposta inválido." << std::endl;
        return false; // Invalid credits
    }
    
    player.set_wage(player.get_IC()/(cash_type) player.get_NR());

    // ------------- Spots --------------------    
    ss_spots << lines[2];
    while(!ss_spots.eof())
    { 
        ss_spots >> spot_;
        if(spot_ < 0 || spot_ > 80)
        {
            std::cout << "    [Erro] Número inválido: " 
                    << spot_ << std::endl;
            return false;
        }

        for(auto r = v_spot_.begin(); r != v_spot_.end(); r++)
        {
            if(*r == spot_)
            {
                std::cout << "    [Erro] Número Repetido: " 
                    << *r << std::endl;
                return false;
            }
        }
        v_spot_.push_back(spot_);   
    }      

    if(v_spot_.size() < 1 || v_spot_.size() > 15) // Verify the number of spots.
    {
        std::cout << "    [Erro] 1 < Qtd de números apostados > 15." << std::endl;
        return false;
    }

    sort_spots(v_spot_); // Sorts the player's spots.
    player.add_number(v_spot_);  // Adds the spots in m_spots.

    return true;
}