#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

    // Declaraciones de las funciones necesarias para leer enteros, reales y cadenas de caracteres
    // Para evitar problemas, es recomendable leer todo como vectores de caracteres, y después, si es necesario, traducir a enteros (atoi) o flotantes (atof)
    // Los prototipos proporcionados pueden ser modificados en sus argumentos y en el tipo de dato devuelto

    float leerFlotante ( char mensaje []);
    int leerEntero ( char mensaje [] );
    void leerCadena ( char cad [] );

#endif // UTIL_H_INCLUDED
