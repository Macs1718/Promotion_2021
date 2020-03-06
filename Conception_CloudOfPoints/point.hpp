/**
 * @defgroup   POINT point
 *
 * @brief      Ce fichier met en oeuvre la structure point en deux dimensions.
 *
 * @author     Xavier Juvigny
 * @date       2020
 */
#ifndef _POINT_HPP_
#define _POINT_HPP_
#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief      Structure de point.
 */
struct point
{
    /**
     * L'abcisse et l'ordonnée des points
     */
    double _x, _y;

    /**
        Constructeurs et destructeur
    */
    ///@{
    /**
    Constructeur par défault créé par le compilateur (n'initialise aucune composante)
    */
    point() = default;
    /**
     * @brief      Initialise un point avec une abcisse et une ordonnée
     *
     * @param[in]  x     L'abcisse du point
     * @param[in]  y     L'ordonnée du point
     */
    point(double x, double y) : _x(x), _y(y) {}

    /**
     * Constructeur de copie par défaut créé par le compilateur : recopie l'abcisse et l'ordonnée du point passés
     * en paramètre comme coordonnée pour le nouveau point
     */
    point(const point& ) = default;
    /**
     * Constructeur de déplacement créé par le compilateur. Le nouveau point "vole" les coordonnées du point passé en
     * paramètre.
     */
    point(point&& ) = default;
    /**
     * @brief      Destructeur par défaut créé par le compilateur.
     */
    ~point() = default;
    ///@}

    point& operator = ( const point& ) = default;
    point& operator = ( point&& ) = default;

    /**
     * @brief      Ordonnancement des points par rapport à leurs ordonnées.
     * 
     * Cet opérateur de comparaison servira pour calculer l'enveloppe convexe
     *
     * @param[in]  p     Le point avec lequel comparer.
     *
     * @return     Retourne vrai si le point courant a une ordonnée plus petite que le point p
     */
    bool operator < ( const point& p )
    {
        return _y < p._y;
    }

    /**
     * @brief      Ordonnancement des points par rapport à leurs ordonnées.
     * 
     * Cet opérateur de comparaison servira pour calculer l'enveloppe convexe
     *
     * @param[in]  p     Le point avec lequel comparer.
     *
     * @return     Retourne vrai si le point courant a une ordonnée plus grande que le point p
     */
    bool operator > ( const point& p )
    {
        return _y < p._y;
    }

    /**
     * @brief      Convertit un point en une chaine de caractère pour que le point soit facilement lisible par un humain.
     */
    explicit operator std::string() const
    {
        std::ostringstream ostr;
        ostr << "(" << this->_x << "," << this->_y << ")";
        return ostr.str();
    }

};

/**
 * @brief      Operateur de flux pour les sorties des points (dans un fichier par exemple)
 *
 * @param      out   Le flux de sortie
 * @param[in]  p     Le point à écrire dans le flux de sortie
 *
 * @return     Le flux de sortie modifié après l'écriture du point
 */
std::ostream& operator << ( std::ostream& out, const point& p )
{
    out << p._x << " " << p._y;
    return out;
}

#endif