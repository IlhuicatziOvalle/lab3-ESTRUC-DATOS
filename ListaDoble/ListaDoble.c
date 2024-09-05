#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "ListaDoble.h"


void InicializarListaDoble(ListaDoble *lista) {
    lista->Head = NULL;
    lista->Tail = NULL;
    lista->Curr = NULL;
    lista->size = 0;
}

void PushFront(ListaDoble *lista, void *item) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    nuevo->dato = item;
    nuevo->next = lista->Head;
    nuevo->prev = NULL;

    if (lista->Head != NULL) {
        lista->Head->prev = nuevo;
    }
    lista->Head = nuevo;

    if (lista->Tail == NULL) {
        lista->Tail = nuevo;
    }
    lista->size++;
}

void PushBack(ListaDoble *lista, void *item) {
    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    nuevo->dato = item;
    nuevo->next = NULL;
    nuevo->prev = lista->Tail;

    if (lista->Tail != NULL) {
        lista->Tail->next = nuevo;
    }
    lista->Tail = nuevo;

    if (lista->Head == NULL) {
        lista->Head = nuevo;
    }
    lista->size++;
}

NodoDoble *GetNodoPos(ListaDoble *lista, int pos) {
    NodoDoble *temp = lista->Head;
    for (int i = 0; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    return temp;
}

void PushPos(ListaDoble *lista, void *item, int pos) {
    if (pos == 0) { 
        PushFront(lista, item); //si la posicion es 0, se inserta al frente
        return;
    }
    if (pos == lista->size) {
        PushBack(lista, item); //si la posicion es igual al tamaño de la lista, inserta al final
        return;
    }

//En otro caso, inserta en la posición intermedia ajustando los punteros de los nodos circundantes.

    NodoDoble *nuevo = (NodoDoble *)malloc(sizeof(NodoDoble));
    nuevo->dato = item;

    NodoDoble *curr = GetNodoPos(lista, pos);
    if (curr != NULL) {
        nuevo->next = curr;
        nuevo->prev = curr->prev;
        if (curr->prev != NULL) {
            curr->prev->next = nuevo;
        }
        curr->prev = nuevo;
        if (pos == 0) {
            lista->Head = nuevo;
        }
    }
    lista->size++;
}

int BorrarPos(ListaDoble *lista, int pos) {
    if (pos < 0 || pos >= lista->size) return -1;

    NodoDoble *temp = lista->Head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        lista->Head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        lista->Tail = temp->prev;
    }

    free(temp->dato);
    free(temp);
    lista->size--;
    return 0;
}

void ImprimirLista(const ListaDoble *const lista, void (*func)(void *)) {
    NodoDoble *temp = lista->Head;
    while (temp != NULL) {
        printf("[%p] (%p) -> ",(void*)temp->prev,(void*)temp);
        func(temp->dato);
        printf(" -> [%p] \n",(void*)temp->next);
        temp = temp->next;
    }
}

void LiberarLista(ListaDoble *lista) {
    NodoDoble *temp;
    while (lista->Head != NULL) {
        temp = lista->Head;
        lista->Head = lista->Head->next;
        free(temp->dato);  // Asegúrate de que data sea liberado si se aloca dinámicamente
        free(temp);
    }
    lista->Tail = NULL;
    lista->size = 0;
}

void ConcatInicio(ListaDoble *lista1, ListaDoble *lista2, ListaDoble *lista3) {
    // Inicializar la lista 3
    InicializarListaDoble(lista3);

    // Recorrer la primera lista y copiar sus elementos a la lista 3
    NodoDoble *temp = lista1->Head;
    while (temp != NULL) {
        char *nuevoDato = (char *)malloc(sizeof(char));
        *nuevoDato = *(char *)temp->dato;  // Copia el dato (carácter)
        PushBack(lista3, nuevoDato);  // Insertar en la lista 3
        temp = temp->next;
    }

    // Recorrer la segunda lista y copiar sus elementos a la lista 3
    temp = lista2->Head;
    while (temp != NULL) {
        char *nuevoDato = (char *)malloc(sizeof(char));
        *nuevoDato = *(char *)temp->dato;  // Copia el dato (carácter)
        PushBack(lista3, nuevoDato);  // Insertar en la lista 3
        temp = temp->next;
    }
}
void ConcatFinal(ListaDoble *lista1, ListaDoble *lista2, ListaDoble *lista4){
 // Inicializar la lista 4
    InicializarListaDoble(lista4);
    
    // Recorrer la primera lista y copiar sus elementos a la lista 3
    NodoDoble *temp = lista2->Head; //modificamos la lista1 por lista2
    while (temp != NULL) {
        char *nuevoDato = (char *)malloc(sizeof(char));
        *nuevoDato = *(char *)temp->dato;  // Copia el dato (carácter)
        PushBack(lista4, nuevoDato);  // Insertar en la lista 3
        temp = temp->next;
    }

    // Recorrer la segunda lista y copiar sus elementos a la lista 3
    temp = lista1->Head; //modificamos la lista2 por lista1
    while (temp != NULL) {
        char *nuevoDato = (char *)malloc(sizeof(char));
        *nuevoDato = *(char *)temp->dato;  // Copia el dato (carácter)
        PushBack(lista4, nuevoDato);  // Insertar en la lista 3
        temp = temp->next;
    }
}
void ConcatPos(ListaDoble *lista1, ListaDoble *lista2,int pos){
    
    NodoDoble *temp = lista1->Head;
   
    // Recorrer la segunda lista y copiar sus elementos a la lista 3
    temp = lista2->Head;
    while (temp!= NULL) {
        char *nuevoDato = (char *)malloc(sizeof(char));
        *nuevoDato = *(char *)temp->dato;  // Copia el dato (carácter)
        PushPos(lista1, nuevoDato, pos);  // Insertar en la lista 1
        temp = temp->next;
        pos++;
    }
    
    
    
}
