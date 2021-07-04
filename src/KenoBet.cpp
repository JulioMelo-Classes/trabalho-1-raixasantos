#include "KenoBet.hpp"

/*! Returns to the current number of spots in the player's bet.
    @return Number of spots present in the bet. */
/*! Retorna a quantidade de apostas que o jogador vai fazer.
    @return A quantidade de apostas realizadas. */
size_t KenoBet::size(void) const
{
    return m_spots.size();
}

/*! Adds a number to the spots only if the number is not already there.
    @param spot_ The number we wish to include in the bet.
    @return T If number chosen is successfully inserted; F Otherwise. */
/*! Adicionar uma aposta/chute apenas se não já tiver sido escolhido.
    @param spot_ O número escolhido para a aposta/chute.
    @return T se o número foi escolhido com sucesso. */
bool KenoBet::add_number(set_of_numbers_type & v_spot_)
{
    m_spots.assign(v_spot_.begin(), v_spot_.end());
    return true;
}

/*! Sets the amount of money the player is betting.
    @param wage_ The wage.
    @return T If we have a wage above zero; F Otherwise. */
/*! Determina o valor de cada aposta.
    @param wage_ crédito.
    @return verdadeiro se o jogador possui crédito para apostar. */
bool KenoBet::set_wage(cash_type wage_)
{
    m_wage = wage_;
    return true; // conditions
}


/*! Set's the player's initial credit.
    @return The initial credit. */
/*! Determina o valor inicial na carteira do jogador.
    @return O valor inicial do jogador. */
cash_type KenoBet::get_wage(void) const
{
    return m_wage;
}
/*! Retrieves the player's wage on this bet.
    @return . */
/*! Retorna o valor da carteira do jogador após a aposta.
    @return . */
bool KenoBet::set_IC(cash_type IC_)
{
    IC = IC_;
    return true; // conditions
}
/*! Get's the player's initial credit.
    @return The initial credit. */]
/*! Determina o valor inicial do crédito do jogador .
    @return O crédito inicial. */
cash_type KenoBet::get_IC(void) const
{
    return IC;
}
/*! Set's the numbers of rounds of bets.
    @return . */
/*! Determina o números de jogos que serão realizados.
    @return . */
bool KenoBet::set_NR(number_type NR_)
{
    NR = NR_;
    return true; // conditions
}
/*! Get's the numbers of rounds of bets.
    @return The numbers of rounds. */
/*! Pega a quantidade de jogos que serão realizadas.
    @return A quantidade de jogos. */
number_type KenoBet::get_NR(void) const
{
    return NR;
}
/*! Change the player's credits between games.
    @return . */
/*! Modifica o valor do crédito do jogador entre as partidas.
    @return . */
bool KenoBet::set_current_credits(cash_type credits)
{
    current_credits += credits;
    return true; // conditions
}
/*! Get's the player's credits between games.
    @return The player's credits. */
/*! Pega o valor do crédito do jogador entre as partidas.
    @return O crédito do jogador. */
cash_type KenoBet::get_current_credits(void) const
{
    return current_credits;
}

/*! Determine how many spots match the hits passed as argument.
    @param hits_ List of hits randomly chosen by the computer.
    @return An vector with the list of hits. */
/*! Determina a quantidade de apostas/chutes o jogador acertou.
    @param hits_ Lista de números sorteados pelo computador.
    @return Um vetor com a lista de acertos do jogador. */
set_of_numbers_type KenoBet::get_hits(const set_of_numbers_type & hits_) const
{
    std::vector<number_type> g_hits;

    for(auto i : hits_)
    {
        for(auto j : m_spots)
        {
            if(i == j){
                g_hits.push_back(i);
            }
        }
    }

    return g_hits;
}

/*! Returns a vector<spot_type> with the spots the player has picked so far.
    @return The vector<spot_type> with the player's spots picked so far. */
/*! Retorna o vector<spot_type> com as apostas/chutes que o jogador escolheu.
    @return O vector<spot_type> com as apostas/chutes do jogador. */
set_of_numbers_type KenoBet::get_spots(void)
{
    return m_spots;
}

/*! Resets a bet to an empty state. */
/*! Reseta as apostas para um estado vazio. */
void KenoBet::reset(void)
{
    m_spots.clear();
    m_spots.resize(0);
    NR = 0;
    m_wage = 0;
    IC = 0;
    current_credits = 0;
}