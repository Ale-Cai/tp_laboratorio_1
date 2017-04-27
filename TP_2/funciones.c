#include "funciones.h"


int getInt(int input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int aux;

    printf("%s", message);
    scanf("%d", &aux);

    while(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMessage);
        scanf("%d", &aux);
    }
        input = aux;

    return input;

}


int getFloat(float input, char message[], char eMessage[], float lowLimit, float hiLimit)
{
    float aux;
    int retornar;

    printf("%s", message);
    scanf("%f", &aux);

    if(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMessage);
        retornar = -1;
    }
    else{
        input = aux;
        retornar = 0;
    }

    return retornar;

}





int getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    char aux[200];


    printf("%s", message);
    fflush(stdin);
    gets(aux);

    while(strlen(aux) < lowLimit || strlen(aux) > hiLimit)
    {
        printf("%s", eMessage);
        fflush(stdin);
        gets(aux);
    }
        strcpy(input,aux);

    return 0;

}



int getLongInt(long int input, char message[], char eMessage[], long int lowLimit, long int hiLimit)
{
    long int aux;


    printf("%s", message);
    scanf("%ld", &aux);

    while(aux < lowLimit || aux > hiLimit)
    {
        printf("%s", eMessage);
        scanf("%ld", &aux);
    }

        input = aux;


    return input;

}


char getSN(char message[], char eMessage[])
{
    char aux;
    printf("%s", message);
    aux = tolower(getche());
    while(aux != 's' && aux != 'n')
    {
        printf("%s", eMessage);
        aux  = tolower(getche());
    }
    return aux;

}

int mayusNombre(char name[])
{
    int i;

    strlwr(name);

    name[0] = toupper(name[0]);

    for(i=0; i<=(strlen(name)); i++)
    {
        if(name[i] == ' ')
            name[i+1] = toupper(name[i+1]);


    }

    return 0;

}


void inicializarEstados(EPersona lista[], int size)
{
    int i;

    for(i=0; i<size; i++){

        lista[i].estado = 0;
    }

}

int obtenerEspacioLibre(EPersona lista[], int size)
{
    int i;

    for(i=0; i<size; i++){

        if(lista[i].estado == 0)
        {
            return i;
        }
    }

    printf("\n\nERROR. No hay mas espacios disponibles");
    return -1;

}


int buscarDuplicado(EPersona lista[], long int dni, int size)
{
    int index;


        while((index = buscarPorDni(lista, dni, size)) != -1 )
            dni = getLongInt(dni, "ERROR. El DNI ya fue ingresado\nReingrese: ", "ERROR. El DNI debe estar comprendido entre 1000000 y 99999999.\nReingrese: ", 1000000, 99999999);

    return 1;

}


int agregarPersona(EPersona lista[], int size)
{
    int index, auxEdad = 0;
    long int auxDni = 0;
    char auxNombre[200];


    if((index = obtenerEspacioLibre(lista, size)) != -1)
    {
        auxDni = getLongInt(auxDni, "Ingrese DNI: ", "\n\nERROR.El DNI debe estar comprendido entre 1000000 y 99999999.\nReingrese: ", 1000000, 99999999);
        buscarDuplicado(lista, auxDni, size);
        getString(auxNombre, "\nIngrese nombre: ", "\n\nERROR. El nombre debe tener entre 2 y 50 caracteres\nReingrese: ", 2, 50);
        mayusNombre(auxNombre);
        auxEdad = getInt(auxEdad, "\nIngrese edad: ", "\n\nERROR. La edad debe estar entre 0 y 115.\nReingrese edad: ", 0, 115);


        lista[index].dni = auxDni;
        strcpy(lista[index].nombre, auxNombre);
        lista[index].edad = auxEdad;
        lista[index].estado = 1;

        printf("\n\nPersona agregada con exito.\n");
    }


    return 0;
}

int buscarPorDni(EPersona lista[], long int dni, int size)
{
    int i;


        for(i=0; i<size; i++){

            if(lista[i].dni == dni && lista[i].estado != 0)
                return i;
        }
    return -1;
}


int borrarPersona(EPersona lista[], long int dni, int size)
{
    int index;
    char resp;

        if((index = buscarPorDni(lista, dni, size)) == -1)
        {
            printf("ERROR. No se encontro el DNI ingresqado");
            return -1;
        }

        printf("Nombre: %s", lista[index].nombre);
        printf("\nDNI: %ld", lista[index].dni);
        printf("\nEdad: %d", lista[index].edad);
        resp = getSN("\n\nDesea eliminar los datos? (S/N) ", "\n\nERROR. Seleccione S o N");

        if(resp == 's'){

            lista[index].estado = 0;
            printf("\nLos datos han sido eliminados correctamente.\n");
            return 0;
        }

        else
            printf("\nLos datos NO han sido eliminados\n");

        return -1;

}


void mostrarPersonas(EPersona lista[], int size)
{
    int i;

    for(i=0; i<size; i++){

        if(lista[i].estado != 0){
            printf("\n\nNombre: %s", lista[i].nombre);
            printf("\nDNI: %ld", lista[i].dni);
            printf("\nEdad: %d", lista[i].edad);
        }

    }

}

void ordenarPersonas(EPersona lista[], int size)
{
    int i, j;
    EPersona aux;

    for(i=0; i<size-1; i++){
        for(j=i+1; j<size; j++){

            if(strcmp(lista[i].nombre, lista[j].nombre) > 0){

                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    mostrarPersonas(lista, size);
}

void graficoPersonas(EPersona lista[], int size)
{
    int i, menores18 = 0, entre = 0, mayores35 = 0, contMax, flag = 0;

    for(i=0; i<size; i++){

        if(lista[i].estado == 1){

            if(lista[i].edad < 18)
                menores18++;
            else if(lista[i].edad > 35)
                mayores35++;
            else
                entre++;


        }
    }

    if(menores18 >= entre && menores18 >= mayores35)
        contMax = menores18;
    else if(entre >= menores18 && entre >= mayores35)
        contMax = entre;
    else
        contMax = mayores35;

    for(i=contMax; i>0; i--){

        if(i <= menores18)
                printf("  *");

        if(i <= entre){
            printf("  \t*");
            flag = 1;
        }

        if(i <= mayores35){
            if(flag == 0)
                printf("\t\t  *");
            else
                printf("\t *");
        }


            printf("\n");

    }

        printf("<18   18/35\t>35");
}


