#include "Coroutines.h"

#include "Controllers.h"

Task generate_numbers(Channel& channel, Random_generator& random, std::size_t count, std::ostream& out) {
    for (std::size_t i = 0; i < count; ++i) {
        const int value = random.next();
        out << "Generator: " << value << "\n";
        co_await Transfer_controller{channel, value};
    }
}

Task print_even(const Channel& channel, std::ostream& out) {
    for (;;) {
        out << "    A: " << channel.value << "\n";
        co_await Return_controller{channel};
    }
}
