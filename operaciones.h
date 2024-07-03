#define PRODUCTO 50
#define NOMBRE 50
#define COLUMNA 6
#define CONTRASEÑA 223

void IngresarAlSistema(int);
void ingresarProducto(int, char[][NOMBRE], int[], float[], float[]);
void leerProductosDeArchivo(int*, char[][NOMBRE], int[], float[], float[]);
void BuscarProductos(char[][NOMBRE], int, char[], int);
void mostrarProducto(char[][NOMBRE], int[], float[], float[], int);