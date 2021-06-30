#include "KenoBet.hpp"

//! Creates an empty KenoBet.
KenoBet::KenoBet( ) : m_wage(0)
{ /* empty */};

/*! Adds a number to the spots only if the number is not already there.
    @param spot_ The number we wish to include in the bet.
    @return T If number chosen is successfully inserted; F Otherwise. */
bool KenoBet::add_number(number_type spot_)
{
    
}

/*! Sets the amount of money the player is betting.
    @param wage_ The wage.
    @return T If we have a wage above zero; F Otherwise. */
bool KenoBet::set_wage(cash_type wage_)
{

}

/*! Resets a bet to an empty state. */
void KenoBet::reset(void)
{

}

/*! Retrieves the player's wage on this bet.
    @return The wage value. */
cash_type KenoBet::get_wage(void) const
{

}

/*! Returns to the current number of spots in the player's bet.
    @return Number of spots present in the bet. */
size_t KenoBet::size(void) const
{

}

/*! Determine how many spots match the hits passed as argument.
    @param hits_ List of hits randomly chosen by the computer.
    @return An vector with the list of hits. */
set_of_numbers_type KenoBet::get_hits(const set_of_numbers_type & hits_) const
{

}

/*! Returns a vector<spot_type> with the spots the player has picked so far.
    @return The vector<spot_type> with the player's spots picked so far. */
set_of_numbers_type KenoBet::get_spots(void) const
{

}