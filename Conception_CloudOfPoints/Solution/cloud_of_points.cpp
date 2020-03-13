#include "cloud_of_points.hpp"
#include "enveloppe_convexe.hpp"
#include <algorithm>


cloud_of_points::operator std::string() const
{
    std::ostringstream o_str;
    o_str << "{ ";
    for ( size_type ind = 0; ind < std::min(size_type(5), this->size()); ++ind)
        o_str << std::string(this->m_set_of_points[ind]) << " ";
    if (this->size() > 5) 
    {
        o_str << " ... ";
        for ( size_type ind = this->size()-5; ind < this->size(); ++ind )
            o_str << std::string(m_set_of_points[ind]) << " ";
    }
    o_str << "}";
    return o_str.str();
}
// --------------------------------------------------------------------------------------------
std::ostream& operator << ( std::ostream& out, const cloud_of_points& cld )
{
    out << cld.size() << " ";
    for ( const auto& pt : cld )
        out << pt << " ";
    return out;
}
// --------------------------------------------------------------------------------------------
std::pair<point,point> 
cloud_of_points::compute_boundingbox() const
{
    point p_min(this->m_set_of_points[0]), p_max(this->m_set_of_points[0]);
    for ( const auto& p : *this )
    {
        p_min._x = std::min(p_min._x, p._x);
        p_min._y = std::min(p_min._y, p._y);
        p_max._x = std::max(p_max._x, p._x);
        p_max._y = std::max(p_max._y, p._y);
    }
    return {p_min,p_max};
}
// --------------------------------------------------------------------------------------------
point
cloud_of_points::compute_barycenter()  const
{
    point bary{0.,0.};
    for ( const auto& p : *this )
    {
        bary._x += p._x; bary._y += p._y;
    }
    bary._x /= this->size();
    bary._y /= this->size();
    return bary;
}
// --------------------------------------------------------------------------------------------
cloud_of_points
cloud_of_points::compute_convexhull()  const
{
    return enveloppe(*this);
}