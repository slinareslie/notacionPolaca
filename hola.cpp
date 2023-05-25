/////////funcion

int rptaPre(const string &expresion, int tam)
{
    int pila[tam];
    int top = -1;

    for (int i = expresion.length() - 1; i >= 0; i--)
    {
        char caracter = expresion[i];

        if (esOperador(caracter))
        {
            int operando1 = pila[top--];
            int operando2 = pila[top--];

            int resultado;
            switch (caracter)
            {
            case '+':
                resultado = operando1 + operando2;
                break;
            case '-':
                resultado = operando1 - operando2;
                break;
            case '*':
                resultado = operando1 * operando2;
                break;
            case '/':
                resultado = operando1 / operando2;
                break;
            case '^':
                resultado = pow(operando1, operando2);
                break;
            }

            pila[++top] = resultado;
        }
        else
        {
            pila[++top] = caracter - '0';
        }
    }

    return pila[top];
}

int rptaPost(const string &expresion, int tam)
{
    int pila[tam];
    int top = -1;

    for (int i = 0; i < expresion.length(); i++)
    {
        char caracter = expresion[i];

        if (!esOperador(caracter))
        {
            pila[++top] = caracter - '0';
        }
        else
        {
            int operando2 = pila[top--];
            int operando1 = pila[top--];

            int resultado;
            switch (caracter)
            {
            case '+':
                resultado = operando1 + operando2;
                break;
            case '-':
                resultado = operando1 - operando2;
                break;
            case '*':
                resultado = operando1 * operando2;
                break;
            case '/':
                resultado = operando1 / operando2;
                break;
            case '^':
                resultado = pow(operando1, operando2);
                break;
            }

            pila[++top] = resultado;
        }
    }

    return pila[top];
}

//////main

cout << "Resultado de la expresion prefija: " << rptaPre(expresionPrefija, expresionPrefija.size()) << "\n\n";
cout << "Resultado de la expresion postfija: " << rptaPost(expresionPostfija, expresionPostfija.size()) << "\n\n";