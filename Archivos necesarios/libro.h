#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

    # include "estructura.h"

    // Declaraciones de las funciones necesarias específicas para gestionar la biblioteca

    // Los prototipos proporcionados pueden ser modificados en sus argumentos y en el tipo de dato devuelto

    void listarLibros ( setLibros variosLibros );
    int buscarISBN( setLibros variosLibros, int isbnBuscar );
    int buscarTitulo ( setLibros variosLibros, char tituloBuscar[] );
    void anhadirLibro (setLibros *variosLibros);
    void librosDelAutor (setLibros variosLibros);
    void borrarLibro (setLibros *variosLibros, int numeroLibro);
    int comprobarFecha (int a, int m, int d);
    void mostrarLibro ( Libro elLibro );
    void modificarLibro(setLibros *variosLibros, int posicion);

#endif // LIBRO_H_INCLUDED
