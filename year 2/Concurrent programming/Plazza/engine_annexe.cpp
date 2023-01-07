/*
** EPITECH PROJECT, 2021
** engine_anex.cpp
** File description:
** engine_anex
*/

#include <thread>
#include <iostream>
#include <utility>
#include <string>
#include <complex>
#include <tuple>
#include <fstream>
#include <ctime>
#include <pthread.h>
#include "include/Engine.hpp"

Cooks::Cooks(Kitchen *kitchene)
{
    kitchen = kitchene;
    state = 0;
    type = -1;
    step = -1;
}

Cooks::~Cooks(void)
{
}

void Cooks::display()
{
    int remain = 0;

    if (state == Sleeping)
        std::cout << "Waiting";
    else {
        remain = kitchen->get_mult(type) - step;
        std::cout << "Cooking a " << Names[type - 1].first << ", Remain =" << remain << "s, Elapsed =" << step << "s";
    }
}

void Cooks::give_work(int _type)
{
    type = _type;
    state = Cooking;
    step = 0;
}

void Cooks::next_step(void)
{
    step++;
}

void Cooks::cook_ready(int mult)
{
    kitchen->pizza_ready(type);
    step = 0;
    type = -1;
    state = 0;
}

Stock::Stock(void)
{
    for (int i = 0; i < 9; i++) {
        std::pair<int, int> pair = { i, 5};
        products[i] = pair;
    }
}

Stock::~Stock(void)
{
}

void Stock::add_food(int food, int nbr)
{
    if (food >= 0 && food <= 8)
        products[food].second += nbr;
}

void Stock::del_food(int food, int nbr)
{
    if (food >= 0 && food <= 8)
        products[food].second -= nbr;
}

void Stock::display_stock(void)
{
    std::cout << "\tcheck_Available stock: {\n\t\t";
    for (int i = DOE; i <= CHIEF_LOVE; i++) {
        std::cout << Names[i].first << ": " << products[i].second << " units; ";
        if (i != 0 && i % 5 == 0) {
            std::cout << std::endl << "\t\t";
        }
    }
    std::cout << std::endl << "\t}" << std::endl;
}

void Stock::update_stock(void)
{
    for (int i = 0; i < 9; i++)
        add_food(i, 1);
}

int Stock::check_stock(int food)
{
    if (food >= 0 && food <= 8)
        return (products[food].second);
    else
        return (-1);
}

bool Stock::get_stock(int nb)
{
    bool boool = true;
    pizRecipe_t recipe = { Nil };

    for (int i = 0; PizzaRec[i].Type != Nil; i++)
        if (PizzaRec[i].Type == nb) {
            recipe = PizzaRec[i];
            break;
        }
    if (recipe.Type == Nil)
        return (false);
    for (int i = 0; recipe.Elems[i] != EMPTY; i++)
        if (check_stock(recipe.Elems[i]) <= 0)
            boool = false;
    if (!boool)
        return (false);
    for (int i = 0; recipe.Elems[i] != EMPTY; i++)
        del_food(recipe.Elems[i], 1);
    return (true);
}

bool Stock::check_available(int nb)
{
    bool boool = true;
    pizRecipe_t recipe = { Nil };

    for (int i = 0; PizzaRec[i].Type != Nil; i++)
        if (PizzaRec[i].Type == nb) {
            recipe = PizzaRec[i];
            break;
        }
    if (recipe.Type == Nil)
        return (false);
    for (int i = 0; recipe.Elems[i] != EMPTY; i++)
        if (check_stock(recipe.Elems[i]) <= 0)
            boool = false;
    return (boool);
}

Kitchen::Kitchen(Engine *eng)
{
    active = 0;
    engine = eng;
    state = Waiting;
    stock = new Stock();
}

Kitchen::~Kitchen(void)
{
    for (int i = 0; i < cooks.size(); i++)
        if (cooks[i])
            free(cooks[i]);
    cooks.clear();
    if (stock)
        free(stock);
}


void Kitchen::stop_work(void)
{
    running = false;
}

void Kitchen::pizza_ready(int nb)
{
    pizCooked.lock();
    if (!pizzasCooked.empty() && pizzasCooked.at(0).first == nb)
        pizzasCooked.at(0).second++;
    else
        pizzasCooked.insert(pizzasCooked.begin(), {nb - 1, 1});
    pizCooked.unlock();
}

bool Kitchen::checkSteps(void)
{
    int steps;
    bool boool = false;

    if (!cooks.size()) {
        active++;
        return (false);
    }
    for (int i = 0; i < cooks.size(); i++) {
        if (!cooks[i]->state)
            continue;
        boool = true;
        steps = engine->multiplier * get_mult(cooks[i]->type);
        cooks[i]->next_step();
        if (cooks[i]->step == steps)
            cooks[i]->cook_ready(steps);
    }
    return (boool);
}

void Kitchen::assign_if_empty(void)
{
    if (!cooks.size())
        return;
    for (int i = 0; i < cooks.size() && pizToCook.size() && pizToCook.at(0).second; i++) {
        if (cooks[i]->state)
            continue;
        if (!stock->check_available(pizToCook.at(0).first))
            continue;
        pizToCook.at(0).second--;
        stock->get_stock(pizToCook.at(0).first);
        cooks[i]->give_work(pizToCook.at(0).first);
    }
}

void Kitchen::refresh_stock(void)
{
    stock->update_stock();
}

int Kitchen::get_mult(int nb)
{
    for (int i = 0; i < 4; i++)
        if (nb == PizzaRec[i].Type)
            return (PizzaRec[i].Time);
    return (1);
}

void Kitchen::create_cooks(void)
{
    for (int i = 0; i < engine->cooks; i++)
        cooks.push_back(new Cooks(this));
}

static void *task(void *kitchene)
{
    Kitchen *kitchen = (Kitchen *)kitchene;
    int refresh_step = 0;
    int cook_step = 0;

    while (kitchen->running) {
        if (!kitchen->pizToCook.empty() && kitchen->pizToCook.at(0).second <= 0)
            kitchen->pizToCook.erase(kitchen->pizToCook.begin());
        if (!kitchen->pizToCook.empty() && kitchen->pizToCook.at(0).second > 0)
            kitchen->assign_if_empty();
        usleep(10000);
        cook_step += 10;
        refresh_step += 10;
        if (kitchen->engine->refresh <= refresh_step) {
            kitchen->refresh_stock();
            refresh_step = 0;
        }
        if (cook_step >= 1000) {
            if (kitchen->checkSteps())
                kitchen->active = 0;
            else if (kitchen->active <= 5)
                kitchen->active++;
            else
                kitchen->running = false;
                cook_step = 0;
        }
    }
    return (NULL);
}

void Kitchen::start_work(void)
{
    create_cooks();
    running = true;
    pthread_create(&this->thread, NULL, task, (void *)this);
    pthread_detach(this->thread);
}

void Kitchen::display_cooks(void)
{
    std::cout << "\tPizza(s) queue: {";
    for (int i = 0; i < pizToCook.size(); i++)
        std::cout << "\n\t\t{ " << Names[pizToCook[i].first - 1].first << " units = " << Names[pizToCook[i].first - 1].second << " }";
    std::cout << std::endl << "\t}" << std::endl << "\tCook(s) (Len =" << cooks.size() << "): {";
    for (int i = 0; i < cooks.size(); i++) {
        std::cout << "\n\t\tCook n°" << i << " { ";
        cooks[i]->display();
        std::cout << " }";
    }
    std::cout << std::endl << "\t}" << std::endl;
}

order_t Kitchen::do_order(order_t order)
{
    std::pair<int, int> pair;
    int posPiz = engine->cooks * 2;

    for (int i = 0; i < 4 && posPiz; i++) {
        if (!order.pizLeft[i].second)
            continue;
        if (posPiz && posPiz >= order.pizLeft[i].second) {
            pair = { order.pizLeft[i].first, order.pizLeft[i].second };
            posPiz -= order.pizLeft[i].second;
            order.pizLeft[i].second -= order.pizLeft[i].second;
            pizToCook.insert(pizToCook.begin(), pair);
        } else if (posPiz) {
            pair = { order.pizLeft[i].first, posPiz };
            order.pizLeft[i].second -= posPiz;
            posPiz = 0;
            pizToCook.insert(pizToCook.begin(), pair);
        }
    }
    return (order);
}