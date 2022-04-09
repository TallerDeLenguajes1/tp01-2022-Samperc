#include <stdio.h>
#include <math.h>


int cuadrado(int a,int b){
    return pow(a,b);
}
void cuadrade(int *a, int *b,int *R){
*R=pow(*a,*b);
}

void mostrar(int *a){
    printf("direccion: %p\n",a);
    printf("valor: %d \n",*a);

}

void Invertir(int *a,int *b){
    int aux;
    aux=*b;
    *b=*a;
    *a=aux;
}

void orden(int *a,int *b){
    int aux;
    if(*a>*b){
         aux=*b;
         *b=*a;
         *a=aux;
    }
} 
int main()
{
  int a,b;
  int *pa,*pb;
pa=&a;
pb=&b;
printf("Ingrese el numero a: \n");
scanf("%d",&a);
printf("Ingrese el numero b: \n");
scanf("%d",&b);
int R;
int *pR=&R;
R=cuadrado(a,b);
printf("R: %d\n",R);
cuadrade(&a,&b,&R);
mostrar(&a);
printf("R: %d\n",R);

Invertir(&a,&b);
printf("a= %d \n",*pa);
printf("b= %d \n",*pb);

orden(&a,&b);
printf("a= %d \n",*pa);
printf("b= %d \n",*pb);
    return 0;
}
