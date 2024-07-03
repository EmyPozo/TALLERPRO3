#include <stdio.h>
#include "lecturas.h"
#include "operaciones.h"

int main(int argc, char *argv[]) {
    int clave, numP=0;
    IngresarAlSistema(clave);
    printf("Sistema de Ingreso de Productos de EcoMart\n");
     
    printf("Numeros de productos a ingresar.\n");
    scanf("%d", &numP);
    char nombreP[PRODUCTO][NOMBRE];
    int cant[PRODUCTO];
    float valor[PRODUCTO], descuento[PRODUCTO];
    

    // Leer productos del archivo
    
    leerProductosDeArchivo(&numP, nombreP, cant, valor, descuento);

    int nuevosProductos = leerEnteroPositivo("Productos a Ingresar: ");
    ingresarProducto(nuevosProductos, nombreP + numP, cant + numP, valor + numP, descuento + numP);
    numP += nuevosProductos;

    printf("-----Productos Ingresados----\n");
    mostrarProducto(nombreP, cant, valor, descuento, numP);

    char Busqueda[NOMBRE];
    int encontrar, exit;
    encontrar = leerEntero("¿Desea revisar si está en lista? (Si = 1, No = 0): ");
    if (encontrar == 1) {
        do {
            BuscarProductos(nombreP, numP, Busqueda, NOMBRE);
            exit = leerEntero("¿Desea continuar? (Si = 1, No = 0): ");
        } while (exit != 0);
    }

    return 0;
}