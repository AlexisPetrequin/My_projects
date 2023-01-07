/*
** EPITECH PROJECT, 2021
** IQ
** File description:
** IQ.hpp
*/

#ifndef IQ_HH_
# define IQ_HH_

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <string>
# include <cmath>

class IQ {
    public:
        IQ(int, int);
        IQ(int, int, int);
        IQ(int, int, int, int);
        ~IQ();
        void calc();
        void print();

    private:
        enum Mode {
            ZERO_B,
            ONE_B,
            TWO_B
        };
        double _map[201];
        int _u;
        int _o;
        int _min;
        int _max;
        Mode _mode;
};

#endif /* !IQ_HH_ */
