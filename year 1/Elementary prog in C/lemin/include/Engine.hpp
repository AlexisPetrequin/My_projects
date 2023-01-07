/*
** EPITECH PROJECT, 2021
** Engine.hpp
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <pthread.h>
#include "Parse.hpp"
#include "Engine_Data.hpp"

class Cooks;
class Stock;
class Kitchen;
class Engine;

enum KitchenState {
    Full,
    Work,
    Waiting
};

typedef struct order_s {
    std::vector<std::pair<int, int>> pizToCook;
    std::vector<std::pair<int, int>> pizLeft;
    std::vector<std::pair<int, int>> pizCooked;
    std::stack<pizzaOrder_t> details;
} order_t;

class Kitchen {
    public:
        Kitchen(Engine *);
        ~Kitchen();
        Engine *engine;
        std::vector<Cooks *> cooks;
        Stock *stock;
        int state;
        int active;
        bool running;
        pthread_t thread;
        std::vector<std::pair<int, int>> pizToCook;
        std::mutex pizCooked;
        std::vector<std::pair<int, int>> pizzasCooked;
        void display_cooks(void);
        order_t do_order(order_t);
        void refresh_stock(void);
        void start_work(void);
        void stop_work(void);
        bool checkSteps(void);
        void assign_if_empty(void);
        void pizza_ready(int);
        int get_mult(int);
    private:
        void create_cooks(void);
};

typedef struct info_s {
    int instruction;
    int val;
    int type;
    int size;
    int delay;
} info_t;

class Engine {
    public:
        Engine(int, int, int);
        ~Engine(void);
        std::vector<Kitchen *> kitchens;
        std::vector<order_t> tasks;
        int multiplier;
        int cooks;
        int refresh;
        bool running;
        pthread_t thread;
        info_t *info;
        void display(void);
        void load_orders(std::stack<pizzaOrder_t>);
        void run(void);
        bool order_ready(void);
        void del_order(void);
        bool del_kitchens(void);
        void clean_kitchens(void);
        void update_order(void);
};

class Stock {
    public:
        Stock();
        ~Stock();
        std::pair<int, int> products[9];
        void display_stock(void);
        void update_stock(void);
        int check_stock(int);
        bool get_stock(int);
        bool check_available(int);
        void add_food(int, int);
        void del_food(int, int);
};

class Pizza {
    public:
        Pizza();
        ~Pizza();

        int type;
        int state;
};

enum CooksState {
    Sleeping = 0,
    Cooking
};

class Cooks {
    public:
        Cooks(Kitchen *);
        ~Cooks();
        Pizza *pizza;
        void display(void);
        void give_work(int);
        void next_step(void);
        void cook_ready(int);
        Kitchen *kitchen;
        int type;
        int step;
        int state;
};

#endif /* !ENGINE_HPP_ */