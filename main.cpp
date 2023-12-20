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
ConsoleBox *consoleBox = new ConsoleBox; //  inicialización

//Declaramos la función load_script

void load_script(const char* filename, bool show_script = false)
{
    string script;
    FILE* f = nullptr;
    try
    {
        //Abrimos el archivo
        f = fopen(filename, "rb");
        if (!f)
        {
            cerr << "error de apertura de " << filename << endl;
            return;
        }
//Leemos el archivo
        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0)
        {
            buf[c] = 0;
            script.append(buf);
        }
        fclose(f);
        f = nullptr;
//Mostramos el archivo
        if (show_script)
        {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    //Capturamos la excepción
    catch (...)
    {
        cerr << "error durante la lectura del archivo" << endl;
        if (f)
            fclose(f);
    }
}
//Declaramos la función load_script
void load_script()
{
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    load_script(filename, true);
}

int main()
{
    // Uso de las funciones
    load_script();
    load_script("ejemplo.txt", true);  // Carga el script del archivo y muestra su contenido

    return 0;
}