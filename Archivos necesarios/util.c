// Lee cadenas números por teclado

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

int leerEntero ( char cad [] )
{
    int entero;
    int i=0; int c;
    c=getchar();
    while(c!='\n'){
    cad[i]=c;
    c=getchar();
    i++;
}
    cad[i] = '\0';
    entero=atoi(cad);
    return entero;
}

float leerFlotante ( char cad [] )
{
    float flotante;
    int i=0; float c;
    c=getchar();
    while(c!='\n'){
    cad[i]=c;
    c=getchar();
    i++;
}
    cad[i] = '\0';
    flotante=atof(cad);
    return flotante;
}

void leerCadena ( char cad [] )
{
int i=0; int c;
c=getchar();
while(c!='\n'){
    cad[i]=c;
    c=getchar();
    i++;
}
cad[i] = '\0';
}
