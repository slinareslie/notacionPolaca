#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <bits/stdc++.h>

using namespace std;

bool pilaVacia(int top)
{
    return (top == -1);
}

bool pilaLlena(int top, int tam)
{
    return (top == tam - 1);
}

void push(char pila[], int &top, char item, int tam)
{
    if (pilaLlena(top, tam))
        return;
    pila[++top] = item;
}

char pop(char pila[], int &top)
{
    if (pilaVacia(top))
        return '\0';
    return pila[top--];
}

bool esOperador(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int prioridad(char operador)
{
    if (operador == '+' || operador == '-')
        return 1;
    else if (operador == '*' || operador == '/')
        return 2;
    else if (operador == '^')
        return 3;
    return 0;
}

string eInfija(const string &expresion, int tam)
{
    char pila[tam];
    int top = -1;
    string expresionPolaca;

    for (int i = expresion.length() - 1; i >= 0; i--)
    {
        char caracter = expresion[i];

        if (!esOperador(caracter) && caracter != '(' && caracter != ')')
        {
            expresionPolaca += caracter;
        }
        else if (caracter == ')')
        {
            push(pila, top, caracter, tam);
        }
        else if (caracter == '(')
        {
            while (!pilaVacia(top) && pila[top] != ')')
            {
                expresionPolaca += pop(pila, top);
            }

            if (!pilaVacia(top))
                pop(pila, top);
        }
        else
        {
            while (!pilaVacia(top) && prioridad(pila[top]) > prioridad(caracter))
            {
                expresionPolaca += pop(pila, top);
            }
            push(pila, top, caracter, tam);
        }
    }

    while (!pilaVacia(top))
    {
        expresionPolaca += pop(pila, top);
    }

    reverse(expresionPolaca.begin(), expresionPolaca.end());

    return expresionPolaca;
}

string ePostfija(const string &expresion, int tam)
{
    char pila[tam];
    int top = -1;
    string expresionPostfija;

    for (int i = 0; i < expresion.length(); i++)
    {
        char caracter = expresion[i];

        if (!esOperador(caracter) && caracter != '(' && caracter != ')')
        {
            expresionPostfija += caracter;
        }
        else if (caracter == '(')
        {
            push(pila, top, caracter, tam);
        }
        else if (caracter == ')')
        {
            while (!pilaVacia(top) && pila[top] != '(')
            {
                expresionPostfija += pop(pila, top);
            }

            if (!pilaVacia(top))
                pop(pila, top);
        }
        else
        {
            while (!pilaVacia(top) && prioridad(pila[top]) >= prioridad(caracter))
            {
                expresionPostfija += pop(pila, top);
            }
            push(pila, top, caracter, tam);
        }
    }

    while (!pilaVacia(top))
    {
        expresionPostfija += pop(pila, top);
    }

    return expresionPostfija;
}

#endif