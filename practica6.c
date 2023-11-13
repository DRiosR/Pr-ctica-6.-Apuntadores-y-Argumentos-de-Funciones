/*
Nombre del archivo: practica6.c
Autor: Daniel Rios Rodriguez
Fecha de creación: 12 de Noviembre de 2023
Descripción: este programa hace operaciones con apuntadores en funciones.
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
            printf("\n[==========================]\n");
            break;
        }
    } while (menu == 1);
}

/*
Función: suma_de_arreglo
Descripción: Esta función calcula la suma de los elementos en un arreglo.
Parámetros:
- arreglo: Apuntador al arreglo de enteros.
- largo: Número de elementos en el arreglo.
Valor de retorno: La suma de los elementos en el arreglo.
*/
int suma_de_arreglo(int *arreglo, int largo) {
    int acu = 0;
    int *ptr = arreglo;

    for (int i = 0; i < largo; i++) {
        acu += *ptr;
        ptr++;
    }

    return acu;
}

/*
Función: copiar_arreglo
Descripción: Esta función copia un arreglo de origen en un arreglo de destino.
Parámetros:
- arreglo_destino: Apuntador al arreglo de destino.
- arreglo_origen: Apuntador al arreglo de origen.
- largo: Número de elementos en el arreglo.
*/
void copiar_arreglo(int *arreglo_destino, int *arreglo_origen, int largo) {
    int *ptr_destino = arreglo_destino;
    int *ptr_origen = arreglo_origen;

    for (int i = 0; i < largo; i++) {
        *ptr_destino = *ptr_origen;
        ptr_destino++;
        ptr_origen++;
    }
}

/*
Función: concatenar_arreglo
Descripción: Esta función concatena dos arreglos en un tercer arreglo.
Parámetros:
- arreglo_destino: Apuntador al arreglo de destino.
- arreglo1: Apuntador al primer arreglo de entrada.
- largo1: Número de elementos en el primer arreglo.
- arreglo2: Apuntador al segundo arreglo de entrada.
- largo2: Número de elementos en el segundo arreglo.
*/
void concatenar_arreglo(int *arreglo_destino, int *arreglo1, int largo1, int *arreglo2, int largo2) {
    int *ptr_destino = arreglo_destino;
    int *ptr1 = arreglo1;
    int *ptr2 = arreglo2;

    for (int i = 0; i < largo1; i++) {
        *ptr_destino = *ptr1;
        ptr_destino++;
        ptr1++;
    }

    for (int i = 0; i < largo2; i++) {
        *ptr_destino = *ptr2;
        ptr_destino++;
        ptr2++;
    }
}

/*
Función: comparar_arreglo
Descripción: Esta función compara dos arreglos y determina si son iguales.
Parámetros:
- arreglo1: Apuntador al primer arreglo.
- largo1: Número de elementos en el primer arreglo.
- arreglo2: Apuntador al segundo arreglo.
- largo2: Número de elementos en el segundo arreglo.
*/
void comparar_arreglo(int *arreglo1, int largo1, int *arreglo2, int largo2) {
    int *ptr1 = arreglo1;
    int *ptr2 = arreglo2;
    int igual = 1; // Suponemos que son iguales hasta que encontremos una diferencia

    if (largo1 != largo2) {
        printf("NO SON IGUALES\n");
        return;
    }

    for (int i = 0; i < largo1; i++) {
        if (*ptr1 != *ptr2) {
            igual = 0;
            break;
        }
        ptr1++;
        ptr2++;
    }

    if (igual) {
        printf("SON IGUALES\n");
    } else {
        printf("NO SON IGUALES\n");
    }
}

/*
Función: elemento_maximo
Descripción: Esta función encuentra y devuelve el elemento máximo en el arreglo.
Parámetros:
- arreglo: Apuntador al arreglo de enteros.
- largo: Número de elementos en el arreglo.
*/
void elemento_maximo(int *arreglo, int largo) {
    int *ptr = arreglo;
    int maximo = *ptr; // Inicializamos con el primer elemento del arreglo

    for (int i = 1; i < largo; i++) {
        if (*(ptr + i) > maximo) {
            maximo = *(ptr + i);
        }
    }

    printf("El elemento máximo en el arreglo es: %d\n", maximo);
}
