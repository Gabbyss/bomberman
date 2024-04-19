#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <ftxui/screen/color.hpp>
#include <experimental/random>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])

{
    int fotograma = 0;
    string reset;

    while (true)
    {
        fotograma++;

        int R = std::experimental::randint(0, 255);
        int G = std::experimental::randint(0, 255);
        int B = std::experimental::randint(0, 255);

        Element personaje = spinner(21, fotograma);
        Decorator colorFondo = bgcolor(Color::RGB(R, G, B));
        Decorator colorTexto = color(Color::RGB(B, G, R));
        Element dibujo = border({hbox(personaje)}) | colorFondo | colorTexto;

        Dimensions Alto = Dimension::Fixed(7);
        Dimensions Ancho = Dimension::Fixed(15);

        Screen pantalla = Screen::Create(Ancho, Alto);

        Render(pantalla, dibujo);

        pantalla.Print();
        reset = pantalla.ResetPosition();
        cout << reset;
        this_thread::sleep_for(0.1s);
    }

    return 0;
}
