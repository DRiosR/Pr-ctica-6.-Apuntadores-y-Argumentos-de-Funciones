/*
1. Suma de elementos en un arreglo: Crea una función que calcule la suma de los
elementos en un arreglo utilizando apuntadores y aritmética de direcciones. La función
debe tomar un apuntador al arreglo y devolver la suma.
2. Copia de arreglos: Crea una función que copie un arreglo de origen en un arreglo de
destino. Utiliza apuntadores para realizar esta operación. La función debe tomar dos
apuntadores como argumentos, uno para el arreglo de origen y otro para el arreglo de
destino.
3. Concatenación de arreglos: Crea una función que tome dos arreglos de entrada y
los concatene en un tercer arreglo. Utiliza apuntadores y aritmética de direcciones para
realizar la concatenación. La función debe tomar tres apuntadores como argumentos:
dos para los arreglos de entrada y uno para el arreglo de destino.
4. Comparación de arreglos: Crea una función que compare dos arreglos y determine
si son iguales. Utiliza apuntadores y aritmética de direcciones para realizar la
comparación. La función debe tomar dos apuntadores como argumentos y devolver
un valor que indique si los arreglos son iguales.
5. Encontrar el elemento máximo: Crea una función que encuentre y devuelva el
elemento máximo en el arreglo.
*/
#include <stdio.h>
#include "RRD.h"
int suma_de_areglo(int *arreglo, int largo);
void copiar_arreglo(int *arreglo_destino, int *arreglo_origen, int largo);
void concatenar_arreglo(int *arreglo_destino, int *arreglo1, int largo1, int *arreglo2, int largo2);
void comparar_arreglo(int *arreglo1, int largo, int *areglo2, int largo2);
void elemento_maximo(int *arreglo, int largo);

int main()
{
    int numeros[] = {10, 8, 9, 4, 5};
    int numeros2[] = {6, 7, 8, 9, 10};
    int largo = sizeof(numeros) / sizeof(numeros[0]);
    int largo2 = sizeof(numeros2) / sizeof(numeros2[0]);
    int largo_total = largo + largo2;
    int numeros3[largo_total];
    int numeros_copia[largo];
    int act, menu;
    int i, suma;
    do
    {
        menu = 1;
        act = validarnumeros("0. SALIR DEL PROGRAMA\n1. Suma de elementos en un arreglo\n2. Copia de arreglos\n3. Concatenación de arreglos\n4. Comparación de arreglos\n5. Encontrar el elemento máximo\n", 0, 5);
        switch (act)
        {
        case 0:
            menu = 0;
            printf("FIN DEL PROGRAMA");
            break;
        case 1:
            printf("[========ACTIVIDAD1========]\n\n");
            suma = suma_de_areglo(numeros, largo);
            printf("suma del arreglo =%d\n", suma);
            printf("\n[==========================]\n\n");

            break;
        case 2:
            printf("[========ACTIVIDAD2========]\n\n");
            copiar_arreglo(numeros_copia, numeros, largo);
            printf("     origen------destino\n");
            for (i = 0; i < largo; i++)
            {
                printf("%9d %10d\n", numeros[i], numeros_copia[i]);
            }
            printf("\n[==========================]\n");

            break;
        case 3:
            printf("[========ACTIVIDAD3========]\n\n");
            concatenar_arreglo(numeros3, numeros, largo, numeros2, largo2);
            printf("Concatenacion de arreglos: ");
            for (int i = 0; i < largo_total; i++)
            {
                printf("%d ", numeros3[i]);
            }
            printf("\n\n[==========================]\n");

            break;
        case 4:
            printf("[========ACTIVIDAD4========]\n\n");
            comparar_arreglo(numeros, largo, numeros2, largo2);

            printf("\n\n[==========================]\n");
            break;
        case 5:
            printf("[========ACTIVIDAD5========]\n\n");
            elemento_maximo(numeros, largo);
            printf("\n\n[==========================]\n");
            break;
        }
    } while (menu == 1);
}

int suma_de_areglo(int *arreglo, int largo)
{
    int acu = 0;
    int *ptr = arreglo;

    for (int i = 0; i < largo; i++)
    {
        acu += *ptr;
        ptr++;
    }

    return acu;
}
void copiar_arreglo(int *arreglo_destino, int *arreglo_origen, int largo)
{
    int acu = 0;
    int *ptr = arreglo_destino;
    int *ptr2 = arreglo_origen;
    for (int i = 0; i < largo; i++)
    {
        *ptr = *ptr2;
        ptr++;
        ptr2++;
    }
}
void concatenar_arreglo(int *arreglo_destino, int *arreglo1, int largo1, int *arreglo2, int largo2)
{
    int *ptr = arreglo_destino;
    int *ptr2 = arreglo1;
    int *ptr3 = arreglo2;
    int i;
    for (i = 0; i < largo1; i++)
    {
        *ptr = *ptr2;
        ptr++;
        ptr2++;
    }

    for (i = 0; i < largo2; i++)
    {
        *ptr = *ptr3;
        ptr++;
        ptr3++;
    }
}
void comparar_arreglo(int *arreglo1, int largo, int *areglo2, int largo2)
{
    int *ptr = arreglo1;
    int *ptr2 = areglo2;
    int i, igual = 0;
    if (largo != largo2)
    {
        printf("NO SON IGUALES");
        return;
    }
    for (i = 0; i < largo; i++)
    {
        if (*ptr != *ptr2)
        {
            printf("NO SON IGUALES");
            return;
        }
        else
        {
            igual = 0;
        }
        ptr++;
        ptr2++;
    }
    printf("SON IGUALES");
    return;
}
void elemento_maximo(int *arreglo, int largo)
{
    int i;
    int *ptr = arreglo;
    int maximo = 0;

    for (i = 0; i < largo; i++)
    {
        if (*ptr > maximo)
        {
            maximo = *ptr;
        }
        ptr++;
    }

    printf("El elemento máximo en el arreglo es: %d\n", maximo);
}