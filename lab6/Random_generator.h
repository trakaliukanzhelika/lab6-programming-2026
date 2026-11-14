#pragma once

#include <random>

class Random_generator {
public:
    Random_generator(int min_value, int max_value);

    int next();

private:
    std::mt19937 _engine;
    std::uniform_int_distribution<int> _distribution;
};
