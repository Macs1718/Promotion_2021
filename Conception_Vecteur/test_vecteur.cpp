#include <algorithm>
#include <fstream>
#include "vecteur.hpp"
using algebre::vecteur;

void f( const vecteur& u, int i )
{
    std::cout << u[i] << std::endl;
    //u[i] = 4; Erreur, u constant, non modifiable !
}

int main()
{
    vecteur u(1000); // Initialiser un vecteur de 
                     // dimension 1000
    vecteur v(u);
    vecteur w({1.,2.,3.,4.,5.,6.});
    std::cout << "dimension de w : " << w.dimension() << std::endl;
    u[0] = 4.;
    vecteur w2({5.,4.,-3.,2.,1., 0.});
    vecteur w3 = w2 + w;
    std::vector<vecteur> base_de_vecteurs = 
    {    w, w3, w2,
         vecteur{1.,3.,4.,5.,7.,4.}, 
         vecteur{1.,0.,0.,0.,0.,0.}};
    std::sort(base_de_vecteurs.begin(), 
              base_de_vecteurs.end(),
              [] (const vecteur& u, const vecteur& v)
              {
                return u.normL2() < v.normL2();
              });
    std::ofstream out_fich("sortie.dat");
    out_fich << w << "\n" << w2 << "\n" << w3;
    out_fich.close();

    std::ifstream inp_fich("sortie.dat");
    vecteur u1(inp_fich);
    vecteur u2(inp_fich);
    vecteur u3(inp_fich);
    inp_fich.close();
    std::cout << "u1 : " << std::string(u1) 
              << ", u2 : " << std::string(u2)
              << ", u3 : " << std::string(u3) << std::endl;
}