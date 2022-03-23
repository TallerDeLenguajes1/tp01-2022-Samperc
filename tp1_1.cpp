#include <stdio.h>
#include <stdlib.h>

typedef int item;

struct NODO
{
    item dato;
    struct NODO *siguiente;
};
typedef struct NODO *Lista;

// FUNCION CREAR LISTA

Lista crearlista()
{
    return (NULL);
}

// FUNCION INSERTAR LISTA
Lista insertarlista(Lista H, item x)
{
    Lista nuevo;
    nuevo = (struct NODO *)malloc(sizeof(struct NODO));
    nuevo->dato = x;
    nuevo->siguiente = H;
    H = nuevo;
    return H;
}

// BORRAR NODO LISTA

Lista Borrarnodo(Lista H)
{
    Lista aux;
    aux = H;
    H = aux->siguiente;
    free(aux);
    return H;
}

// ES LISTA VACIA
int eslistavacia(Lista H)
{
    if (H == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// PRIMER ELEMENTO

item primerelemento(Lista H)
{
    if (eslistavacia(H) == 0)
    {
        return (H->dato);
    }
    else
    {
        return NULL;
    }
}

// MOSTRAR LISTA
void Mostrarlista(Lista H, Lista L)
{
    int cont = 1;
    while (eslistavacia(H) == 0)
    {
        printf("Dato%d= %d \n",cont, H->dato);
        H = H->siguiente;
        cont++;
    }
}

// LONGITUD
int Longitud(Lista H)
{
    int cont = 0;
    while (eslistavacia(H) == 0)
    {
        cont++;
        H = H->siguiente;
    }
    return cont;
}

// FUNCION Pertenece
int pertenece(Lista H, item x)
{

    while (eslistavacia(H) == 0)
    {
        if (H->dato == x)
        {
            return 1;
        }

        H = H->siguiente;
    }
    return 0;
}

// FUNCION borrarK
Lista borrarK(Lista H, item K)
{
    Lista aux, NA;
    aux = H;
    while (eslistavacia(aux) == 0)
    {
        if (H->dato == K)
        {
            H = H->siguiente;
            free(aux);
            aux = H;
           
        }
        else
        {
            printf("SOY EL ELSE \n");
            NA = aux;
            aux = aux->siguiente;
            if (eslistavacia(aux) == 0)
            {
                if (aux->dato == K)
            {
                NA->siguiente = aux->siguiente;
                free(aux);
                aux = NA;
            }
            }
            
            
        }
    }
    return H;
}   

//FUNCION ESTA CONTENIDA 




int main()
{
    int bandera = 1, sel;
    int longi,i=0;
    item x, y, K;
    Lista H, L;
    Lista *H[2];
    while (bandera == 1)
    {
        printf("******************PRESIONE******************\n _1 para crearlista \n _2 para esListaVacia \n _3 para Mostrar \n _4 Para primerElemento \n _5 para insertar \n _6 para borrar 1er nodo \n _7 para longitud \n _8 para pertenece \n _9 para BorrarK \n _10 para salir\n");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            H = crearlista();
            break;
        case 2:
            if (eslistavacia(H) == 1)
            {
                printf("La lista esta vacia \n");
            }
            else
            {
                printf("La lista no esta vacia \n");
            }

            break; 
        case 3:
            L = H;
            Mostrarlista(H, L);
            break;
        case 4:
            x = primerelemento(H);
            printf("1er elemento %d \n", x);
            break;
        case 5:
            printf("Ingresa el dato que deseas insertar: \n");
            scanf("%d", &x);

            H = insertarlista(H, x);
            break;
        case 6:
            H = Borrarnodo(H);
            break;
        case 7:

            longi = Longitud(H);
            printf("longitud: %d  \n", longi);
            break;
        case 8:
            printf("Ingresar dato a buscar: \n");
            scanf("%d", &y);
            if (pertenece(H, y) == 1)
            {
                printf("El dato %d pertenece a la lista \n", y);
            }
            else
            {
                printf("El dato %d NO pertenece a la lista \n", y);
            }

            break;
        case 9:
          printf("Que dato desea borrar? \n ");
          scanf("%d",&K);
          H=borrarK(H,K);
            break;
        case 10:
            bandera = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
