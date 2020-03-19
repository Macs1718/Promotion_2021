#include <iostream>
#include <complex>
using namespace std::literals::complex_literals;
#include <cmath>

/** Le premier paramètre template est le type de la fonction à évaluer. Le deuxième est le corps où la fonction prend ses valeurs
*/
template<typename Function, typename K> auto df_s_dh( const Function& f, const K& h, const K& x,
                                                      const decltype((std::abs(h)))& eps = 1.E-6 )
{
    auto norm_h = std::abs(h); // On devrait lancer une exception sir norm_h est plus petit qu'une certaine valeur. Possible mais pas fait ici.
    K dh = eps * h / norm_h;
    return K(1./eps) * (f(x+dh) - f(x));
}

/** On spécialise la dérivée directionnelle pour les réelles en la transformant en simple dérivée :
*/
template<typename Function> double df_s_dh(const Function& f, const double& h, const double& x)
{
    return (1./h)*(f(x+h)-f(x));
}

double f(double x)
{
    return std::sin(x*x);
}

std::complex<double> g(const std::complex<double>& z)
{
    return z * std::exp(z);    
}

int main()
{
    double x = 3.;
    std::complex<double> z = 0.5 + 1.i;
    auto dsqrt   = df_s_dh((double(*)(double))std::sqrt, 1.E-6, x);
    auto df = df_s_dh(f, 1.E-6, x);
    auto dg = df_s_dh(g, 1. + 1.i, z);
    auto dh = df_s_dh([](const std::complex<double>& z){ return z*z; }, 1. + 1.i, 0. + 0.5i);

    std::cout << "Pour x = 3, on a :" << std::endl;
    std::cout << "d sqrt(x) = " << dsqrt << std::endl;
    std::cout << u8"d sin(x²) = " << df << std::endl;
    std::cout << "d z.e^z /d(1+i) (0.5+i) = " << dg << std::endl;
    std::cout << "d z*z / d(1+i) (0.5i) = " << dh << std::endl;
    return EXIT_SUCCESS; 
}