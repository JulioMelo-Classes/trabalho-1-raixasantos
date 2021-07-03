#include "KenoBet.hpp"

/*! Returns to the current number of spots in the player's bet.
    @return Number of spots present in the bet. */
size_t KenoBet::size(void) const
{
    return m_spots.size();
}

/*! Adds a number to the spots only if the number is not already there.
    @param spot_ The number we wish to include in the bet.
    @return T If number chosen is successfully inserted; F Otherwise. */
bool KenoBet::add_number(set_of_numbers_type & v_spot_)
{
    m_spots.assign(v_spot_.begin(), v_spot_.end());
    return true;
}

/*! Sets the amount of money the player is betting.
    @param wage_ The wage.
    @return T If we have a wage above zero; F Otherwise. */
bool KenoBet::set_wage(cash_type wage_)
{
    m_wage = wage_;
    return true; // conditions
}


/*! Retrieves the player's wage on this bet.
    @return The wage value. */
cash_type KenoBet::get_wage(void) const
{
    return m_wage;
}

bool KenoBet::set_IC(cash_type IC_)
{
    IC = IC_;
    return true; // conditions
}

cash_type KenoBet::get_IC(void) const
{
    return IC;
}

bool KenoBet::set_NR(number_type NR_)
{
    NR = NR_;
    return true; // conditions
}

number_type KenoBet::get_NR(void) const
{
    return NR;
}

/*! Determine how many spots match the hits passed as argument.
    @param hits_ List of hits randomly chosen by the computer.
    @return An vector with the list of hits. */
set_of_numbers_type KenoBet::get_hits(const set_of_numbers_type & hits_) const
{
    std::vector<number_type> g_hits;

    return g_hits;
}

/*! Returns a vector<spot_type> with the spots the player has picked so far.
    @return The vector<spot_type> with the player's spots picked so far. */
set_of_numbers_type KenoBet::get_spots(void)
{
    return m_spots;
}

/*! Resets a bet to an empty state. */
void KenoBet::reset(void)
{
    m_wage = 0;
    m_spots.clear();
    m_spots.resize(0);
}