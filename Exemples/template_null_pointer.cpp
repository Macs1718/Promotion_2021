#include <iostream>
template<typename T> void display_pointer( const T* pt)
{
    std::cout << "Adresse du pointeur : " << pt << " avec des éléments de taille " << sizeof(T) << std::endl;
}

// Commenter la fonction ci-dessous pour vérifier que le programme ne compile plus.
void display_pointer( std::nullptr_t pt )
{
    std::cout << "Pointeur nul !" << std::endl;
}

int main()
{
    double x = 0; int i = 3;
    display_pointer(&x)  ; display_pointer(&i);
    display_pointer(NULL); display_pointer(nullptr);
    return EXIT_SUCCESS;
}
