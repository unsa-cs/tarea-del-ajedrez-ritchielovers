#include "chess.h"
#include "figures.h"

void display() {

  char **_spwhite = whiteSquare;       // un casillero en blanco
  char **_spblack = reverse(_spwhite); // un casillero en negro

  // Unir casillero blanco y negro
  char **two_block = join(_spwhite, _spblack);

  // Repetir 4 veces la variable two_block
  char **fila = repeatH(two_block, 4);

  // Revertir la variable fila
  char **reverse_fila = reverse(fila);

  // Agregar una fila, en total 2
  char **two_row = up(reverse_fila, fila);

  // Repetir la variable two_row dos veces, 4 filas
  char **four_row = repeatV(two_row, 2);

  interpreter(four_row);
}
