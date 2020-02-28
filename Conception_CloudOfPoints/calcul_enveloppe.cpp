#include <cmath>
#include <list>

/*
  foncteur qui permet de classer deux points suivant l'angle entre l'axe des x et le vecteur
  forme par chacun des points et un p donne.
*/
class sens_trigo
{
public:
    sens_trigo( const point & p ) :_p( p )
    {}
    bool operator()( const point & a , const point & b )
    {
        double tta_a = atan2( a._y - _p._y , a._x - _p._x ) ;
        double tta_b = atan2( b._y - _p._y , b._x - _p._x ) ;
        return  tta_a > tta_b ;
    }
private:
    point _p ;
};


cloud_of_points enveloppe( const cloud_of_points& nuage )
{
    std::list<point> nuage_lst(nuage.begin(), nuage.end());
    //Recherche du point le plus bas
    nuage_lst.sort(le_plus_bas);
    point bas = nuage_lst.front() ;
    nuage_lst.pop_front();

    //Tri du reste du nuage en fonction des angles par rapport au point le plus bas
    nuage_lst.sort(sens_trigo(bas));

    //On place le point le plus bas dans l'enveloppe
    cloud_of_points env ;
    env.push_back( bas ) ;

    //On replace egalement le point le plus bas a la fin du nuage
    nuage_lst.push_back( bas ) ;

    //Tant qu'il y a des points dans le nuage...
    while ( !nuage_lst.empty() )
    {
        //On retire le premier point du nuage et on le place dans l'enveloppe
        env.push_back( nuage_lst.front() ) ;
        nuage_lst.pop_front() ;

        //Tant qu'il y a au moins 4 points dans l'enveloppe...
        while ( env.size() >= 4 )
        {
            size_t n = env.size() - 1 ;
            const point & b = env[ n ] ;
            const point & p2 = env[ n - 1 ] ;
            const point & p1 = env[ n - 2 ] ;
            const point & a = env[ n - 3 ] ;

            //Si les points a et b sont du meme cote que la droite passant par p1 et p2
            if ( ! droite( p1 , p2 ).meme_cote( a , b ) )
            {
                env.erase( env.begin() + n - 1 ) ;
            }
            else
            {
                //sinon on quitte la boucle
                break ;
            }
        }
    }
    return env ;
}
