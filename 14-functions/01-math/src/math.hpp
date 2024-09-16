#ifndef MATH_H
#define MATH_H
#include <cstdint>

std::uint32_t fatorial(std::uint32_t n);

template <typename T>
T sum(T a, T b);
extern template T sum(T a, T b);
#endif