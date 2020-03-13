/**
 * @defgroup   CLOUD_OF_POINTS cloud of points
 *
 * @brief      Ce fichier met en oeuvre un nuage de points
 *
 * @author     Xavier Juvigny
 * @date       2020
 */
#ifndef _CLOUD_OF_POINTS_HPP
#define _CLOUD_OF_POINTS_HPP
#include <vector>
#include "point.hpp"

/**
 * @brief      Cette classe décrit un nuage de points en deux dimensions
 */
class cloud_of_points
{
public:
    /// Traits
    //@{
    using value_type     = point;
    using container_type = std::vector<point>;
    using size_type      = container_type::size_type;
    using reference      = value_type&;
    using const_reference= const value_type&;
    using pointer        = value_type*;
    using const_pointer  = const value_type*;
    using iterator       = container_type::iterator;
    using const_iterator = container_type::const_iterator;
    //@}
    /// Constructeurs et destructeur
    //@{

    /**
     * @brief      Construction par défaut
     */
    cloud_of_points() = default;

    /**
     * @brief      Construit un nouveau nuage de points contenant n sommets non initialisés
     *
     * @param[in]  n     Le nombre de points contenus dans le nuage.
     */
    cloud_of_points( size_type n ) : m_set_of_points(n) {}

    /**
     * @brief      Construit un nouveau nuage qui recopie les sommets compris entre beg(inclu) et end(exclu).
     *
     * @param[in]  beg   The beg
     * @param[in]  end   The end
     */
    cloud_of_points( const_iterator beg, const_iterator end ) : m_set_of_points(beg,end) {}

    /**
     * @brief      Créée un nouveau nuage dont les sommets sont initialisés à partir d'une liste de points donnée en paramètre.
     *
     * @param[in]  init_lst  La liste d'initialisation des points du nuage
     */
    cloud_of_points( const std::initializer_list<point>& init_lst ) : m_set_of_points(init_lst) {}

    /**
     * @brief      Constructeur de copie par défaut généré par le compilateur
     */
    cloud_of_points( const cloud_of_points& ) = default;

    /**
     * @brief      Constructeur de déplacement par défaut généré par le compilateur
     */
    cloud_of_points( cloud_of_points&& )      = default;

    /**
     * @brief      Destructeur par défaut généré par le compilateur : détruit le tableau des points
     */
    ~cloud_of_points()                        = default;    
    //@}

    /// Opérations sur les nuages de points
    //@{

    /**
     * @brief      Opérateur de copie par défaut généré par le compilateur
     */
    cloud_of_points& operator = ( const cloud_of_points& ) = default;

    /**
     * @brief      Opérateur de déplacement par défaut généré par le compilateur
     */
    cloud_of_points& operator = ( cloud_of_points&& )      = default;

    /**
     * @brief      Rajoute les points du nuage cld aux points du nuage courant
     *
     * @param[in]  cld   Le nuage contenant les points à rajouter
     *
     * @return     Le nuage courant mis à jour
     */
    cloud_of_points& operator += ( const cloud_of_points& cld )
    {
        m_set_of_points.insert(m_set_of_points.end(), cld.begin(), cld.end());
        return *this;
    }

    /**
     * @brief      Fusionne le nuage courant et le nuage cld
     *
     * @param[in]  cld   Le nuage cld à fusionner avec le nuage courant
     *
     * @return     Le nouveau nuage fusion du nuage courant et du nuage cld
     */
    cloud_of_points operator + ( const cloud_of_points& cld ) const
    {
        cloud_of_points ret_cld(cld);
        ret_cld += cld;
        return ret_cld;
    }
    //@}
    //
    /// Accesseurs et modifieurs
    //@{

    /**
     * @brief      Opérateur d'indexation du nuage de points
     *
     * @param[in]  i     L'indice du point à lire
     *
     * @return     Retourne le ième point du nuage (index commençant à zéro)
     */
    const_reference operator [] ( size_type i ) const { return m_set_of_points[i]; }

    /**
     * @brief      Opérateur d'indexation du nuage de points
     *
     * @param[in]  i     L'indice du point à lire
     *
     * @return     Retourne le ième point du nuage (index commençant à zéro)
     */
    reference operator [] ( size_type i ) { return m_set_of_points[i]; }

    /**
     * @brief      Retourne le ième point après vérification de l'indice
     *
     * Si l'indice n'est pas valide, la méthode retourne une exception de type std::out_of_range
     *
     * @param[in]  i     L'indice du point à lire.
     *
     * @return     Une référence constante sur le ième point
     */
    const_reference at( size_type i ) const { return m_set_of_points.at(i); }

    /**
     * @brief      Retourne le ième point après vérification de l'indice
     *
     * Si l'indice n'est pas valide, la méthode retourne une exception de type std::out_of_range
     *
     * @param[in]  i     L'indice du point à lire.
     *
     * @return     Une référence sur le ième point
     */
    reference at( size_type i ) { return m_set_of_points.at(i); }

    /**
     * @brief      Retourne un itérateur sur le premier point du nuage
     *
     * @return     Un itérateur sur le premier point du nuage
     */
    iterator begin() { return m_set_of_points.begin(); }
    /**
     * @brief      Retourne un itérateur sur le premier point constant du nuage
     *
     * @return     Un itérateur sur le premier point constant du nuage
     */
    const_iterator begin() const { return m_set_of_points.begin(); }
    /**
     * @brief      Retourne un itérateur après le dernier point du nuage
     *
     * @return     Un itérateur après le dernier point du nuage
     */
    iterator end() { return m_set_of_points.end(); }

    /**
     * @brief      Retourne un itérateur après le dernier point constant du nuage
     *
     * @return     Un itérateur après le dernier point constant du nuage
     */
    const_iterator end() const { return m_set_of_points.end(); }    

    /**
     * @brief      Retourne un pointeur sur le début des points du nuage
     *
     * @return     L'adresse du premier point du tableau
     */
    pointer data() { return m_set_of_points.data(); }

    /**
     * @brief      Retourne un pointeur sur le début des points du nuage
     *
     * @return     L'adresse du premier point du tableau
     */
    const_pointer data() const { return m_set_of_points.data(); }

    /**
     * @brief      Retourne une référence sur le premier point du nuage
     */
    reference front() { return m_set_of_points.front(); }
    const_reference front() const { return m_set_of_points.front(); }

    /**
     * @brief      Retourne une référence sur le dernier point du nuage
     */
    reference back() { return m_set_of_points.back(); }
    const_reference back() const { return m_set_of_points.back(); }

    /**
     * @brief      Retourne le nombre de points dans le nuage
     */
    size_type size() const { return m_set_of_points.size(); }

    /**
     * @brief      Renvoie vrai si le nuage ne contient pas de points
     */
    bool empty() const { return m_set_of_points.empty(); }

    /**
     * @brief      Le nombre de points pouvant être contenus par le nuage par rapport à la place mémoire réservée.
     *
     * @return     Retourne le nombre de points pouvant être mis dans la place mémoire allouée
     */
    size_type capacity() const { return m_set_of_points.capacity(); }
    //@}

    /**
     * @brief      Alloue suffisamment d'espace mémoire pour contenir sz points
     *
     * @param[in]  sz    Le nombre de points pouvant être contenus dans la mémoire réservée
     */
    void reserve( size_type sz ) { m_set_of_points.reserve(sz); }

    /**
     * @brief      Realloue la place mémoire pour être de la taille minimale pour contenir tous les points du nuage.
     */
    void shrink_to_fit() { m_set_of_points.shrink_to_fit(); }

    /**
     * @brief      Enlève tous les points du nuage, mais conserve la mémoire allouée.
     */
    void clear() { m_set_of_points.clear(); }

    /**
     * @brief      Enlève du nuage le point référencé par l'itérateur
     *
     * @param[in]  it    The iterator
     */
    void erase( const_iterator it) { m_set_of_points.erase(it); }

    /**
     * @brief      Rajoute à la fin du nuage une copie du point passé en argument
     *
     * @param[in]  pt    Le point à copier
     */
    void push_back(const point& pt) { m_set_of_points.push_back(pt); }

    /**
     * @brief      Rajoute à la fin du nuage le point passé en argument.
     *
     * @param      pt    Le point dont on doit déplacer les données.
     */
    void push_back(point&& pt) { m_set_of_points.push_back(std::move(pt)); }

    /**
     * @brief      Enlève le dernier point du nuage.
     */
    void pop_back() { m_set_of_points.pop_back(); }

    /**
     * @brief       Redimensionne le nuage de points pour contenir sz points.
     * 
     * Si le nombre de points actuel est plus grand sz, le nuage de points est réduit aux sz premiers points.
     *
     * @param[in]  sz    Le nouveau nombre de points.
     */
    void resize( size_type sz ) { m_set_of_points.resize(sz); }

    /**
     * @brief      Echange les points du nuage courant avec les points du nuage cld.
     *
     * @param      cld   Le nuage avec qui échanger les points.
     */
    void swap( cloud_of_points& cld ) { m_set_of_points.swap(cld.m_set_of_points); }

    explicit operator std::string() const;

    std::pair<point,point> compute_boundingbox() const;
    point                  compute_barycenter()  const;
    cloud_of_points        compute_convexhull()  const;

private:
    container_type m_set_of_points;
};

std::ostream& operator << ( std::ostream& out, const cloud_of_points& cld );
#endif