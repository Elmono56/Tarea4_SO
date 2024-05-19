#include <stdio.h>
#include "alloc.h"

int main() {
  int *arreglo;

  // Asignación de memoria desde el inicio (de arriba hacia abajo)
  arreglo = (int *)alloc(sizeof(int) * 10, 0);
  if (arreglo == NULL) {
    printf("Error: No se pudo asignar memoria.\n");
    return 1;
  }
  for (int i = 0; i < 10; i++)
    arreglo[i] = 10 * i;
  for (int i = 0; i < 10; i++)
    printf("%i\n", arreglo[i]);
  afree((char *)arreglo, 0);

  // Asignación de memoria desde el final (de abajo hacia arriba)
  arreglo = (int *)alloc(sizeof(int) * 10, 1);
  if (arreglo == NULL) {
    printf("Error: No se pudo asignar memoria.\n");
    return 1;
  }
  for (int i = 0; i < 10; i++)
    arreglo[i] = 20 * i;
  for (int i = 0; i < 10; i++)
    printf("%i\n", arreglo[i]);

  // Imprimir información de depuración
  print_memory_info();

  return 0;
}