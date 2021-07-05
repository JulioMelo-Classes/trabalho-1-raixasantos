#ifndef KenoBet_hpp
#define KenoBet_hpp

#include <vector>
#include <iostream>

using number_type = unsigned short int; //<! Defines the data type for a keno hit.
using cash_type = float;                //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >;

class KenoBet {
    public:

        // Creates an empty KenoBet.
        KenoBet () : m_wage(0)
        { /* empty */};
        
        /*! Returns to the current number of spots in the player's bet.
            @return Number of spots present in the bet. */
        size_t size(void) const;


        /*! Adds numbers to the list of spots.
            @param v_spot_ The number we wish to include in the bet.
            @return void */
        void add_number(set_of_numbers_type & v_spot_);

        /*! Sets the amount of money the player is betting.
            @param wage_ The wage.
            @return void */
        void set_wage(cash_type wage_);


        /*! Retrieves the player's wage on this bet.
            @return The wage value. */
        cash_type get_wage(void) const;

        /*! Sets the amount of money the player starts the bet.
            @param IC_ The amount.
            @return void */
        void set_IC(cash_type IC_);

        /*! Retrieves the player's initial credits.
            @return The intial credit value. */
        cash_type get_IC(void) const;
        
        /*! Sets the number of rounds that will be happen.
            @param NR_ The number of rounds.
            @return void */
        void set_NR(number_type NR_);

        /*! Retrieves the player's number of rounds.
            @return The number of rounds. */
        number_type get_NR(void) const;

        /*! Sets the player's current credits.
            @param credits The amount of credits.
            @return void */
        void set_current_credits(cash_type credits);

        /*! Retrieves the player's current credits.
            @return The current credit value. */
        cash_type get_current_credits(void) const;

        /*! Determines how many spots match the hits passed as argument.
            @param hits_ List of hits randomly chosen by the computer.
            @return An vector with the list of hits. */
        set_of_numbers_type get_hits(const set_of_numbers_type & hits_) const;

        /*! Returns a vector<spot_type> with the spots the player has picked so far.
            @return The vector<spot_type> with the player's spots picked so far. */
        set_of_numbers_type get_spots(void);

        /*! Resets a bet to an empty state. */
        void reset(void);
         
        cash_type payoff_table[15][16] = {{0,3}, //<! Multidimensional array of payout rate.
                                    {0,1,9},
                                    {0,1,2,16},
                                    {0,0.5,2,6,12},
                                    {0,0.5,1,3,15,50},
                                    {0,0.5,1,2,3,30,75},
                                    {0,0.5,0.5,1,6,12,36,100},
                                    {0,0.5,0.5,1,3,6,19,90,720},
                                    {0,0.5,0.5,1,2,4,8,20,80,1200},
                                    {0,0,0.5,1,2,3,5,10,30,600,1800},
                                    {0,0,0.5,1,1,2,6,15,25,180,1000,3000},
                                    {0,0,0,0.5,1,2,4,24,72,250,500,2000,4000},
                                    {0,0,0,0.5,0.5,3,4,5,20,80,240,500,3000,6000},
                                    {0,0,0,0.5,0.5,2,3,5,12,50,150,500,1000,2000,7500},
                                    {0,0,0,0.5,0.5,1,2,5,15,50,150,300,600,1200,2500,10000}};

    private:
        set_of_numbers_type m_spots;    //<! The player's bet.       
        number_type NR;                 //<! Number of rounds. 
        cash_type m_wage;               //<! The player's wage.        
        cash_type IC;                   //<! The player's initial credit.
        cash_type current_credits;      //<! The player's current credit.
        
};

#endif
