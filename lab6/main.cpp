#include <cstdlib>
#include <exception>
#include <iostream>

#include "Channel.h"
#include "Constants.h"
#include "Coroutines.h"
#include "Input.h"
#include "Random_generator.h"
#include "Task.h"

int main() {
    try {
        std::cout << "Enter the count of numbers [" << min_count << ", " << max_count << "]: ";
        const std::size_t count = read_count(std::cin);

        Random_generator random(min_random_value, max_random_value);
        Channel channel;

        const Task consumer = print_even(channel, std::cout);
        channel.consumer = consumer.handle();

        const Task generator = generate_numbers(channel, random, count, std::cout);
        generator.resume();
    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
