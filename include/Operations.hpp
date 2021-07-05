#ifndef Operations_hpp
#define Operations_hpp

#include "KenoBet.hpp"

#include <iostream>
#include <vector>
#include <random>

/*! Sorts a list of spots in ascending order.
    @param v_spot The list of spots.
    @return void */
void sort_spots(set_of_numbers_type & v_spot);

/*! Generates random numbers.
    @return A list of random numbers. */
set_of_numbers_type v_numbers_random(void);

#endif