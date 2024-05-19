// alloc.h
#define ALLOCSIZE 10000 // tamaño del espacio disponible

static char allocbuf[ALLOCSIZE]; // almacenamiento para alloc
static char *allocp = allocbuf;  // siguiente posición libre

char *alloc(int n) { // regresa un puntero a n caracteres
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else
    return 0;
}

void afree(char *p) { // libera la memoria apunta por p
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}