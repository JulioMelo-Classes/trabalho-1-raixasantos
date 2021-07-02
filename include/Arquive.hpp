#ifndef Arquive_hpp
#define Arquive_hpp

#include "KenoBet.hpp"

#include <iostream>
#include <vector>
#include <string>

class Arquive {
    public:
        /*! */
        void set_local(std::string local_);

        /*! */
        std::string get_local(void);

    private:
        /*! */
        std::string local;
};


/*! */
bool read_lines(Arquive &file_bet, KenoBet &player);

/*! */
void set_infos(std::vector<std::string> & lines, KenoBet &player);

#endif