#include "Input.h"

#include <sstream>
#include <stdexcept>
#include <string>

#include "Constants.h"

std::size_t read_count(std::istream& in) {
    std::string line;
    if (!std::getline(in, line)) {
        throw std::runtime_error("No input was provided");
    }

    std::istringstream stream(line);
    long long count{};
    if (!(stream >> count)) {
        throw std::invalid_argument("Count must be an integer");
    }

    stream >> std::ws;
    if (!stream.eof()) {
        throw std::invalid_argument("Unexpected characters after the count");
    }

    if (count < static_cast<long long>(min_count) || count > static_cast<long long>(max_count)) {
        throw std::out_of_range("Count must be in range [" + std::to_string(min_count) + ", " +
                                std::to_string(max_count) + "]");
    }

    return static_cast<std::size_t>(count);
}
