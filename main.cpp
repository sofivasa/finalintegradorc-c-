#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

//Declaramos la clase ColorConsole
struct ColorConsole
{
    //Declaramos los atributos de la clase ColorConsole
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    //Declaramos los atributos de la clase ConsoleBox
    void new_text() { /*...*/ }
    void set_text(const string &text) { cout << text << endl; }
};

//Declaramos el objeto consoleBox
ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado