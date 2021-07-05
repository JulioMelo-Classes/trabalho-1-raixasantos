#include "KenoBet.hpp"

// Returns to the current number of spots in the player's bet.
size_t KenoBet::size(void) const
{
    return m_spots.size();
}

// Adds numbers to the list of spots.
void KenoBet::add_number(set_of_numbers_type & v_spot_)
{
    m_spots.assign(v_spot_.begin(), v_spot_.end());
}

// Sets the amount of money the player is betting.
void KenoBet::set_wage(cash_type wage_)
{
    m_wage = wage_;
}


// Retrieves the player's wage on this bet.
cash_type KenoBet::get_wage(void) const
{
    return m_wage;
}

// Sets the amount of money the player starts the bet.
void KenoBet::set_IC(cash_type IC_)
{
    IC = IC_;
}

// Retrieves the player's initial credits.
cash_type KenoBet::get_IC(void) const
{
    return IC;
}

// Sets the number of rounds that will be happen.
void KenoBet::set_NR(number_type NR_)
{
    NR = NR_;
}

// Retrieves the player's number of rounds.
number_type KenoBet::get_NR(void) const
{
    return NR;
}

// Sets the player's current credits.
void KenoBet::set_current_credits(cash_type credits)
{
    current_credits += credits;
}

// Retrieves the player's current credits.
cash_type KenoBet::get_current_credits(void) const
{
    return current_credits;
}

// Determine how many spots match the hits passed as argument.
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

// Returns a vector<spot_type> with the spots the player has picked so far.
set_of_numbers_type KenoBet::get_spots(void)
{
    return m_spots;
}

// Resets a bet to an empty state.
void KenoBet::reset(void)
{
    m_spots.clear();
    m_spots.resize(0);
    NR = 0;
    m_wage = 0;
    IC = 0;
    current_credits = 0;
}