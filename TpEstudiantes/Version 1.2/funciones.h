#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define DIM_CHAR 30
#define DIM_NOTAS 6
typedef struct
{
    int legajo; //identificacion
    char nombre[DIM_CHAR];
    char apellido[DIM_CHAR];
    int notas[DIM_NOTAS];
    int cantidadNotas; // validos
    int comision;
    int estado;
}stEstudiante;

stEstudiante crearUnEstdiante(char archivoEstudiante[]);
void cargarEstudianteAlArchivo(char archivo[]);
void mostrarEstudiante(stEstudiante aux);
void mostrarNotas(stEstudiante aux);
void mostrarTodosLosEstudiantes(char archivo[]);
void limpiarPantalla();
stEstudiante retornarEstudianteXlegajo(char archivo[], int legajo);
void modificarEstudiante(int opsw, char archivo[]);

void preguntarNyA(char dato[]);
int preguntarDatoEntero();
void buscarEstudiantePorNombre(char archivo[]);
void buscarEstudiantePorApellido(char archivo[]);
void buscarPorLegajo(char archivo[]);
#endif // FUNCIONES_H_INCLUDED
