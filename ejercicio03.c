#include "chess.h"
#include "figures.h"

void display() {

  char **_spwhite = whiteSquare;       // un casillero en blanco
  char **_spblack = reverse(_spwhite); // un casillero en negro

  // Unir casillero blanco y negro
  char **two_block = join(_spwhite, _spblack);

  // Agregar 2 filas de 2 columna en la variable fila
  char **two_rows_two_columns = up(reverse(two_block), two_block);

  // 4 filas y 2 columnas
  char **four_rows_two_columns = up(two_rows_two_columns, two_rows_two_columns);

  // 4 filas y 8 columnas
  char **four_rows_eight_columns = repeatH(four_rows_two_columns, 4);

  // mostrar
  interpreter(four_rows_eight_columns);
}
