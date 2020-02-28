#include "write_svg.hpp"


int main()
{
    FILE* fich = open_svg("Essai.svg");
    write_description_svg(fich, "Un point");
    write_point_svg(fich, {0,0}, "darkblue");
    write_description_svg(fich, "Une droite");
    write_line_svg(fich, {-50,-50}, {50,50});
    for (int i = -50; i < 50; i += 5)
    {
        write_line_svg(fich, {-50,-50}, {double(i), 50}, "blue");
        write_line_svg(fich, {+50,-50}, {double(i), double(i)}, "yellow");
        write_circle_svg(fich, {0,0}, (50.-i), 2, "purple");
    }
    write_circle_svg(fich, {0,0}, 25., "pink", 0.25);
    write_rectangle_svg(fich, {-25,-25}, {25,25}, 1, "brown");    
    write_rectangle_svg(fich, {-20,-20}, {20,20}, "cyan", 0.15);
    write_triangle_svg(fich, {-30,-40}, {30,-40}, {0,40}, "green", 0.33);
    write_triangle_svg(fich, {-30,-40}, {30,-40}, {0,40}, 2, "forestgreen");
    write_text_svg(fich, {-40,40}, "Essai de texte", "royalblue", 0.75);
    close_svg(fich);
    return 0;
}