#include "helpers.hpp"
#include <algorithm>
#include <cstddef>    // std::size_t
#include <iostream>
#include <random>

/// \todo Add standard library headers as needed

namespace ex0 {

void print(const Vector& vec)
{
    for (const auto& x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}
 
void reset(Vector& vec)
{
    vec.clear();
}
 
Vector copy(const Vector& vec)
{
    return vec;
}
 
Vector concat(const Vector& a, const Vector& b)
{
    auto res = a;
    res.insert(res.end(),b.begin(), b.end());
    return res;
}
 
void swap(Vector& a, Vector& b)
{
    a.swap(b);
}
 
void fill_uniform_random(Vector& vec, std::size_t n, double lower, double upper)
{
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(lower,upper);
    vec.resize(n);
    std::generate(vec.begin(), vec.end(), [&gen, &dist]() ->auto {return dist(gen);});
}
 
void sort(Vector& vec, Compare comp)
{
    std::sort(vec.begin(), vec.end(), comp);
}

} // namespace ex0
