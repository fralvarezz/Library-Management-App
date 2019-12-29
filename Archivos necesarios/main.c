/*  Fernando Rodriguez Alvarez
    Brais Rey Noya
    Grupo 5
*/
//Por un problema con el otro miembro del grupo, finalmente hemos tenido que hacer el proyecto entre 2.

//Programa main para gestion de biblioteca particular

# include "estructura.h"
# include "libro.h"
# include "util.h"

# include <stdio.h>
# include <stdlib.h>

# include <string.h>

int menu();

int main() {
    int opcion;
    int numeroLibro;
    char ISBN[21]={0};
    int ISBNnum;
    char tituloAbuscar[100]={0};

    setLibros variosLibros;

    variosLibros.numLibros = 0; // Inicializamos el numero de Libros.

    // Valores iniciales de prueba

    strcpy(variosLibros.Libros[0].ISBN, "1111111111111");
    strcpy(variosLibros.Libros[0].titulo, "Irene");
    strcpy(variosLibros.Libros[0].autoria, "Pepe");
    strcpy(variosLibros.Libros[0].editorial, "Grijalbo");
    strcpy(variosLibros.Libros[0].formato, "papel");
    variosLibros.Libros[0].precio = 23.6;
    variosLibros.Libros[0].fecha.dia = 15;
    variosLibros.Libros[0].fecha.mes = 4;
    variosLibros.Libros[0].fecha.anho = 2013;


    strcpy(variosLibros.Libros[1].ISBN, "2222222222222");
    strcpy(variosLibros.Libros[1].titulo, "Historia de un canalla");
    strcpy(variosLibros.Libros[1].autoria, "Julia Navarro");
    strcpy(variosLibros.Libros[1].editorial, "Plaza & Janes");
    strcpy(variosLibros.Libros[1].formato, "electronico");
    variosLibros.Libros[1].precio = 12.34;
    variosLibros.Libros[1].fecha.dia = 10;
    variosLibros.Libros[1].fecha.mes = 2;
    variosLibros.Libros[1].fecha.anho = 2016;

    strcpy(variosLibros.Libros[2].ISBN, " 9788490265475");
    strcpy(variosLibros.Libros[2].titulo, "Alex");
    strcpy(variosLibros.Libros[2].autoria, "Pierre Lemaitre");
    strcpy(variosLibros.Libros[2].editorial, "Bromera");
    strcpy(variosLibros.Libros[2].formato, "papel");
    variosLibros.Libros[2].precio = 39.85;
    variosLibros.Libros[2].fecha.dia = 16;
    variosLibros.Libros[2].fecha.mes = 8;
    variosLibros.Libros[2].fecha.anho = 2015;

    strcpy(variosLibros.Libros[3].ISBN, "9788433998200");
    strcpy(variosLibros.Libros[3].titulo, "Chicos y chicas");
    strcpy(variosLibros.Libros[3].autoria, "Pepe");
    strcpy(variosLibros.Libros[3].editorial, "Anagrama");
    strcpy(variosLibros.Libros[3].formato, "electronico");
    variosLibros.Libros[3].precio = 9.49;
    variosLibros.Libros[3].fecha.dia = 5;
    variosLibros.Libros[3].fecha.mes = 10;
    variosLibros.Libros[3].fecha.anho = 2016;

    strcpy(variosLibros.Libros[4].ISBN, "9788483103937");
    strcpy(variosLibros.Libros[4].titulo, "Profundidades");
    strcpy(variosLibros.Libros[4].autoria, "Henning Mankell");
    strcpy(variosLibros.Libros[4].editorial, "Tusquets");
    strcpy(variosLibros.Libros[4].formato, "papel");
    variosLibros.Libros[4].precio = 52.23;
    variosLibros.Libros[4].fecha.dia = 1;
    variosLibros.Libros[4].fecha.mes = 5;
    variosLibros.Libros[4].fecha.anho = 2009;

    variosLibros.numLibros = 5;


    printf("\nBienvenido a GesBIBLIO--Sistema gestor de biblioteca.\n");
    do {
        opcion = menu();
        switch ( opcion ) {
            case 1: listarLibros ( variosLibros );
                    break;
            case 2: if(variosLibros.numLibros<200){
                    variosLibros.numLibros+=1;
                    anhadirLibro(&variosLibros);
                    }else{
                        printf("No hay espacio en la biblioteca");
                    };

                    break;
            case 3: printf("Introduce el titulo del libro a borrar\n");
                    leerCadena(tituloAbuscar);
                    numeroLibro=buscarTitulo(variosLibros, tituloAbuscar);
                    borrarLibro(&variosLibros, numeroLibro);
                    break;
            case 4: printf("Cual es el ISBN que quieres buscar?\n");
                    ISBNnum=leerEntero(ISBN);
                    numeroLibro=buscarISBN( variosLibros , ISBNnum);

                    if (numeroLibro < 200){
                        mostrarLibro(variosLibros.Libros[numeroLibro]);
                    }
                    else{printf("Error");};
                    break;
            case 5: printf("Escribe el titulo del libro que quieres buscar\n");
                    leerCadena(tituloAbuscar);
                    numeroLibro=buscarTitulo( variosLibros, tituloAbuscar);
                    if (numeroLibro < 200){
                        mostrarLibro(variosLibros.Libros[numeroLibro]);
                    }
                    else{printf("Error");};
                    break;
            case 6: librosDelAutor(variosLibros);
                    break;
            case 7: printf("Escribe el titulo del libro que quieres modificar\n");
                    leerCadena(tituloAbuscar);
                    numeroLibro=buscarTitulo( variosLibros, tituloAbuscar );
                    modificarLibro(&variosLibros,numeroLibro);
                    break;
            case 8: break;
        }
    } while ( opcion != 8 );
    return 0;
}


int menu()
{
    char cadenaaux[2];
    int opcion;
    printf("\n######################################################\n");
    printf("\nQue operacion desea realizar?");
    do {
        printf("\n1. Listar Libros");
        printf("\n2. Insertar Libro");
        printf("\n3. Eliminar Libro");
        printf("\n4. Buscar Libro por ISBN");
        printf("\n5. Buscar Libro por Titulo");
        printf("\n6. Mostrar libros por Autor/a");
        printf("\n7. Modificar datos de un libro");
        printf("\n8. Salir\n");
        printf("\n######################################################\n");
        printf("Opcion: ");
        opcion=leerEntero(cadenaaux);
    } while ( opcion < 0 || opcion > 8 );
    return opcion;
}
