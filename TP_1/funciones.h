#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
int num1(x)
{
    printf("Ingrese el 1er operando: ");
    scanf("%d",&x);
    system("pause");
    system("cls");
    return x;
}
int num2 (y)
{
    printf("Ingrese el 2do operando: ");
    scanf("%d",&y);
    system("pause");
    system("cls");
    return y;
}
void suma (x,y)
{
    printf("El resultado de la suma es: %d\n",x+y);
    system("pause");
    system("cls");
}
void resta (x,y)
{
    printf("El resultado de la resta es: %d\n",x-y);
    system("pause");
    system("cls");
}
void division (x,y)
{
    if(y==0)
    {
        printf("No se puede dividir entre 0\n");
    }
    else
    {
        printf("El resultado de la division es: %d\n",x/y);
    }
    system("pause");
    system("cls");
}
void multiplicacion (x,y)
{
    printf("El resultado de la multiplicacion es: %d\n",x*y);
    system("pause");
    system("cls");
}
void factorial (x)
{
    int i,fac=x;
    for(i=1;i<x;i++)
    {
        fac=fac*i;
    }
    printf("El numero factorial de %d es: %d",x,fac);
    system("pause");
    system("cls");
}
void todas(x,y)
{
    int i;
    long fac=x;
    for(i=1;i<x;i++)
    {
        fac=fac*i;
    }
    printf("Los resultados de cada operacion son: ");
    printf("SUMA: %d\n",x+y);
    printf("RESTA: %d\n",x-y);
    if(y==0)
    {
        printf("DIVISION: Imposible dividir por 0\n");
    }
    else
    {
        printf("DIVISION: %d\n",x/y);
    }
    printf("MULTIPLICACION: %d\n",x*y);
    printf("FACTORIAL DE %d: %ld\n",x,fac);
    system("pause");
    system("cls");
}
#endif // FUNCIONES_H_INCLUDED
