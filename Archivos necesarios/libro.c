# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "libro.h"
# include "util.h"
 // Defniciones de las funciones necesarias específicas para gestionar la biblioteca



void mostrarLibro( Libro elLibro )
{
    char meses [ ][ 12 ] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};      // Para visualizar los meses
    printf("\n\tTitulo: %s", elLibro.titulo);
    printf("\n\tISBN: %s", elLibro.ISBN);
    printf("\n\tAutor/a: %s", elLibro.autoria);
    printf("\n\tEditorial: %s", elLibro.editorial);
    printf("\n\tFormato: %s", elLibro.formato);
    printf("\n\tPrecio: %.2f", elLibro.precio);
    printf("\n\tFecha: %d de %s de %d", elLibro.fecha.dia, meses [ elLibro.fecha.mes -1 ], elLibro.fecha.anho);
    printf("\n------------------------------------------------------\n");
}

void listarLibros( setLibros variosLibros )  //Listar todas los libros
{
    int i;
    if ( variosLibros.numLibros == 0 )
        printf("\nNo existen libros que listar.\n");
    else {
        printf("\nListando libros...\n");
        for (i = 0; i < variosLibros.numLibros; i++ ) {
            printf("\nLibro %d: ", i);
            mostrarLibro( variosLibros.Libros[ i ] );
        }
    }
}

int buscarISBN( setLibros variosLibros, int isbnBuscar ){

int i;
int ISBNnumer;

for (i=0;i<variosLibros.numLibros;i++){
    ISBNnumer=atoi(variosLibros.Libros[i].ISBN);
    if (ISBNnumer == isbnBuscar){
        return i;
    }
}
return 250;
}


int buscarTitulo( setLibros variosLibros, char tituloBuscar[] ){

int i;
for (i=0;i<variosLibros.numLibros;i++){
    if ((strcmp(variosLibros.Libros[i].titulo, tituloBuscar)) == 0){
        return i;
    }
}
return 250;
}


void anhadirLibro(setLibros *variosLibros){

char cadena[100];
int anho,mes,dia;

//Titulo
printf("\nEscribe el titulo del libro: ");
leerCadena(cadena);
strcpy(variosLibros->Libros[variosLibros->numLibros-1].titulo,cadena);

//Autor
printf("\nEscribe el autor del libro: ");
leerCadena(cadena);
strcpy(variosLibros->Libros[variosLibros->numLibros-1].autoria,cadena);

//Editorial
printf("\nEscribe la editorial del libro: ");
leerCadena(cadena);
strcpy(variosLibros->Libros[variosLibros->numLibros-1].editorial,cadena);

//ISBN
printf("\nEscribe el ISBN del libro: ");
leerCadena(cadena);
strcpy(variosLibros->Libros[variosLibros->numLibros-1].ISBN,cadena);

//Formato
printf("\nEscribe el formato del libro: ");
leerCadena(cadena);
strcpy(variosLibros->Libros[variosLibros->numLibros-1].formato,cadena);

//Precio
printf("\nEscribe el precio del libro: ");
variosLibros->Libros[variosLibros->numLibros-1].precio=leerFlotante(cadena);

//Fecha
printf("\nIntroduce el anho: ");
anho=leerEntero(cadena);
printf("\nIntroduce el mes: ");
mes=leerEntero(cadena);
printf("\nIntroduce el dia: ");
dia=leerEntero(cadena);

while(comprobarFecha(anho,mes,dia)==0){
printf("\nError. Escribe una fecha correcta.\n");
printf("\nIntroduce el anho: ");
anho=leerEntero(cadena);
printf("\nIntroduce el mes: ");
mes=leerEntero(cadena);
printf("\nIntroduce el dia: ");
dia=leerEntero(cadena);
}
variosLibros->Libros[variosLibros->numLibros-1].fecha.anho=anho;
variosLibros->Libros[variosLibros->numLibros-1].fecha.mes=mes;
variosLibros->Libros[variosLibros->numLibros-1].fecha.dia=dia;
}


void librosDelAutor(setLibros variosLibros){
int i=0;
char autor[50];
printf("Introduce el nombre del autor\n");
leerCadena(autor);
for(i=0;i<variosLibros.numLibros;i++){
    if(strcmp(variosLibros.Libros[i].autoria,autor)==0){
        mostrarLibro(variosLibros.Libros[i]);
    }
}
}

void borrarLibro(setLibros *variosLibros, int numeroLibro){
int i;
for(i=numeroLibro;i<variosLibros->numLibros;i++){
    variosLibros->Libros[i]=variosLibros->Libros[i+1];
}
variosLibros->numLibros-=1;

strcpy(variosLibros->Libros[variosLibros->numLibros].ISBN, "0000000000000");
    strcpy(variosLibros->Libros[variosLibros->numLibros].titulo, "LibroVacio");
    strcpy(variosLibros->Libros[variosLibros->numLibros].autoria, "LibroVacio");
    strcpy(variosLibros->Libros[variosLibros->numLibros].editorial, "LibroVacio");
    strcpy(variosLibros->Libros[variosLibros->numLibros].formato, "Librovacio");
    variosLibros->Libros[variosLibros->numLibros].precio = 0.0;
    variosLibros->Libros[variosLibros->numLibros].fecha.dia = 0;
    variosLibros->Libros[variosLibros->numLibros].fecha.mes = 0;
    variosLibros->Libros[variosLibros->numLibros].fecha.anho = 0000;

}

int comprobarFecha(int anho, int mes, int dia){
    int maximo;

    if (mes < 1 || mes > 12) {
        return 0;
    }
    if (dia < 1) {
        return 0;
    }

    maximo = 31;
    if (mes == 2) {
        maximo = 28;
        if (anho % 400 == 0 || (anho % 4 == 0 && anho % 100 != 0)) {
            maximo = 29;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        maximo = 30;}

    if (dia > maximo) {
        return 0;
    }
    return 1;
}

void modificarLibro(setLibros *variosLibros, int posicion){
    char cadena[100];
    int opcion;
    int anho,mes,dia;
    do{
        printf("Que quieres modificar?\n\t");
        printf("\n1. Titulo");
        printf("\n2. Autor");
        printf("\n3. Editorial");
        printf("\n4. ISBN");
        printf("\n5. Formato");
        printf("\n6. Fecha");
        printf("\n7. Precio");
        printf("\n8. Salir\n");
        printf("\n######################################################\n");
        opcion=leerEntero(cadena);
    }while(opcion>8||opcion<1);

    switch(opcion){

        case 1: printf("\nIntroduce el nuevo titulo: ");
                leerCadena(cadena);
                strcpy(variosLibros->Libros[posicion].titulo,cadena);
                break;

        case 2: printf("\nIntroduce el nuevo autor: ");
                leerCadena(cadena);
                strcpy(variosLibros->Libros[posicion].autoria,cadena);
                break;

        case 3: printf("\nIntroduce la nueva editorial: ");
                leerCadena(cadena);
                strcpy(variosLibros->Libros[posicion].editorial,cadena);
                break;

        case 4: printf("\nIntroduce el nuevo ISBN: ");
                leerCadena(cadena);
                strcpy(variosLibros->Libros[posicion].ISBN,cadena);
                break;

        case 5: printf("\nIntroduce el nuevo formato: ");
                leerCadena(cadena);
                strcpy(variosLibros->Libros[posicion].formato,cadena);
                break;
        case 6: printf("Introduzca la nueva fecha:\n");

                printf("\nIntroduce el anho: ");
                anho=leerEntero(cadena);
                printf("\nIntroduce el mes: ");
                mes=leerEntero(cadena);
                printf("\nIntroduce el dia: ");
                dia=leerEntero(cadena);

                while(comprobarFecha(anho,mes,dia)==0){
                printf("\nError. Escribe una fecha correcta.\n");
                printf("\nIntroduce el anho: ");
                anho=leerEntero(cadena);
                printf("\nIntroduce el mes: ");
                mes=leerEntero(cadena);
                printf("\nIntroduce el dia: ");
                dia=leerEntero(cadena);
                }
                variosLibros->Libros[posicion].fecha.anho=anho;
                variosLibros->Libros[posicion].fecha.mes=mes;
                variosLibros->Libros[posicion].fecha.dia=dia;
                break;

        case 7: printf("Introduce el nuevo precio: ");
                variosLibros->Libros[posicion].precio=leerFlotante(cadena);
                break;
        case 8: break;
    }

 }
