#include "KenoBet.hpp"

/*! Adds a number to the spots only if the number is not already there.
    @param spot_ The number we wish to include in the bet.
    @return T If number chosen is successfully inserted; F Otherwise. */
bool KenoBet::add_number(number_type spot_)
{
    m_spots.push_back(spot_);
    return true;
}

/*! Sets the amount of money the player is betting.
    @param wage_ The wage.
    @return T If we have a wage above zero; F Otherwise. */
bool KenoBet::set_wage(cash_type wage_)
{
    m_wage = wage_;
    return true;
}

/*! Resets a bet to an empty state. */
void KenoBet::reset(void)
{
    // m_wage, m_spots
}

/*! Retrieves the player's wage on this bet.
    @return The wage value. */
cash_type KenoBet::get_wage(void) const
{
    return m_wage;
}

/*! Returns to the current number of spots in the player's bet.
    @return Number of spots present in the bet. */
size_t KenoBet::size(void) const
{
    return m_spots.size();
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
set_of_numbers_type KenoBet::get_spots(void) const
{
    return m_spots;
}