#include <cassert>
#include <cmath>
#include <sstream>
#include "vecteur.hpp"
using namespace algebre;

vecteur::vecteur( std::istream& inp ) : m_coefs(), m_norme_courante(-1)
{
    index_type n;
    inp >> n;
    m_coefs.reserve(n);
    for ( int i = 0; i < n; ++i )
    {
        element_type x;
        inp >> x;
        m_coefs.emplace_back(x);
    }
}


vecteur& 
vecteur::operator += ( const vecteur& v )
{
    assert(dimension() == v.dimension());
    for ( index_type i = 0; i < dimension(); ++i )
        (*this)[i] += v[i];
    return *this;
}

vecteur 
vecteur::operator + ( const vecteur& v ) const
{
    assert(dimension() == v.dimension());
    vecteur w(dimension());
    for ( index_type i = 0; i < dimension(); ++i )
        w[i] = (*this)[i] + v[i];
    return w;
}

auto
vecteur::operator | ( const vecteur& v ) const 
                                            -> element_type
{
    assert(dimension() == v.dimension());
    element_type scal = 0;
    for ( index_type i = 0; i < dimension(); ++i )
        scal += (*this)[i]*v[i];
    return scal;
}

auto
vecteur::normL2 () const -> element_type
{
    if (this->m_norme_courante >= 0) return m_norme_courante;
    m_norme_courante = 0;
    for ( const auto& val : *this )
        m_norme_courante += val * val;
    /*for ( const_iterator it = begin(); it != end(); ++it )
        m_norme_courante += (*it)*(*it);*/
    /*for ( index_type i = 0; i < dimension(); ++i )
        m_norme_courante += (*this)[i]*(*this)[i];*/
    m_norme_courante = std::sqrt(m_norme_courante);
    return m_norme_courante;
}

vecteur::operator std::string() const
{
    std::ostringstream output_string;
    output_string << "(";
    for ( int i = 0; i < std::min(dimension(),5); ++i )
        output_string << this->m_coefs[i] << " ";
    if (dimension() > 5) 
    {
        output_string << "...";
        for ( int i = std::max(5,dimension()-5); 
              i < dimension(); ++i )
            output_string << this->m_coefs[i] << " ";
    }
    output_string << ")";
    return output_string.str();
}

std::ostream& 
algebre::operator << ( std::ostream& out, 
                            const vecteur& u )
{
        out << u.dimension() << "\t";
        for ( const auto& val : u )
            out << val << " ";
        return out;        
}
