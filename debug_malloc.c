#include "malloc.h"
#include <stdio.h>
#include <unistd.h>

int main() {
  // Ejemplo de uso de malloc y free
  int *arr1 = (int *)malloc(10 * sizeof(int));
  int *arr2 = (int *)malloc(20 * sizeof(int));
  free(arr1);
  int *arr3 = (int *)malloc(5 * sizeof(int));

  // Llamada a la función de depuración
  print_memory_blocks();

  // Liberar memoria
  free(arr2);
  free(arr3);

  // Llamada a la función de depuración después de liberar memoria
  print_memory_blocks();

  return 0;
}
