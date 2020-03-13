#include <random>
#include <chrono>
#include <tuple>
#include "cloud_of_points.hpp"
#include "write_svg.hpp"

int main()
{
    constexpr const int taille_nuage = 50;
    //generation d'un nuage de points au hasard
    unsigned int seed = time(0);
    srand( (unsigned int) seed ) ;

    int elapsed_generation = 0;
    int elapsed_convexhull = 0;

    cloud_of_points nuage;
    nuage.reserve( taille_nuage ) ;
    for ( int i = 0; i < taille_nuage; ++i )
    {
        nuage.push_back({rand() % 100 - 50., rand() % 100 - 50.}) ;
    }

    point pmin,pmax;
    std::tie(pmin,pmax) = nuage.compute_boundingbox();
    point barycentre = nuage.compute_barycenter();

    cloud_of_points convex_hull = nuage.compute_convexhull();

    FILE* fich = open_svg("Test_cloud.svg");

    for ( const auto& p : nuage )
        write_point_svg(fich, p, "brown");
    write_rectangle_svg(fich, pmin, pmax, 1, "red");
    write_point_svg(fich, barycentre, "cyan");
    for ( int i = 0; i < convex_hull.size(); ++i )
    {
        point vi   = convex_hull[i];
        point vip1 = convex_hull[(i+1)%convex_hull.size()];
        write_triangle_svg(fich, vi, vip1, barycentre, 1, "blue");
    }
    close_svg(fich);
    return EXIT_SUCCESS;
}