#include "chess.h"
#include "figures.h"

void display() {

  char **_spwhite = whiteSquare;       // un casillero en blanco
  char **_spblack = reverse(_spwhite); // un casillero en negro

  // Unir casillero blanco y negro
  char **two_block = join(_spwhite, _spblack);

  // Agregar 2 filas de 2 columna en la variable fila
  char **fila = up(reverse(two_block), two_block);

  interpreter(fila);
}
