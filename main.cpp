#include <iostream>
#include <memory>



#define p(x) { std::cout << x << "\n";}


//  WZORCE PROJEKTOWE   -   NAUKA
//  Autor:  Michał Kotecki








//  SINGLETON
//  Można utworzyć tylko jeden obiekt klasy singleton.

//  Główne założenia:
//  1. Konstruktor jest prywatny - nie można go użyć do skonstruowania obiektu poza klasą.
//  2. Klasa posiada w sobie statyczny obiekt swojego typu.
//  3. Nie ma konstruktora kopiującego i operator= (są usunięte), aby nie było sposoby na skonstrukowanie kolejnych obiektów.
//  4. Przy pierwszym odwołaniu do obiektu, obiekt jest inicjalizowany. Jeżeli jest już zainicjalizowany (not null),
//  to nie trzeba go inicjalizować.


//  W poniższym przykładzie jest Uniwersum - mozę istnieć tylko jedno, więc to singleton.

class Universe
{
     static Universe * universe;

     Universe(){}
     Universe(Universe const& universe) = delete;
     void operator=(Universe const& universe) = delete;

     int Star;  //  field example

public:
    static Universe * getUniverse()
    {
         if (!universe)
         {
             p("First time universe object is used! It needs to be initialized.");
             Universe::universe = new Universe;
         }
         return universe;
    }

    int getStar() const{
        return Star;
    }

    void setStar(int star){
        this->Star = star;
    }
};

Universe * Universe::universe = 0;

int main() {

    Universe * universe = universe->getUniverse();

    universe->getUniverse()->setStar(6);
    p("Value of star:\t"); p(universe->getUniverse()->getStar());

    universe->getUniverse()->setStar(11);
    p("Value of star:\t"); p(universe->getUniverse()->getStar());

    return 0;
}

/*
    OUTPUT:

    Value of star:
    6
    Value of star:
    11

*/

//          SINGLETON   END