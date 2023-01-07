/*
** EPITECH PROJECT, 2021
** groundhog
** File description:
** groundhog.cpp
*/

#include "groundhog.hpp"

double find_median(std::vector<double> len)
{
    size_t size = len.size();

    if (size == 0)
        return (0);
    else {
        if (size % 2 == 0)
            return (len[size / 2 - 1] + len[size / 2]) / 2;
        else
            return len[size / 2];
    }
}

Groundhog::Groundhog()
{
    _nb_switch = 0;
    _r = 0;
    _last_r = 0;
}

Groundhog::~Groundhog()
{
}

void Groundhog::get_weirdest_value()
{
    static int i = 0;
    double M = 0;
    double Q1 = 0;
    double Q3 = 0;
    double interQ = 0;
    double interLimit = 0;
    double interLimitInf = 0;
    double interLimitSup = 0;
    double diff = 0;
    std::vector<double> temparray = _list;

    std::sort(temparray.begin(), temparray.end());
    M = find_median(temparray);
    if (temparray.size() % 4 == 0) {
        Q1 = temparray[temparray.size() / 4 - 1];
        Q3 = temparray[3 * temparray.size() / 4 - 1];
    }
    else {
        Q1 = temparray[temparray.size() / 4];
        Q3 = temparray[3 * temparray.size() / 4];
    }
        interQ = Q3 - Q1;
        interLimit = interQ * 0.8;
        interLimitInf = Q1 - interLimit;
        interLimitSup = Q3 + interLimit;
        _interlimitinf.push_back(interLimitInf);
        _interlimitsup.push_back(interLimitSup);
        if (_interlimitinf.size() > 2) {
            if (_list.back() < _interlimitinf.at(_interlimitinf.size() - 2)) {
                _weirdest_values.push_back(_list.back());
                diff = _list.back() - _interlimitinf.at(_interlimitinf.size() - 2);
                if (diff < 0)
                    diff *= -1;
                _differences.push_back(diff);
            }
            if (_list.back() > _interlimitsup.at(_interlimitsup.size() - 2)) {
                _weirdest_values.push_back(_list.back());
                diff = _list.back() - _interlimitsup.at(_interlimitsup.size() - 2);
                if (diff < 0)
                    diff *= -1;
                _differences.push_back(diff);
            }
        }
}

void Groundhog::calc_temp_inc_av(size_t period)
{
    if (_list.size() <= period)
        return;
    _g = 0;
    for (size_t count = _list.size() - period; count != _list.size(); count++) {
        double tmp = _list[count] - _list[count - 1];
        if (tmp > 0)
            _g += tmp;
    }
    _g /= period;
}

void Groundhog::calc_relat_temp_evo(size_t period)
{
    if (_list.size() <= period)
        return;
    _last_r = _r;
    double value1 = _list[_list.size() - period - 1];
    double value2 = _list.back();
    _r = (round((value2 - value1) / value1 * 100));
}


void Groundhog::calc_standard_deviation(int period)
{
    double value1 = 0;
    double value2 = 0;
    double check = _list.size();

    check -= period;
    if (check >= 1)
        for (std::vector<double>::iterator iteration = _list.end() - period; iteration != _list.end(); iteration++) {
            value1 += *iteration;
            value2 += (*iteration * *iteration);
        }
    _s = sqrt(value2 / period - (value1 / period) * (value1 / period));
}

void Groundhog::calc(int period)
{
    calc_temp_inc_av(period);
    calc_relat_temp_evo(period);
    calc_standard_deviation(period);
}

void Groundhog::display(size_t period)
{
    static size_t count = 0;
    std::size_t test = _list.size();

    count++;
    std::cout << std::setprecision(2) << std::fixed << "g=";
    if (test <= period)
        std::cout << "nan";
    else
        std::cout << _g;
    std::cout << "\tr=";
    if (test <= period)
        std::cout << "nan";
    else
        std::cout << _r;
    std::cout << "%\ts=";
    if (test < period)
        std::cout << "nan";
    else
        std::cout << _s;
    if (count >= period && ((_last_r < 0 && _r >= 0) || (_last_r >= 0 && _r < 0)) && _last_r) {
        ++_nb_switch;
        std::cout << "\ta switch occurs";
    }
    std::cout << std::endl;
}

void Groundhog::get_five()
{
    double temp = 0;
    double weirdvalue_in = 0;
    int nb = 0;
    std::vector<double> stock;
    std::vector<double> weirdvalues_list;
    std::vector<double>::const_iterator weirdvalue = _weirdest_values.begin();

    for (int count = 0; count < 5; ++count) {
        for (std::vector<double>::const_iterator val = _differences.begin(); val != _differences.end(); ++val, ++weirdvalue) {
            for (std::vector<double>::const_iterator x = stock.begin(); x != stock.end(); ++x)
                if (*val == *x)
                    nb++;
            if (temp < *val && nb == 0) {
                temp = *val;
                weirdvalue_in = *weirdvalue;
            }
            nb = 0;
        }
        if (temp != 0) {
            weirdvalues_list.push_back(weirdvalue_in);
            stock.push_back(temp);
            temp = 0;
            weirdvalue = _weirdest_values.begin();
        }
        else {
            weirdvalues_list.push_back(0.00);
            stock.push_back(temp);
            temp = 0;
            weirdvalue = _weirdest_values.begin();
        }
    }
    std::cout << "5 weirdest values are [";
    for (std::vector<double>::const_iterator a = weirdvalues_list.begin(); a != weirdvalues_list.end(); ++a) {
         std::cout << *a;
         if (a < weirdvalues_list.end() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int Groundhog::main(int period)
{
    int test = 0;
    struct timeval tmo;
    fd_set readfds;
    int count = 0;
    struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };

    while (1) {
    fflush(stdout);

    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    tmo.tv_sec = 9.8;
    tmo.tv_usec = 0;

    switch (select(1, &readfds, NULL, NULL, &tmo)) {
    case -1:
        err(1, "select");
        break;
    case 0:
        std::cout << "Error : time out" << std::endl;
        return (84);
    }
        test = std::scanf("%s", _input);
        ++count;
        if (std::strcmp("STOP", _input) == 0 && count < period) {
            std::cout << "Error : not enough periods, exiting. " << std::endl;
            return (84);
        }
        if (std::strcmp("STOP", _input) == 0) {
            std::cout << "Global tendency switched " << _nb_switch << " times" << std::endl;
            get_five();
            return (0);
        }
        if (test == -1)
            return (84);
        for (int i = 0; _input[i]; ++i)
            if ((_input[i] < '0' || _input[i] > '9') && _input[i] != '.' && _input[i] != '-') {
                std::cout << "wrong argument type, exiting." << std::endl;
                return (84);
            }
        if (std::atof(_input) != 0) {
            _list.push_back(std::atof(_input));
            calc(period);
            get_weirdest_value();
            display(period);
        }
    }
    return (0);
}