#pragma once

class Error final {
private:
    using T = const char* (*)();

    const T value;

public:
    consteval explicit Error(const T value) noexcept : value(value) {}

    constexpr Error(Error&&) noexcept = default;

    constexpr Error(const Error&) noexcept = default;

    constexpr ~Error() noexcept = default;

    Error& operator=(Error&&) = delete;

    Error& operator=(const Error&) = delete;

    [[nodiscard]] constexpr auto what() const noexcept -> const char* {
        return value();
    }
};