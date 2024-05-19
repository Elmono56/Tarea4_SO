// alloc.h
#include <stdio.h>
#include <unistd.h>

#define ALLOCSIZE 10000 // tamaño del espacio disponible

static char allocbuf[ALLOCSIZE]; // almacenamiento para alloc
static char *allocp_top = allocbuf;  // siguiente posición libre desde el inicio
static char *allocp_bottom = allocbuf + ALLOCSIZE; // siguiente posición libre desde el final

char *alloc(int n, int i) {
  if (i == 0) { // asignación desde el inicio (de arriba hacia abajo)
    if (allocp_top + n <= allocp_bottom) { //hay espacio en pila
      allocp_top += n;
      return allocp_top - n;
    } else{
        printf("No hay suficiente espacio\n\n");
        return 0; // no hay suficiente espacio
    }
  }
  else if (i == 1) { // asignación desde el final (de abajo hacia arriba)
    if (allocp_bottom - n >= allocp_top) { //hay espacio en pila
      allocp_bottom -= n;
      return allocp_bottom;
    } else{
        printf("No hay suficiente espacio\n\n");
        return 0; // no hay suficiente espacio
    }
  }
  else { // valor de i inválido
    return 0; 
  }
}

void afree(char *p, int i) { // libera la memoria apuntada por p
  if (i == 0) { // liberación desde arriba
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
      allocp_top = p;
    }
  }
  else if (i == 1) { // liberación desde abajo
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
      allocp_bottom = p + ALLOCSIZE - (allocbuf + ALLOCSIZE);
    }
  }
}

// Función de depuración para imprimir la información de los bloques de memoria
void print_memory_info() {
  printf("Información de los bloques de memoria:\n");
  printf("Puntero de arriba: %p\n", allocp_top);
  printf("Puntero de abajo: %p\n", allocp_bottom);
  printf("Espacio libre en la pila entre ambos: %ld bytes\n\n\n", allocp_bottom - allocp_top);
}
