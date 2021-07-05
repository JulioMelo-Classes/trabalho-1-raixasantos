#include "Operations.hpp"
#include "KenoBet.hpp"

// Sorts a list of spots in ascending order.
void sort_spots(set_of_numbers_type & v_spot)
{
    int j;
    number_type aux;

    for (int i = 1; i < v_spot.size(); i++)
    {
        aux = v_spot[i];
        j = i-1;
        while (j >= 0 && v_spot[j] > aux)
        {
            v_spot[j+1] = v_spot[j];
            j = j-1;
        }
        v_spot[j+1] = aux;
    }
}

// Generates random numbers.
set_of_numbers_type v_numbers_random(void)
{
    set_of_numbers_type numbers;
    numbers.clear();
    numbers.resize(0);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,80);

    int count = 0;
    while(numbers.size() != 20)
    {
        number_type num = dist(gen);
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