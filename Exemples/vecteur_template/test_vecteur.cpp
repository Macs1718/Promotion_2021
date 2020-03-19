#include <list>
#include "vecteur.hpp"
using algebra::vecteur;

int main()
{
    auto u = vecteur<double>{1.,2.,3.,4.,5.,6.};
    auto v = vecteur<double>(6);
    v[0] = v[1] = v[2] = v[3] = v[4] = v[5] = 1.;
    auto w = u + v;
    std::cout << u << " + " << v << " = " << w << std::endl;

    auto vi = vecteur<int>{1,1,1,1,1,1};
    std::cout << u << " + " << vi << " = " << u+vi << std::endl;

    std::list<double> lv2{6.,5.,4.,3.,2.,1.};
    auto v2 = vecteur<double>(lv2.begin(), lv2.end());
    std::cout << v2 << std::endl;
    return EXIT_SUCCESS;
}
