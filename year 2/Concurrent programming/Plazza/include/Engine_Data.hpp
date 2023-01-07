/*
** EPITECH PROJECT, 2019
** Engine_Data.hpp
** File description:
** Engine_Data
*/

#ifndef ENGINE_DATA_HPP_
#define ENGINE_DATA_HPP_enum

#include <chrono>
#include <thread>
#include <vector>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <iostream>
#include <stack>
#include <mutex>
#include <unistd.h>
#include <utility>
#include <stack>

static const int pizzaLen = 4;
static const int sizeLen = 5;
static const int maxContentLen = 6;

enum PizType
{
    Nil = 0,
    Regina = 1,
    Margarita = 2,
    Americana = 3,
    Fantasia = 4
};

enum PizSize
{
    O = 0,
    S = 1,
    M = 2,
    L = 3,
    XL = 4,
    XXL = 5
};

enum PizContent
{
    EMPTY = -1,
    DOE = 0,
    TOMATO = 1,
    GRUYERE = 2,
    HAM = 3,
    MUSHROOMS = 4,
    STEAK = 5,
    EGGPLANT = 6,
    GOAT_CHEESE = 7,
    CHIEF_LOVE = 8,
};

typedef struct pizRecipe_s {
    PizType Type;
    PizContent Elems[maxContentLen];
    int Time;
} pizRecipe_t;

static std::pair<const char *, PizSize> Size[] =
{
    { "S", S },
    { "M", M },
    { "L", L },
    { "XL", XL },
    { "XXL", XXL },
    { "", O }
};

static std::pair<const char *, PizType> Names[] =
{
    { "regina", Regina },
    { "margarita", Margarita },
    { "americana", Americana },
    { "fantasia", Fantasia },
    { "", Nil }
};

static std::pair<const char *, PizContent> FoodName[] =
{
    { "doe", DOE },
    { "tomato", TOMATO },
    { "gruyere", GRUYERE },
    { "ham", HAM },
    { "mushrooms", MUSHROOMS },
    { "steak", STEAK },
    { "eggplant", EGGPLANT },
    { "goat cheese", GOAT_CHEESE },
    { "chief love", CHIEF_LOVE },
    { "", EMPTY }
};

static pizRecipe_t PizzaRec[] =
{
    { Regina, { DOE, TOMATO, GRUYERE, HAM, MUSHROOMS, EMPTY }, 2 },
    { Margarita, { DOE, TOMATO, GRUYERE, EMPTY }, 1 },
    { Americana, { DOE, TOMATO, GRUYERE, STEAK, EMPTY }, 2},
    { Fantasia, { DOE, TOMATO, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE, EMPTY}, 4},
    { Nil, { EMPTY } }
};

#endif /* !ENGINE_DATA_HPP_ */