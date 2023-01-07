/*
** EPITECH PROJECT, 2021
** engine.cpp
** File description:
** engine
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

static bool order_empty(order_t order)
{
    bool empty = false;

    for (int i = 0; i < 4; i++)
        if (!order.pizLeft[i].second)
            empty = true;
        else
            return (false);
    return (empty);
}

Engine::Engine(int _multiplier, int _cooks, int _refresh)
{
    multiplier = _multiplier;
    cooks = _cooks;
    refresh = _refresh;
}

Engine::~Engine(void)
{
    for (; !kitchens.empty();) {
        if (!kitchens.at(0))
            break;
        kitchens.at(0) = NULL;
        delete(kitchens.at(0));
        kitchens.erase(kitchens.begin());
    }
    tasks.clear();
    multiplier = 0;
    cooks = 0;
    refresh = 0;
    pthread_cancel(thread);
}

order_t prepare_kitchens(Engine *engine, order_t order)
{
    for (int i = 0; i < engine->kitchens.size(); i++)
        order = engine->kitchens[i]->do_order(order);
    if (order_empty(order))
        return (order);
    for (; !order_empty(order);) {
        Kitchen *kitch = new Kitchen(engine);
        order = kitch->do_order(order);
        engine->kitchens.push_back(kitch);
        kitch->start_work();
    }
    return (order);
}

bool Engine::del_kitchens(void)
{
    for (int i = 0; i < kitchens.size(); i++)
        if (kitchens[i] && !kitchens[i]->running) {
            Kitchen *tmp = kitchens[i];
            kitchens.erase(kitchens.begin() + i);
            tmp = NULL;
            delete (tmp);
            return (true);
        }
    return (false);
}

void Engine::clean_kitchens(void)
{
    for (int i = 0; i < kitchens.size(); i++)
        if (kitchens[i])
            kitchens[i]->running = false;
    for (int i = 0; i < kitchens.size(); i++)
        if (kitchens[i]) {
            kitchens[i] = NULL;
            delete (kitchens[i]);
        }
}

void Engine::load_orders(std::stack<pizzaOrder_t> orders)
{
    order_t order;
    int oldLen = tasks.size();

    order.pizToCook = { { Regina, 0 }, { Margarita, 0 }, { Americana, 0 }, { Fantasia, 0 } };
    order.pizLeft = { { Regina, 0 }, { Margarita, 0 }, { Americana, 0 }, { Fantasia, 0 } };
    order.pizCooked = { { Regina, 0 }, { Margarita, 0 }, { Americana, 0 }, { Fantasia, 0 } };
    order.details = orders;
    for (; !orders.empty();) {
        order.pizLeft[orders.top().type - 1].second += orders.top().quantity;
        order.pizToCook[orders.top().type - 1].second += orders.top().quantity;
        orders.pop();
    }
    tasks.push_back(order);
}

void Engine::del_order(void)
{
    std::time_t result = std::time(nullptr);

    if (!tasks.size())
        return;
    std::ofstream logs("logs.txt", std::ios::app);
    logs << std::asctime(std::localtime(&result)) << "{" << std::endl;
    std::cout << "An order is ready {" << std::endl;
    while (!tasks[0].details.empty()) {
        std::cout << "\t" << Names[tasks[0].details.top().type - 1].first << " x" << tasks[0].details.top().quantity << " Size =" << Size[tasks[0].details.top().size - 1].first << std::endl;
        logs << "\t" << Names[tasks[0].details.top().type - 1].first << " x" << tasks[0].details.top().quantity << " Size =" << Size[tasks[0].details.top().size - 1].first << std::endl;
        tasks[0].details.pop();
    }
    logs << "}";
    logs.close();
    std::cout << "}" << std::endl << "> ";
    tasks.erase(tasks.begin());
}

void Engine::update_order(void)
{
    if (kitchens.empty())
        return;
    for (int i = 0; i < kitchens.size(); i++) {
        kitchens.at(i)->pizCooked.lock();
        for (; !kitchens.at(i)->pizzasCooked.empty();) {
            std::pair<int, int> pair = kitchens.at(i)->pizzasCooked.at(0);
            tasks[0].pizCooked[pair.first].second += pair.second;
            kitchens.at(i)->pizzasCooked.erase(kitchens.at(i)->pizzasCooked.begin());
        }
        kitchens.at(i)->pizCooked.unlock();
    }
}

bool Engine::order_ready(void)
{
    if (!tasks.size())
        return (false);
    for (int i = 0; i < tasks.size(); i++)
        if (tasks[0].pizCooked[i].second != tasks[0].pizToCook[i].second)
            return (false);
    return (true);
}


void Engine::display(void)
{
    std::cout << "Order(s) status (Len=" << tasks.size() << "):" << std::endl;
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << "Order n°" << i << " {" << std::endl;
        for (int p = 0; p < 4; p++) {
            if (!tasks[i].pizToCook[p].second)
                continue;
            std::cout << "\t" << Names[p].first << " " << tasks[i].pizCooked[p].second << "/" << tasks[i].pizToCook[p].second << std::endl;
        }
        std::cout << "}" << std::endl;
    }
    std::cout << "Kitchen(s) status (Len=" << kitchens.size() << "):" << std::endl;
    for (int i = 0; i < kitchens.size(); i++) {
        std::cout << "Kitchen n°" << i << " {" << std::endl;
        kitchens[i]->stock->display_stock();
        kitchens[i]->display_cooks();
        std::cout << "}" << std::endl;
    }
}

void *task(void *eng)
{
    Engine *engine = (Engine *)eng;
    order_t current;

    engine->running = true;
    for (; engine->running;) {
        for (; engine->del_kitchens(););
        if (!engine->tasks.size())
            continue;
        engine->update_order();
        if (engine->order_ready())
            engine->del_order();
        else if (!engine->kitchens.size()) {
            current = engine->tasks[0];
            if (!engine->order_ready())
                current = prepare_kitchens(engine, current);
        }
    }
    engine->clean_kitchens();
    return (NULL);
}

void Engine::run(void)
{
    running = true;
    pthread_create(&this->thread, NULL, parse_loop, (void *)this);
    task(this);
    running = false;
}