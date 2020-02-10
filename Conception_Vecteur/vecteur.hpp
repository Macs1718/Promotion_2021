#ifndef _ALGEBRE_VECTEUR_HPP
#define _ALGEBRE_VECTEUR_HPP
#include <vector>
#include <iostream>
#include <string>

namespace algebre
{
    class vecteur
    {
    public:
        using element_type = double;
        using container_type = std::vector<element_type>;
        using index_type   = int;
        using iterator     = container_type::iterator;
        using const_iterator = container_type::const_iterator;
        vecteur() = default;// Prends le constructeur par défaut généré par le compilateur
        vecteur(index_type dim) : m_coefs(dim), m_norme_courante(-1)
        {}
        vecteur( const std::initializer_list<element_type>& coefs) :
            m_coefs(coefs), m_norme_courante(-1)
        {}
        vecteur( std::istream& inp );
        vecteur(const vecteur& u) = default; // Constructeur de copie ( pris par défaut )
        vecteur( vecteur&& u ) = default;
        ~vecteur() = default;        

        vecteur& operator = ( const vecteur& u ) = default;
        vecteur& operator = ( vecteur&& u ) = default;

        index_type dimension() const 
        { return this->m_coefs.size(); }
        index_type size() const { return m_coefs.size(); }
        element_type operator []  ( index_type i ) const
        { return m_coefs[i]; }
        element_type& operator [] ( index_type i )
        {
            m_norme_courante = -1; 
            return m_coefs[i]; 
        }

        vecteur& operator += ( const vecteur& v );
        vecteur operator + ( const vecteur& v ) const;
        element_type operator | ( const vecteur& v ) const;
        element_type normL2() const;

        iterator begin() { return m_coefs.begin(); }
        iterator end()   { return m_coefs.end(); }
        const_iterator begin() const { return m_coefs.begin(); }
        const_iterator end() const { return m_coefs.end(); }

        explicit operator std::string() const;
    private:
        container_type m_coefs;
        mutable element_type m_norme_courante;
    };

    std::ostream& operator << ( std::ostream& out, 
                                const vecteur& u );

}
#endif