#ifndef _ALGEBRA_VECTEUR_HPP_
#define _ALGEBRA_VECTEUR_HPP_
#include <cassert>
#include <vector>
#include <iostream>

namespace algebra
{
    template<typename K>
    class vecteur
    {
    public:
        using index_t = std::size_t;
        using value = K;
        using container = std::vector<K>;
        using reference = value&;
        using const_reference = const value&;
        using iterator = typename container::iterator;
        using const_iterator = typename container::const_iterator;

        vecteur() = default;
        vecteur( index_t dim ) : m_arr_coefs(dim)
        {}
        vecteur( const std::initializer_list<K>& li ) : m_arr_coefs(li)
        {}
        template<typename Iterator> vecteur( const Iterator& beg, const Iterator& end ) : m_arr_coefs(beg,end)
        {}
        vecteur( const vecteur& u ) = default;
        vecteur( vecteur&& u) = default;

        index_t dimension() const 
        {
            return m_arr_coefs.size(); 
        }

        reference operator [] ( index_t i )
        {
            return m_arr_coefs[i];
        }

        const_reference operator[] (index_t i) const
        {
            return m_arr_coefs[i];
        }

        iterator begin() { return m_arr_coefs.begin(); }
        const_iterator begin() const { return m_arr_coefs.begin(); }

        iterator end() { return m_arr_coefs.end(); }
        const_iterator end() const { return m_arr_coefs.end(); }

        vecteur operator + ( const vecteur& u ) const;
        template<typename K2> vecteur
        operator + ( const vecteur<K2>& u ) const;
    private:
        container m_arr_coefs;
    };

    template<typename K> auto
    vecteur<K>::operator + ( const vecteur& u ) const -> vecteur
    {
        assert(this->dimension() == u.dimension());
        vecteur v(dimension());
        for ( index_t i = 0; i < dimension(); ++i)
            v[i] = m_arr_coefs[i] + u[i];
        return v;
    }

    template<typename K> template<typename K2> auto 
    vecteur<K>::operator + ( const vecteur<K2>& u ) const -> vecteur
    {
        assert(this->dimension() == u.dimension());
        vecteur v(dimension());
        for ( index_t i = 0; i < dimension(); ++i)
            v[i] = m_arr_coefs[i] + u[i];
        return v;        
    }
}

template<typename K> 
std::ostream& operator << ( std::ostream& out, const algebra::vecteur<K>& u )
{
    out << "< ";
    for (const auto& val : u )
        out << val << " ";
    out << ">";
    return out;
}

#endif