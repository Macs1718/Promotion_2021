#include <iostream>
template<long n> constexpr long fact() {return n * fact<n-1>(); }
// Spécialisation template pour la valeur 0 :
template<> constexpr long fact<0>() { return 1L; }

int main()
{
    std::cout << fact<10>() << std::endl;
    return EXIT_SUCCESS;
}
