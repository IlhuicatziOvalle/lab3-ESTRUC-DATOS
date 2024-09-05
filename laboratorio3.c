#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaDoble/ListaDoble.h"  // Asegúrate de que este archivo incluya las declaraciones necesarias

void ImprimirInt(void *dato){
    printf("%d", *(int *)dato);
}

void ImprimirChar(void *dato){
    printf("%c", *(char *)dato);
}

int main(){
   

    ListaDoble Lista_1;
    InicializarListaDoble(&Lista_1);

    PushBack(&Lista_1,"I");
    PushBack(&Lista_1,"N");
    PushBack(&Lista_1,"G");
    PushBack(&Lista_1,"E");
    PushBack(&Lista_1,"N");
    PushBack(&Lista_1,"I");
    PushBack(&Lista_1,"E");
    PushBack(&Lista_1,"R");
    PushBack(&Lista_1,"O");

    printf("Lista 1:\n");
    ImprimirLista(&Lista_1,ImprimirChar);

    ListaDoble Lista_2;
    InicializarListaDoble(&Lista_2);

    PushBack(&Lista_2,"S");
    PushBack(&Lista_2,"O");
    PushBack(&Lista_2,"F");
    PushBack(&Lista_2,"T");
    PushBack(&Lista_2,"W");
    PushBack(&Lista_2,"A");
    PushBack(&Lista_2,"R");
    PushBack(&Lista_2,"E");
   

    printf("\nLista 2:\n");
    ImprimirLista(&Lista_2,ImprimirChar);

    ListaDoble Lista_3;
    InicializarListaDoble(&Lista_3);

    ConcatInicio(&Lista_1, &Lista_2, &Lista_3);
    printf("\nLista 3:\n");
    ImprimirLista(&Lista_3, ImprimirChar);

    ListaDoble Lista_4;
    InicializarListaDoble(&Lista_4);

    ConcatFinal(&Lista_1, &Lista_2, &Lista_4);
    printf("\nLista 4:\n");
    ImprimirLista(&Lista_4, ImprimirChar);

    ListaDoble Lista_5;
    InicializarListaDoble(&Lista_5);

    ConcatPos(&Lista_1, &Lista_2, 3);
    printf("\nLista 5:\n");
    ImprimirLista(&Lista_1, ImprimirChar);

    LiberarLista(&Lista_1);
    LiberarLista(&Lista_2);
    LiberarLista(&Lista_3);
    LiberarLista(&Lista_4);
    LiberarLista(&Lista_5);
   

    return 0;
}
