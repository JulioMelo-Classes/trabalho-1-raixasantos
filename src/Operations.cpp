#include "Operations.hpp"
#include "KenoBet.hpp"

#include <iostream>
#include <vector>


// Ordenar o v_spot_.
void sort_spots(set_of_numbers_type & v_spot)
{
    int j;
    number_type aux;
    for (int i = 1; i < v_spot.size(); i++)
    {
        aux = v_spot[i];
        j = i - 1;

        /* Move elements of v_spot[0..i-1], that are
        greater than aux, to one position ahead
        of their current position */
        while (j >= 0 && v_spot[j] > aux)
        {
            v_spot[j + 1] = v_spot[j];
            j = j - 1;
        }
        v_spot[j + 1] = aux;
    }
}
