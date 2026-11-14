#pragma once

#include <coroutine>

struct Channel {
    int value{};
    std::coroutine_handle<> generator{};
    std::coroutine_handle<> consumer{};
};
