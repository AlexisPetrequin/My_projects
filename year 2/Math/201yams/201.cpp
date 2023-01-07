/*
** EPITECH PROJECT, 2021
** 201
** File description:
** 201.cpp
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

int errorcheck(char **av)
{
    char comp[66][12] = {"pair_1", "pair_2", "pair_3", "pair_4", "pair_5", "pair_6",
    "three_1", "three_2", "three_3", "three_4", "three_5", "three_6",
    "four_1", "four_2", "four_3", "four_4", "four_5", "four_6",
    "straight_1", "straight_2", "straight_3", "straight_4", "straight_5", "straight_6",
    "yams_1", "yams_2", "yams_3", "yams_4", "yams_5", "yams_6",
    "full_1_1", "full_1_2", "full_1_3", "full_1_4", "full_1_5", "full_1_6",
    "full_2_1", "full_2_2", "full_2_3", "full_2_4", "full_2_5", "full_2_6",
    "full_3_1", "full_3_2", "full_3_3", "full_3_4", "full_3_5", "full_3_6",
    "full_4_1", "full_4_2", "full_4_3", "full_4_4", "full_4_5", "full_4_6",
    "full_5_1", "full_5_2", "full_5_3", "full_5_4", "full_5_5", "full_5_6",
    "full_6_1", "full_6_2", "full_6_3", "full_6_4", "full_6_5", "full_6_6"};

    for (int i = 1; i < 6; i++)
        if (av[i][0] < '0' || av[i][0] > '6' || av[i][1] != '\0')
            return (1);
    for (int i = 0; i < 66; i++)
        if (std::strcmp(comp[i], av[6]) == 0)
            return (0);
    return (1);
}

class Game {
    public:
    Game(int a, int b, int c, int d, int e, std::string str);
    ~Game();
    enum Combinaison{
        PAIR,
        THREE,
        FOUR,
        YAMS,
        FULL,
        STRAIGHT
        };
    double proba_pair();
    double proba_three();
    double proba_four();
    double proba_full();
    double proba_yams();
    double proba_straight();
    int die1;
    int die2;
    int die3;
    int die4;
    int die5;
    Combinaison cb;
    int cb1;
    int cb2;
};

Game::Game(int a, int b, int c, int d, int e, std::string str): die1(a), die2(b), die3(c), die4(d), die5(e), cb2(0)
{
    if (str[0] == 'p')
        cb = PAIR;
    if (str[0] == 't')
        cb = THREE;
    if (str[0] == 'f' && str[1] == 'o')
        cb = FOUR;
    if (str[0] == 'y')
        cb = YAMS;
    if (str[0] == 'f' && str[1] == 'u')
        cb = FULL;
    if (str[0] == 's')
        cb = STRAIGHT;
    cb1 = atoi(&str[str.find('_') + 1]);
    if (cb == FULL)
        cb2 = atoi(&str[str.find_last_of('_') + 1]);
}

Game::~Game()
{
}

double Game::proba_pair()
{
    double get = 0;

    if (die1 == cb1)
        get++;
    if (die2 == cb1)
        get++;
    if (die3 == cb1)
        get++;
    if (die4 == cb1)
        get++;
    if (die5 == cb1)
        get++;
    if (get >= 2)
        return (100.00);
    if (get == 1)
        return (51.77);
    if (get == 0)
        return (19.62);
    return (0.00);
}

double Game::proba_three()
{
    double get = 0;

    if (die1 == cb1)
        get++;
    if (die2 == cb1)
        get++;
    if (die3 == cb1)
        get++;
    if (die4 == cb1)
        get++;
    if (die5 == cb1)
        get++;
    if (get >= 3)
        return (100.00);
    if (get == 2)
        return (42.13);
    if (get == 1)
        return (13.19);
    if (get == 0)
        return (3.55);
    return (0.00);
}

double Game::proba_four()
{
    double get = 0;

    if (die1 == cb1)
        get++;
    if (die2 == cb1)
        get++;
    if (die3 == cb1)
        get++;
    if (die4 == cb1)
        get++;
    if (die5 == cb1)
        get++;
    if (get >= 4)
        return (100.00);
    if (get == 3)
        return (30.56);
    if (get == 2)
        return (7.41);
    if (get == 1)
        return (1.62);
    if (get == 0)
        return (0.33);
    return (0.00);
}

double Game::proba_full()
{
    double get = 0;
    double get2 = 0;

    if (die1 == cb1)
        get++;
    if (die2 == cb1)
        get++;
    if (die3 == cb1)
        get++;
    if (die4 == cb1)
        get++;
    if (die5 == cb1)
        get++;
    if (die1 == cb2)
        get2++;
    if (die2 == cb2)
        get2++;
    if (die3 == cb2)
        get2++;
    if (die4 == cb2)
        get2++;
    if (die5 == cb2)
        get2++;
    if (get == 3 && get2 == 2)
        return (100);
    if (get == 3 && get2 == 1)
        return (16.67);
    if (get == 2 && get2 == 2)
        return (16.67);
    if (get == 0 && get2 == 0)
        return (0.13);
    return (0.00);
}

double Game::proba_straight()
{
    double get = 0;

    if (cb1 == 5) {
        if (die1 == 1 || die2 == 1 || die3 == 1 || die4 == 1 || die5 == 1)
            get++;
        if (die1 == 2 || die2 == 2 || die3 == 2 || die4 == 2 || die5 == 2)
            get++;
        if (die1 == 3 || die2 == 3 || die3 == 3 || die4 == 3 || die5 == 3)
            get++;
        if (die1 == 4 || die2 == 4 || die3 == 4 || die4 == 4 || die5 == 4)
            get++;
        if (die1 == 5 || die2 == 5 || die3 == 5 || die4 == 5 || die5 == 5)
            get++;
    }
    if (cb1 == 6) {
        if (die1 == 6 || die2 == 6 || die3 == 6 || die4 == 6 || die5 == 6)
            get++;
        if (die1 == 2 || die2 == 2 || die3 == 2 || die4 == 2 || die5 == 2)
            get++;
        if (die1 == 3 || die2 == 3 || die3 == 3 || die4 == 3 || die5 == 3)
            get++;
        if (die1 == 4 || die2 == 4 || die3 == 4 || die4 == 4 || die5 == 4)
            get++;
        if (die1 == 5 || die2 == 5 || die3 == 5 || die4 == 5 || die5 == 5)
            get++;
    }
    if (get == 5)
        return (100.00);
    if (get == 4)
        return (16.67);
    if (get == 3)
        return (5.56);
    if (get == 2)
        return (2.78);
    if (get == 1)
        return (1.85);
    if (get == 0)
        return (1.54);
    return (0.00);
}

double Game::proba_yams()
{
    double get = 0;

    if (die1 == cb1)
        get++;
    if (die2 == cb1)
        get++;
    if (die3 == cb1)
        get++;
    if (die4 == cb1)
        get++;
    if (die5 == cb1)
        get++;
    if (get == 5)
        return (100.00);
    if (get == 4)
        return (16.67);
    if (get == 3)
        return (2.78);
    if (get == 2)
        return (0.46);
    if (get == 1)
        return (0.08);
    if (get == 0)
        return (0.01);
    return (0.00);
}

int main(int ac, char **av)
{
    if (ac != 7)
        return (84);
    if (errorcheck(av))
        return (84);
    std::string comb = av[6];
    Game game(atoi(av[1]), atoi(av[2]), atoi(av[3]), atoi(av[4]), atoi(av[5]), comb);
    if (game.cb == game.STRAIGHT && game.cb1 < 5)
        return (84);

    if (game.cb == game.PAIR)
        std::cout << "Chances to get a " << game.cb1 << " pair: " << game.proba_pair() << "%" << std::endl;
    if (game.cb == game.THREE)
        std::cout << "Chances to get a " << game.cb1 << " three-of-a-kind: " << game.proba_three() << "%" << std::endl;
    if (game.cb == game.FOUR)
        std::cout << "Chances to get a " << game.cb1 << " four-of-a-kind: " << game.proba_four() << "%" << std::endl;
    if (game.cb == game.FULL)
        std::cout << "Chances to get a " << game.cb1 << " full of " << game.cb2 << ": "<< game.proba_full() << "%" << std::endl;
    if (game.cb == game.YAMS)
        std::cout << "Chances to get a " << game.cb1 << " yams: " << game.proba_yams() << "%" << std::endl;
    if (game.cb == game.STRAIGHT)
        std::cout << "Chances to get a " << game.cb1 << " straight: " << game.proba_straight() << "%" << std::endl;
    return (0);
}