#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

    #define MAXLIBROS 200
    #define MAXTITULO 100
    #define MAXISBN 20
    #define MAXAUTORIA 50
    #define MAXEDITORIAL 50
    #define MAXFORMATO 12

// Las estructuras proporcionadas NO pueden ser modificadas

    typedef struct {
        unsigned int dia;
        unsigned int mes;
        unsigned int anho;
    } data;

    typedef struct {
        char ISBN [ MAXISBN ];
        char titulo [ MAXTITULO ];
        char autoria [ MAXAUTORIA ];
        char editorial [ MAXEDITORIAL ];
        char formato [ MAXFORMATO ];
        float precio;
        data fecha;
    } Libro;

    typedef struct {
        Libro Libros[ 200 ];  // Array donde almacenamos todos los libross
        int numLibros;  // Numero total de libros existentes en el vector Libros
    } setLibros ;

#endif // ESTRUCTURA_H_INCLUDED
