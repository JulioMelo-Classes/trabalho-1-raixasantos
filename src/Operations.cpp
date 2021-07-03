#include "Operations.hpp"
#include "KenoBet.hpp"

#include <iostream>
#include <vector>
#include <time.h>


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

// Ordenar o v_spot_.
set_of_numbers_type v_numbers_random(void)
{
    set_of_numbers_type numbers;
    numbers.resize(0);
    
    int count = 0;
    while(numbers.size() != 20)
    {
        number_type num = rand() % 80; // colocar seed
        for(auto i : numbers)
        {
            if(i == num)
                count++;
        }
        if(count == 0)
            numbers.push_back(num);

        count = 0;
    }

    sort_spots(numbers);

    return numbers;
}
