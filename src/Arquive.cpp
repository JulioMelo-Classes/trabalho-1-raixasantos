#include "Arquive.hpp"
#include <fstream>

using namespace std;
Arquive::Arquive(std::string local_){
    local = local_;
};
void Arquive::write_ln(std::string texto){
    ofstream file1;
    file1.open(local, ios::app);
    file1<<texto<<endl;
    file1.close();
};
std::vector<std::string> Arquive::read_lines(int n){
    ifstream file1;
    file1.open(local);
    std::vector<string> v;
    for(int i=0; i<n; i++){
        string texto;
        getline(file1, texto);
        v.push_back(texto);
    }
    file1.close();

    return v;
};