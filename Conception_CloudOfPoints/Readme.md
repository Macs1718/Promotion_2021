# Nuage de points et enveloppe convexe

Introduction
============

Le but de ce projet est de créer un programme qui permet de manipuler un ensemble de points dans le plan, à savoir :
    - Rajouter ou enlever un point de l'ensemble
    - Fusionner deux ensemble de points en un ensemble
    - Calculer la boîte englobante de l'ensemble
    - Calculer le barycentre de l'ensemble
    - Calculer l'enveloppe convexe de l'ensemble (optionnelle)

Deux fichiers sont inclus avec ce mini-projet :
    - Un fichier mettant en oeuvre un algorithme de calcul d'enveloppe convexe, qui vous permettra en partie de bien définir l'interface de votre classe manipulant votre ensemble de point (ayant comme nom de classe `cloud_of_points`).
    - Un fichier proposant des fonctions permettant d'écrire un fichier vectoriel au format svg permettant d'afficher graphiquement votre nuage, vos boîtes, etc. à l'aide de votre navigateur préféré ( firefox, safary, edge, etc. ). Un fichier exemple générant un fichier au format svg est fourni : `exemple_svg.cpp`.

Une structure basique `point` est proposée. N'hésitez pas à l'enrichir, voire à la modifier. 

Documentation des fonctionnalités voulues
=========================================

Le nom de la classe représentant un nuage de points est imposé : `cloud_of_points`.

Modifieurs de nuage de points
-----------------------------

Trois fonctionnalités sont demandées, modifiant ou calculant un nouveau nuage de point, à savoir :
- La possiblité de rajouter un point à un nuage : à la fin de l'ensemble des points, ou bien à une certaine position dans l'ensemble des points
- Enlever un point en indiquant sa position dans le nuage de points
- À partir de deux nuages de points, créer un nuage de points qui est la fusion des deux nuages. On ne s'occupe pas d'éventuels doublons...

Calcul sur un nuage de points
-----------------------------

Trois fonctionnalités sont également demandées sur les nuages de points :
- Calculer une boîte alignée par rapport aux axes, de taille minimale englobant un nuage de points
- Calculer le point barycentre des points appartenant à un nuage de points
- Calculer l'enveloppe convexe d'un nuage de points. L'algorithme est mis en oeuvre dans `calcul_enveloppe.cpp` mais demande à rajouter les méthodes adéquates pour les points et pour le nuage de points.

Test et validation
==================
On cherchera à valider chacune de ces fonctionnalités à l'aide d'un ou plusieurs programmes tests qui pourront écrire une sortie au format SVG permettant
visuellement de valider l'une ou l'autre fonctionnalité.

Le format SVG
--------------
Le format SVG est un format graphique vectoriel compatible avec le HTML 5. Il est interprétable par tout browser relativement récent. C'est un langage à balise
basé sur la norme xml (qui représente un arbre). Le fichier `write_svg.hpp` propose diverses fonctions permettant d'écrire facilement ce fichier. Pour la compilation, il faudra compiler en plus d'un programme test, le fichier `write_svg.cpp` pour pouvoir l'utiliser.

Le fichier exemple `exemple_svg.cpp` vous permet de voir la façon de créer un tel fichier.
Le fichier `write_svg.hpp` propose les fonctionnalités suivantes :
- Ouverture d'un fichier au format svg en écriture (la fonction écrit l'entête attendue pour un tel fichier) :
    FILE* open_svg(const char* fileName)
- Rajoute un commentaire dans le fichier  SVG (non représenté à l'écran):
    void write_description_svg(FILE* fich, const std::string& desc)
- Rajoute un point dans le fichier SVG (sous forme de petit rectangle) avec une couleur donnée (par défaut, noire) :
    void write_point_svg(FILE* fich, const point& p, const std::string&  col = "black" )
- Rajoute une ligne allant du point p1 au point p2 avec une couleur donnée (rouge par défaut) :
    void write_line_svg(FILE* fich, const point& p1, const point& p2, const std::string& color = "red")
- Rajoute un cercle creux de centre p et de rayon r avec une couleur donnée pour la bordure (bleue par défaut) et une épaisseur (de 1 par défaut)
    void write_circle_svg(FILE* fich, const point& p, double r, int thick = 1, const std::string& color = "blue")
- Rajoute un cercle plein de centre p et de rayon r avec une certaine opacité (1 = opaque, 0 = complètement transparent, 0.5 : 50% transparent, etc.)
    void write_circle_svg(FILE* fich, const point& p, double r, const std::string& fill_color, double fill_opactity = 1.)
- Rajoute un rectangle creux ayant pour coins opposés p_min et p_max (coords min et max) avec une certaine épaisseur et couleur pour le bord
    void write_rectangle_svg(FILE* fich, const point& p_min, const point& p_max, int thick = 1, const std::string& color = "red" )
- Rajoute un rectangle plein ayant pour coins opposés p_min et p_max (coords min et max) avec une couleur et opacité donnée :
    void write_rectangle_svg(FILE* fich, const point& p_min, const point& p_max, const std::string& fill_color, double fill_opacity = 1.)
- Rajoute un texte sur l'image avec un éventuel remplissage et une certaine opacité (Note : je n'ai pas trouvé comment donner une taille au texte...) :
    void write_text_svg(FILE* fich, const point& origin, const std::string& texte, const std::string& fill_color = "black", double fill_opacity = 1. )
- Affiche un triangle creux avec une couleur et une épaisseur données pour le bord
    void write_triangle_svg(FILE* fich, const point& p1, const point& p2, const point& p3, int thick = 1, const std::string& color = "red")
- Affiche un triangle plein avec une opacitée et une couleur données pour le remplissage
    void write_triangle_svg(FILE* fich, const point& p1, const point& p2, const point& p3, const std::string& fill_color, double fill_opacity = 1.)
- Referme un fichier svg en complétant le fichier avec les balises de fin demandées par le format svg.
    void close_svg(FILE* fich)

Pour les couleurs possibles en SVG, vous pouvez vous référer au [lien html suivant](https://www.december.com/html/spec/colorsvgsvg.html)

D'autres formes sont possibles, ainsi que la gestion des gradients de couleurs. Les fonctionnalités proposées par `write_svg` ne demandent donc que d'être encore enrichies (et le seront sans doute dans un futur proche !).
