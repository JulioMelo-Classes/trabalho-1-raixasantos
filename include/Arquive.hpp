#ifndef Arquive_hpp
#define Arquive_hpp

#include "KenoBet.hpp"

#include <iostream>
#include <vector>
#include <string>

class Arquive {
    public:
        /*! Determina o local do arquivo
            std::string local_ string que possui o endereço do arquivo*/
        void set_local(std::string local_);

        /*! Pega o local do arquivo*/
        std::string get_local(void);

    private:
        /*! String que guarda o local do arquivo*/
        std::string local;
};


/*! Leitura do Arquivo e atribuição dos valores da aposta*/
bool read_lines(Arquive &file_bet, KenoBet &player);

/*! Verificar a presença de caracteres estranhos.
* @param line Texto a ser verificado.
* @return Verdadeiro, se houver caracteres estranhos. Caso contrário, retorna falso.
*/
bool others_symbols(std::string s_test);

/*! Verificar se há " ".
* @param line
*/
bool space_between(std::string line);

/*! */
bool set_infos(std::vector<std::string> & lines, KenoBet &player);

#endif