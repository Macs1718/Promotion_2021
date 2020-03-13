#include "enveloppe_convexe.hpp"

#include <cmath>
#include <list>

namespace  // Namespace anonyme...
{
    /*
        foncteur qui permet de classer deux points suivant l'angle entre l'axe des x et le vecteur
        forme par chacun des points et un p donne.
    */
    class sens_trigo
    {
      public:
        sens_trigo(const point& p) : _p(p) {}
        bool
        operator()(const point& a, const point& b)
        {
            double tta_a = atan2(a._y - _p._y, a._x - _p._x);
            double tta_b = atan2(b._y - _p._y, b._x - _p._x);
            return tta_a > tta_b;
        }

      private:
        point _p;
    };

    /*
      droite construite a partir de deux points
      dont l'equation est de la forme ax + by + c = 0
    */
    class droite
    {
      private:
        double _a;
        double _b;
        double _c;

      public:
        droite(const point& p1, const point& p2)
          : _a(p2._y - p1._y), _b(-p2._x + p1._x), _c(p1._y * p2._x - p1._x * p2._y)
        {
        }
        /* Renvoie true si p1 et p2 sont du meme cote de la droite,
           c'est-a-dire si le signe de ax + by + c pour chacun des points est le meme
        */
        bool
        meme_cote(const point& p1, const point& p2)
        {
            return (_a * p1._x + _b * p1._y + _c) * (_a * p2._x + _b * p2._y + _c) > 0;
        }
    };
}  // namespace

cloud_of_points
enveloppe(const cloud_of_points& nuage)
{
    std::list<point> nuage_lst(nuage.begin(), nuage.end());
    // Recherche du point le plus bas
    nuage_lst.sort();
    point bas = nuage_lst.front();
    nuage_lst.pop_front();

    // Tri du reste du nuage en fonction des angles par rapport au point le plus bas
    nuage_lst.sort(sens_trigo(bas));

    // On place le point le plus bas dans l'enveloppe
    cloud_of_points env;
    env.push_back(bas);

    // On replace egalement le point le plus bas a la fin du nuage
    nuage_lst.push_back(bas);

    // Tant qu'il y a des points dans le nuage...
    while (!nuage_lst.empty()) {
        // On retire le premier point du nuage et on le place dans l'enveloppe
        env.push_back(nuage_lst.front());
        nuage_lst.pop_front();

        // Tant qu'il y a au moins 4 points dans l'enveloppe...
        while (env.size() >= 4) {
            size_t       n  = env.size() - 1;
            const point& b  = env[n];
            const point& p2 = env[n - 1];
            const point& p1 = env[n - 2];
            const point& a  = env[n - 3];

            // Si les points a et b sont du meme cote que la droite passant par p1 et p2
            if (!droite(p1, p2).meme_cote(a, b)) {
                env.erase(env.begin() + n - 1);
            } else {
                // sinon on quitte la boucle
                break;
            }
        }
    }
    return env;
}
