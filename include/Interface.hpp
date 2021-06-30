#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>

class Interface {
    public:
        /*! Resets the console.*/
        void reset(void);

        /*! Reads the file with bet and wage. */
        void read_file(void);
};

#endif