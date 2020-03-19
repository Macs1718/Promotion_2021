#include <iostream>

template<typename I, long n> constexpr I factoriel = I(n) * factoriel<I,n-1>;
template<typename I> constexpr I factoriel<I,0> = I(1);

int main()
{
    std::cout << "10! = " << factoriel<unsigned long,10> << std::endl;
    std::cout << "20! = " << factoriel<double,20> << std::endl;
    return EXIT_SUCCESS;
}