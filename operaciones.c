#include <stdio.h>
#include <string.h>
#include "operaciones.h"
#include "lecturas.h"

void IngresarAlSistema(int clave){
    do {
        printf("Ingrese la clave de seguridad: ");
        scanf("%d", &clave);
        if (clave = 0){
            printf("Contraseña Incorrecta. Intente de nuevo por favor.\n");
        }
    } while (clave = 0);
}

void ingresarProducto(int numP, char nombreP[][NOMBRE], int *cant, float *valor, float *descuento) {
    FILE *file = fopen("productos.txt", "a+");
    if (file == NULL) {
        printf("Error al abrir el archivo para guardar los productos.\n");
        return;
    }
   
    for (int i = 0; i < numP; i++) {
        printf("Producto %d:\n", i + 1);
        printf("Nombre: ");
        getchar();  
        fgets(nombreP[i], NOMBRE, stdin);
        nombreP[i][strcspn(nombreP[i], "\n")]= '\0';
        printf("Cantidad: ");
        scanf("%d", &cant[i]);
        printf("Valor por unidad: ");
        scanf("%f", &valor[i]);
        printf("Descuento del día: ");
        scanf("%f", &descuento[i]);

        // Guardar producto en el archivo
        fprintf(file, "%s %d %.2f %.2f\n", nombreP[i],&cant[i], &valor[i], &descuento[i] );
    }

    fclose(file);
}

void leerProductosDeArchivo(int *numP, char nombreP[][NOMBRE], int cant[], float valor[], float descuento[]) {
    FILE *file = fopen("productos.txt", "r");
    if (file != NULL) {
        int i = 0;
        while (fscanf(file, "%s %d %f %f", nombreP[i], &cant[i], &valor[i], &descuento[i]) != EOF) {
            i++;
        }
        *numP = i;
        fclose(file);
    } else {
        printf("Error al abrir el archivo para leer los productos.\n");
    }
}

void BuscarProductos(char nombreP[][NOMBRE], int numP, char Busqueda[], int name) {
    printf("Ingrese el producto que desea buscar: ");
    getchar();
    fgets(Busqueda, name, stdin);
    Busqueda[strcspn(Busqueda, "\n")] = '\0';
    int find = 0;
    for (int i = 0; i < numP; i++) {
        if (strcmp(nombreP[i], Busqueda) == 0) {
            printf("Está en lista\n");
            find = 1;
            break;
        }
    }
    if (!find) {
        printf("No está en lista\n");
    }
}

void mostrarProducto(char nombreP[][NOMBRE], int cant[], float valor[], float descuento[], int numP) {
    printf("%-12s %6s %8s %10s %8s\n", "Producto", "Cantidad", "Valor", "Descuento", "Precio Total");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < numP; i++) {
        float valortotal = valor[i] * (1 - descuento[i] / 100);
        printf("%-12s %6d %8.2f %10.2f %8.2f\n", nombreP[i], cant[i], valor[i], descuento[i], valortotal);
    }
}