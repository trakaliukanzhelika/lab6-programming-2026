#include "Random_generator.h"

Random_generator::Random_generator(int min_value, int max_value)
    : _engine(std::random_device{}()), _distribution(min_value, max_value) {}

int Random_generator::next() {
    return _distribution(_engine);
}
