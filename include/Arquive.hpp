#ifndef Arquive_hpp
#define Arquive_hpp

#include "KenoBet.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class Arquive {
    public:
        /*! Determines the file's path.
            @param local_ The file's path.. */
        void set_local(std::string local_);

        /*! Retrieves the file's path.
            @return The file's path. */
        std::string get_local(void);

    private:
        std::string local; //<! The file's path.
};

/*! Reads data written to a file passed by command-line. 
    @param file_bet The Arquive's object.
    @param player The KenoBet's object.
    @return T If all information is successfully read. F Otherwise.*/
bool read_lines(Arquive &file_bet, KenoBet &player);

/*! Checks if the line contains something besides numbers.
    @param line Bet's file line.
    @return T If the line contains something. F Otherwise. */
bool others_symbols(std::string line);

/*! Checks if the line contains some space.
    @param line Bet's file line. 
    @return T If the line contains " ". F Otherwise. */
bool space_between(std::string line);

/*! Pass all information from the file to the KenoBet's object. 
    @param line All lines from the file.
    @param player The KenoBet's object. 
    @return T If all information is ok. F Otherwise. */
bool set_infos(std::vector<std::string> & lines, KenoBet &player);

#endif