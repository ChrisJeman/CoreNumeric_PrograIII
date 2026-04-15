#ifndef CORE_NUMERIC_H
#define CORE_NUMERIC_H

#include <vector>
#include <concepts>
#include <iterator>
#include <type_traits>

using namespace std;

namespace core_numeric {

template <typename C>
concept Iterable = requires(C c) {
    begin(c);
    end(c);
};

template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> same_as<T>;
};

template <typename T>
concept Divisible = requires(T a, size_t n) {
    { a / n } -> same_as<T>;
};

template <typename T>
concept Comparable = requires(T a, T b) {
    { a > b } -> same_as<bool>;
};

template <Iterable C>
requires Addable<typename C::value_type>
auto sum(const C& container) {

    using T = typename C::value_type;

    T result{};

    for (const auto& value : container) {
        result = result + value;
    }

    return result;
}

template <Iterable C>
requires Addable<typename C::value_type> && Divisible<typename C::value_type>
auto mean(const C& container) {

    using T = typename C::value_type;

    T total = sum(container);

    size_t count = 0;

    for (const auto& _ : container) {
        count++;
    }

    if constexpr (is_integral_v<T>) {
        return static_cast<double>(total) / count;
    } else {
        return total / count;
    }
}

template <Iterable C>
requires Addable<typename C::value_type>
auto variance(const C& container) {

    using T = typename C::value_type;

    T m = mean(container);

    T result{};

    size_t count = 0;

    for (const auto& value : container) {
        T diff = value - m;
        result = result + diff * diff;
        count++;
    }
    return result / count;
}

template <Iterable C>
requires Comparable<typename C::value_type>
auto max(const C& container) {

    auto it = begin(container);
    auto max_val = *it;
    ++it;
    for (; it != end(container); ++it) {
        if (*it > max_val) {
            max_val = *it;
        }
    }
    return max_val;
}

template <Iterable C, typename Func>
requires Addable<typename C::value_type>
auto transform_reduce(const C& container, Func f) {

    using T = typename C::value_type;
    T result{};
    for (const auto& value : container) {
        result = result + f(value);
    }
    return result;
}

template <typename... Args>
requires Addable<common_type_t<Args...>>
auto sum_variadic(Args... args) {
    return (args + ...);
}

template <typename... Args>
requires Addable<common_type_t<Args...>> && Divisible<common_type_t<Args...>>
auto mean_variadic(Args... args) {

    auto total = (args + ...);
    size_t count = sizeof...(args);
    return total / count;
}

template <typename... Args>
requires Addable<common_type_t<Args...>>
auto variance_variadic(Args... args) {

    using T = common_type_t<Args...>;
    T m = mean_variadic(args...);
    T result{};
    ((result += (args - m) * (args - m)), ...);
    return result / sizeof...(args);
}

template <typename... Args>
requires Comparable<common_type_t<Args...>>
auto max_variadic(Args... args) {
    auto max_val = (args, ...);
    ((max_val = max_val > args ? max_val : args), ...);
    return max_val;
}

}
#endif