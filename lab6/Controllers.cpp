#include "Controllers.h"

namespace {
bool is_odd(int value) {
    return value % 2 != 0;
}
}

Transfer_controller::Transfer_controller(Channel& channel, int value)
    : _channel(channel), _value(value) {}

bool Transfer_controller::await_ready() const noexcept {
    return is_odd(_value);
}

std::coroutine_handle<> Transfer_controller::await_suspend(std::coroutine_handle<> generator) noexcept {
    _channel.value = _value;
    _channel.generator = generator;
    return _channel.consumer;
}

void Transfer_controller::await_resume() const noexcept {}

Return_controller::Return_controller(const Channel& channel) : _channel(channel) {}

bool Return_controller::await_ready() const noexcept {
    return false;
}

std::coroutine_handle<> Return_controller::await_suspend(std::coroutine_handle<>) const noexcept {
    return _channel.generator;
}

void Return_controller::await_resume() const noexcept {}
