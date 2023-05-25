#include "funciones.h"

using namespace std;

int main()
{
    string expresionInfija;
    cout << "\nInserte una expresion infija:\n";
    cin >> expresionInfija;
    string expresionPrefija = eInfija(expresionInfija, expresionInfija.size());
    string expresionPostfija = ePostfija(expresionInfija, expresionInfija.size());

    cout << "\n\nExpresion infija: " << expresionInfija << "\n\n";
    cout << "Expresion prefija: " << expresionPrefija << "\n\n";
    cout << "Expresion postfija: " << expresionPostfija << "\n\n";

    return 0;
}
