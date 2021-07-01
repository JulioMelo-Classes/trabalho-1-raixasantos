#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>

class Interface {
    public:
        /*! Resets the console. */
        void reset(void);

        /*! Reads the file with bet and wage. */
        void start(int argc, char *argv[]);

        /*! Shows the initial informations. */
        void show_initial(void);
};

#endif