#include <iostream>

template<typename T1, typename T2> auto mean( const T1& val1, const T2& val2)
{
    return (val1+val2)/2;
}

double mean( const int& val1, const int& val2 )
{
    return (val1+val2)/2.;
}

int main()
{
    std::cout << "mean(1,3) = " << mean(1,3) << std::endl;
    std::cout << "mean(1.5,4.5) = " << mean(1.5,4.5) << std::endl;
    std::cout << "mean(1,3.5) = " << mean(1, 3.5) << std::endl;
    std::cout << "mean(1,2) = " << mean(1, 2) << std::endl;
    return EXIT_SUCCESS;
}