#include "Arquive.hpp"
#include "KenoBet.hpp"
#include "Operations.hpp"

#include <fstream>
#include <sstream>
#include <string> 

/*! Set's the file local*/
/*! Determina o local do arquivo de apostas */
void Arquive::set_local(std::string local_)
{
    local = local_;
}

/*! Get's the file local*/
/*! Entrega o local do arquivo de apostas */
std::string Arquive::get_local(void)
{
    return local;
}

/*! Read the arquive and determine if is valid
    @return T if is valid F otherwise*/
/*! Ler o arquivo e determina se ele é válido ou não 
    @return T se for válido F se não*/
bool read_lines(Arquive &file_bet, KenoBet &player){
    std::ifstream file;
    std::vector<std::string> lines;

    file.open(file_bet.get_local());

    if(file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Arquivo vazio!\n"; // error message
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

    if(!set_infos(lines, player)) // caso tiver algo errado com as infos
        return false;

    file.close();

    return true;
}

/*! Verificar a presença de caracteres estranhos.
    @param line Texto a ser verificado.
    @return Verdadeiro, se houver caracteres estranhos. Caso contrário, retorna falso.
*/
bool others_symbols(std::string line)
{
    std::size_t procurar;

    procurar = line.find_first_not_of("0123456789. ");
    if(procurar != std::string::npos)
    {
        std::cout << "Error Message: linha 1 Caractere estranho: " 
                << line[procurar] << std::endl;
        return true;
    }

    return false;
}

/*! Verificar se há " ".
* @param line
*/
bool space_between(std::string line)
{
    if(line.find(" ") != std::string::npos)
    {
        std::cout << "Error Message: espaço indevido" << std::endl;
        return true;
    }
    return false;
}

/*! Coleta as informações da aposta de dentro do arquivo*/
bool set_infos(std::vector<std::string> & lines, KenoBet &player)
{
    for(int i = 0; i < lines.size(); i++)
    {
        if(others_symbols(lines[i]))
            return false;
        if(i != 2 && space_between(lines[i]))
            return false;
    }

    std::stringstream ss_ic, ss_nr, ss_spots;
    cash_type IC_;
    int NR;
    number_type spot_;
    set_of_numbers_type v_spot_;

    // ------------- Créditos --------------------
    ss_ic << lines[0];
    ss_ic >> IC_;
    player.set_IC(IC_);

    // ------------- Nº de rodadas --------------------    
    ss_nr << lines[1];
    ss_nr >> NR;
    player.set_NR(NR);
    if(player.get_IC()/(cash_type) player.get_NR() <= 0)
        return false; // valor de crédito por rodada inválido
    player.set_wage(player.get_IC()/(cash_type) player.get_NR());

    // ------------- Números --------------------    
    ss_spots << lines[2];
    while(!ss_spots.eof())
    { 
        ss_spots >> spot_;
        for(auto r = v_spot_.begin(); r != v_spot_.end(); r++)
        {
            if(*r == spot_)
            {
                std::cout << "Error Messeger: Número Repetido " << std::endl;
                return false;
            }
        }
        v_spot_.push_back(spot_);   
    }      

    if(v_spot_.size() <= 0 || v_spot_.size() > 15)
    {
        std::cout << "Error Messeger: > 15 " << std::endl;
        return false;
    }

    sort_spots(v_spot_);
    player.add_number(v_spot_);  

    return true;
}