#include <stdio.h>


int main()
{
   printf("HOLA  MUNDO\n");
   int x=666,*p;
   p=&x;
   printf("El contenido del puntero es %p \n",p);
   printf("El contenido del puntero es %p \n",p);
   printf("La direccion del meme del puntero es %p \n",&p);
   printf("Tamaño de memoria de la variable x %d \n",sizeof(x));

    return 0;
}
