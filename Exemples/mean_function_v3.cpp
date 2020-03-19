#include <complex>
#include <iostream>
auto mean( const auto& val1, const auto& val2)
{
    return 0.5*(val1+val2);
}

int main()
{
    std::cout << "mean(1,3) = " << mean(1,3) << std::endl;
    std::cout << "mean(1.5,4.5) = " << mean(1.5,4.5) << std::endl;
    std::cout << "mean(1,3.5) = " << mean(1, 3.5) << std::endl;
    std::cout << "mean(1,2) = " << mean(1, 2) << std::endl;
    std::cout << "mean(1+i,1-3i) = " << mean(std::complex<double>(1,1), std::complex<double>(1,-3));
    return EXIT_SUCCESS;
}