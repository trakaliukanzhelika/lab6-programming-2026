#pragma once

#include <cstddef>
#include <ostream>

#include "Channel.h"
#include "Random_generator.h"
#include "Task.h"

Task generate_numbers(Channel& channel, Random_generator& random, std::size_t count, std::ostream& out);
Task print_even(const Channel& channel, std::ostream& out);
