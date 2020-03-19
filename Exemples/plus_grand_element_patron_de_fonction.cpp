#include <iostream>
#include <vector>
#include <list>

// Patron de fonction
template<typename C> auto plus_grand_element(const C& container)
{
    auto max_value = *container.begin();
    for ( const auto& value : container )
        if (value > max_value ) max_value = value;
    return max_value;
}

// Programme principal:
int main()
{
    std::vector<double> vfield{1., -2., 3., 2.5, 4., -6.};
    std::list<int> lindices{1, 3, 2, 7, 5, 4, 8, 3, 4};

    std::cout << "max dans vfield  : " << plus_grand_element(vfield) << std::endl;
    std::cout << "max dans lindices: " << plus_grand_element(lindices) << std::endl;
    return EXIT_SUCCESS;
}
