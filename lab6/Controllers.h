#pragma once

#include <coroutine>

#include "Channel.h"

class Transfer_controller {
public:
    Transfer_controller(Channel& channel, int value);

    bool await_ready() const noexcept;
    std::coroutine_handle<> await_suspend(std::coroutine_handle<> generator) noexcept;
    void await_resume() const noexcept;

private:
    Channel& _channel;
    int _value;
};

class Return_controller {
public:
    explicit Return_controller(const Channel& channel);

    bool await_ready() const noexcept;
    std::coroutine_handle<> await_suspend(std::coroutine_handle<> consumer) const noexcept;
    void await_resume() const noexcept;

private:
    const Channel& _channel;
};
