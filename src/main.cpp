#include "Arquive.hpp"
#include "KenoBet.hpp"
#include "Interface.hpp"
#include "Operations.hpp"
/*
Avaliação
Processamento do Arquivo de Entrada: 0,75 (faltou processar o caso em que o arquivo tem menos de 3 linhas)
Execução correta: 1
Interfcace Textual: 1
Documentação: 1
Compilação automatizada: 1
Organização em src, include, build, data: 1

Comentários
- Acho que a organização ficou muito boa, para melhorar vocês poderiam adicionar alguns atributos na classe Interface
especialmente uma referencia para KenoBet.
- A parte de processamento do arquivo na classe Arquive também poderia ficar mais focada dentro da classe e não em funções
separadas. Veja que quando vocês enviam uma referencia de Arquive na função readlines, fica bem claro que essa função poderia
ser um método da classe arquive. Como as demais funções não se encaixam como métodos (pois são auxiliares de arquive), não tem
problema colocar elas separadas, mas vocês poderiam coloca-las como membros estáticos da classe arquive melhorando ainda mais a organização.
*/

int main(int argc, char *argv[]) {
    Interface interface;
    Arquive file_bet;
    KenoBet player;

    if(interface.start(player, file_bet, argc, argv))    
    {
        number_type rounds = player.get_NR();
        for(int i = 1; i < rounds+1; i++)
        {
            interface.show_game(player, i);
        }

        interface.show_summary(player);
    }

    player.reset();
}
