#include <iostream>

template<typename T> auto mean( const T& val1, const T& val2)
{
    return (val1+val2)/2.;
}

int main()
{
    std::cout << "mean(1,3) = " << mean(1,3) << std::endl;
    std::cout << "mean(1.5,4.5) = " << mean(1.5,4.5) << std::endl;
    return EXIT_SUCCESS;
}