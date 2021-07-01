#ifndef Arquive_hpp
#define Arquive_hpp

#include <iostream>
#include <vector>
#include <string>


class Arquive {
    private:
        std::string local;
    public:
        Arquive(std::string local_);
        void write_ln(std::string texto);
        std::vector<std::string> read_lines(int n);
    
};

#endif