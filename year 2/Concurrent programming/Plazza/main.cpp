/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main
*/

#include "include/Engine.hpp"

static bool usage(int ac, char **av)
{
    if (ac != 2 || (strcmp(av[1], "-h") && strcmp(av[1], "-help")))
        return (false);
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t    " << av[0] << " [multiplier] [cooks] [time]" << std::endl;
    std::cout << "DESCRIPTION:" << std::endl;
    std::cout << "\t    multiplier\t" << "multiplier for the cooking time of the pizzas" << std::endl;
    std::cout << "\t    cooks\t" << "number of cooks per kitchen" << std::endl;
    std::cout << "\t    time\t" << "the time in milliseconds, used by the kitchen stock to replace ingredients" << std::endl;
    return (true);
}

static bool check(int ac, char **av)
{
    if (ac != 4) {
        std::cerr << "Bad usage." << std::endl;
        return (false);
    } else if (atoi(av[1]) <= 0) {
        std::cerr << "Multiplier value must be a positive number." << std::endl;
        return (false);
    }
    if (atoi(av[2]) <= 0) {
        std::cerr << "Cooks value must be a positive number." << std::endl;
        return (false);
    } else if (atoi(av[3]) <= 0) {
        std::cerr << "Cooks value must be a positive number." << std::endl;
        return (false);
    }
    return (true);
}

int main(int ac, char **av)
{
    Engine *engine = NULL;
    info_t *info;
    int pid = fork();
    int memid = shmget(0x00042473, sizeof(info_t), 0700 | IPC_CREAT);

    if (memid < 0)
        return (84);
    info = (info_t *)shmat(memid, NULL, 0);
    if (pid < 0)
        return (84);
    else if (pid == 0) {
        if (!engine)
            return (84);
        engine->del_kitchens();
        engine->display();
        engine->running = true;
        return (0);
    } else {
        if (usage(ac, av))
            return (0);
        if (!check(ac, av))
            return (84);
        engine = new Engine(atoi(av[1]), atoi(av[2]), atoi(av[3]));
        engine->info = info;
        if (!engine)
            return (84);
        engine->run();
        delete(engine);
        wait(NULL);
    }
    return (0);
}
