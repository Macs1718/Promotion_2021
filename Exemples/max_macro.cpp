#include <iostream>

#define max(a,b) ((a) > (b) ? (a) : (b))

int main()
{
    int a = max(3,5); // a vaut 5
    double b = max(0.5*a, 7./a); // b vaut 2.5    
    std::cout << "a : " << a << " et b : " << b << std::endl;
    int c = max(a++,4); // On s'attend à ce que a vaille 6 et c vaille 5
    std::cout << "a : " << a << " et c : " << c << std::endl; // mais...
    return EXIT_SUCCESS;
}