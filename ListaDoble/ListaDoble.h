
typedef struct _NodoDoble{
    void *dato;
    struct _NodoDoble *next;
    struct _NodoDoble *prev;
}NodoDoble;

typedef struct _ListaDoble{
    NodoDoble *Head;
    NodoDoble *Tail;
    NodoDoble *Curr;
    int size;
} ListaDoble;



void InicializarListaDoble(ListaDoble *lista);
void PushFront(ListaDoble *lista, void *item);
void PushBack(ListaDoble *lista, void *item);
NodoDoble *GetNodoPos(ListaDoble *lista, int pos);
void PushPos(ListaDoble *lista, void *item, int pos);
int BorrarPos(ListaDoble *lista, int pos);
void ImprimirLista(const ListaDoble *const, void (*func)(void *));
void LiberarLista(ListaDoble *lista);

void ConcatInicio(ListaDoble *lista1, ListaDoble *lista2, ListaDoble *lista3);
void ConcatFinal(ListaDoble *lista1, ListaDoble *lista2, ListaDoble *lista4);
void ConcatPos(ListaDoble *lista1, ListaDoble *lista2,int pos);